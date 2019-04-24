#include "../include/tile_map_layer.hpp"
#include <iostream>

namespace jrpg {
    constexpr static auto RESERVED_TILEID = -1;

    tile_map_layer::tile_map_layer(const std::string &filename, const sf::Vector2u &tileSize, std::size_t width,
                                   std::size_t height)
        : _width(width), _height(height) {
        tile_map_parser parser{};
        layer_level_type level{};

        // TODO: handle exception accordingly
        try {
            level = parser.parse(filename);
        } catch (const jrpg::parse_map_exception &e) {
            std::cerr << e.what() << '\n';
        }

        _name = parser.name();
        _size = level.size();

        auto &asset_manager = asset_manager::instance();
        const auto &tileset = asset_manager.get_texture("tileset");

        // populate the vertex array, with one quad per tile
        for (std::size_t x = 0; x < width; ++x) {
            for (std::size_t y = 0; y < height; ++y) {
                jrpg::tile tile(tileset, tileSize);

                // get the current tile number and skip reserved tiles (-1)
                const auto tile_number = level[x + y * width];
                if (tile_number == RESERVED_TILEID) {
                    continue;
                }
                tile.set_tile_id(tile_number);

                // find its position in the tileset texture
                const auto tw = tile_number % (tileset->getSize().x / tile.get_tile_size().x);
                const auto th = tile_number / (tileset->getSize().x / tile.get_tile_size().x);

                // add the tile to the map
                add(std::move(tile), x, y, tw, th);
            }
        }
    }

    void tile_map_layer::add(tile &&tile, std::size_t x, std::size_t y, std::size_t tw, std::size_t th) {
        tile.set_tile_position(sf::Vector2f(x * tile.get_tile_size().x, y * tile.get_tile_size().y));
        tile.set_tile_tex_coords(tw, th);
        _layer.emplace_back(tile);
    }

    bool tile_map_layer::remove(const sf::Vector2f &tilePos) {
        const auto &it = std::remove_if(_layer.begin(), _layer.end(), ([&tilePos](const tile &value) {
                                            return std::round(value.getPosition().x) == std::round(tilePos.x) &&
                                                   std::round(value.getPosition().y) == std::round(tilePos.y);
                                        }));

        if (it != _layer.end()) {
            _layer.erase(it, _layer.end());
            return true;
        }
        return false;
    }

    void tile_map_layer::clear() {
        _layer.clear();
    }

    layer_size_type tile_map_layer::size() const {
        return _size;
    }

    const std::string &tile_map_layer::name() const {
        return _name;
    }

    std::size_t tile_map_layer::width() const {
        return _width;
    }

    std::size_t tile_map_layer::height() const {
        return _height;
    }

    void tile_map_layer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
        for (auto &tile : _layer) {
            target.draw(tile, states);
        }
    }

} // namespace jrpg
