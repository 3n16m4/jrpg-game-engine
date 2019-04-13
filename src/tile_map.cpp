#include "../include/tile_map.hpp"

namespace jrpg {
    tile_map::tile_map(std::string name, TileAmount amount, std::size_t width, std::size_t height)
        : _name(std::move(name)), _width(width), _height(height) {
        _tiles.reserve(amount);
    }

    tile_map::~tile_map() {
        _tiles.clear();
    }

    bool tile_map::load(const std::string &filename, const TileMap &tiles, const sf::Vector2u &tileSize,
                        std::size_t width, std::size_t height) {
        auto &asset_manager = asset_manager::instance();
        if (!asset_manager.load_texture("tile_set", filename)) {
            return false;
        }

        const auto &tileset = asset_manager.get_texture("tile_set");

        // populate the vertex array, with one quad per tile
        for (std::size_t x = 0; x < width; ++x) {
            for (std::size_t y = 0; y < height; ++y) {
                jrpg::tile tile(tileset, tileSize);

                // get the current tile number
                const auto tile_number = tiles[x + y * width];
                tile.set_tile_id(tile_number);

                // find its position in the tileset texture
                const auto tw = tile_number % (tileset->getSize().x / tile.get_tile_size().x);
                const auto th = tile_number / (tileset->getSize().x / tile.get_tile_size().x);

                // add the tile to the map
                add(std::move(tile), x, y, tw, th);
            }
        }

        asset_manager.free_textures();

        return true;
    }

    void tile_map::add(tile &&tile, std::size_t x, std::size_t y, std::size_t tw, std::size_t th) {
        tile.set_tile_position(sf::Vector2f(x * tile.get_tile_size().x, y * tile.get_tile_size().y));
        tile.set_tile_tex_coords(tw, th);
        _tiles.emplace_back(tile);
    }

    bool tile_map::remove(const sf::Vector2f &tilePos) {
        const auto &it = std::remove_if(_tiles.begin(), _tiles.end(), ([&tilePos](const tile &value) {
                                            return std::round(value.getPosition().x) == std::round(tilePos.x) &&
                                                   std::round(value.getPosition().y) == std::round(tilePos.y);
                                        }));

        if (it != _tiles.end()) {
            _tiles.erase(it, _tiles.end());
            return true;
        }
        return false;
    }

    void tile_map::clear() {
        _tiles.clear();
    }

    const std::string &tile_map::get_name() const {
        return _name;
    }

    void tile_map::set_name(const std::string &name) {
        _name = name;
    }

    std::size_t tile_map::get_width() const {
        return _width;
    }

    void tile_map::set_width(std::size_t width) {
        _width = width;
    }

    std::size_t tile_map::get_height() const {
        return _height;
    }

    void tile_map::set_height(std::size_t height) {
        _height = height;
    }

    const std::vector<tile> &tile_map::get_tiles() const {
        return _tiles;
    }

    void tile_map::draw(sf::RenderTarget &target, sf::RenderStates states) const {
        for (auto &tile : _tiles) {
            target.draw(tile, states);
        }
    }
}