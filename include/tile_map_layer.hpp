#ifndef JRPG_GAME_ENGINE_TILE_MAP_LAYER_HPP
#define JRPG_GAME_ENGINE_TILE_MAP_LAYER_HPP

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <vector>
#include <string>
#include <cmath>

#include "tile.hpp"
#include "tile_map_parser.hpp"
#include "asset_manager.hpp"

#include "utility/non_copyable.hpp"
#include "utility/non_moveable.hpp"

namespace jrpg {
    using layer_type = std::vector<tile>;
    using layer_size_type = layer_type::size_type;

    class tile_map_layer final : public sf::Drawable {
      public:
        explicit tile_map_layer(const std::string& filename, const sf::Vector2u &tileSize, std::size_t width, std::size_t height);
        ~tile_map_layer() override = default;

        void add(tile &&tile, std::size_t x, std::size_t y, std::size_t tw, std::size_t th);
        bool remove(const sf::Vector2f &tilePos);
        void clear();

        layer_size_type size() const;

        const std::string &name() const;
        std::size_t width() const;
        std::size_t height() const;

      protected:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

      private:
        layer_type _layer;

        std::string _name;
        std::size_t _width;
        std::size_t _height;
    };
} // namespace jrpg

#endif // JRPG_GAME_ENGINE_TILE_MAP_LAYER_HPP
