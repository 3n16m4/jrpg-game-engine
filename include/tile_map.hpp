#ifndef JRPG_GAME_ENGINE_TILE_MAP_HPP
#define JRPG_GAME_ENGINE_TILE_MAP_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <cmath>
#include <string>
#include <map>

#include "tile_map_layer.hpp"
#include "asset_manager.hpp"

#include "utility/non_copyable.hpp"
#include "utility/non_moveable.hpp"

namespace jrpg {
    using map_type = std::map<std::uint8_t, tile_map_layer>;

    class tile_map final : public sf::Drawable, public non_copyable, public non_moveable {
      public:
        explicit tile_map(std::string name);
        ~tile_map() override;

        bool load_tileset(const std::string &filename);

        void add_layer(std::uint8_t layerId, tile_map_layer&& layer);
        void remove_layer(std::uint8_t layerId);

        const std::string &name() const;
        void set_name(const std::string &name);

      protected:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

      private:
        std::string _name;
        map_type _map;
    };
} // namespace jrpg

#endif // JRPG_GAME_ENGINE_TILE_MAP_HPP
