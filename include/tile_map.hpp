#ifndef JRPG_GAME_ENGINE_TILE_MAP_HPP
#define JRPG_GAME_ENGINE_TILE_MAP_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <cmath>
#include <string>
#include <vector>

#include "asset_manager.hpp"
#include "tile.hpp"

#include "utility/non_copyable.hpp"
#include "utility/non_moveable.hpp"

namespace jrpg {
    using TileAmount = std::vector<tile>::size_type;
    using TileMap = std::vector<std::int32_t>;

    class tile_map final : public sf::Drawable, public non_copyable, public non_moveable {
      public:
        explicit tile_map(std::string name, TileAmount amount, std::size_t width, std::size_t height);
        ~tile_map() override;

        bool load(const std::string &filename, const TileMap &tiles, const sf::Vector2u &tileSize, std::size_t width,
                  std::size_t height);

        void add(tile &&tile, std::size_t x, std::size_t y, std::size_t tw, std::size_t th);
        bool remove(const sf::Vector2f &tilePos);
        void clear();

        const std::string &get_name() const;
        void set_name(const std::string &name);

        std::size_t get_width() const;
        void set_width(std::size_t width);

        std::size_t get_height() const;
        void set_height(std::size_t height);

        const std::vector<tile> &get_tiles() const;

      protected:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

      private:
        std::string _name;
        std::size_t _width;
        std::size_t _height;

        std::vector<tile> _tiles;
    };
} // namespace jrpg

#endif // JRPG_GAME_ENGINE_TILE_MAP_HPP
