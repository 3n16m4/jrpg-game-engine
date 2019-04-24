#include "../include/tile_map.hpp"

namespace jrpg {
    tile_map::tile_map(std::string name)
        : _name(std::move(name)) {
    }

    tile_map::~tile_map() {
        _map.clear();
    }

    bool tile_map::load_tileset(const std::string &filename) {
        auto &asset_manager = asset_manager::instance();
        return asset_manager.load_texture("tileset", filename);
    }

    void tile_map::add_layer(std::uint8_t layerId, tile_map_layer&& layer) {
        _map.emplace(layerId, layer);
    }

    void tile_map::remove_layer(std::uint8_t layerId) {
        _map.erase(layerId);
    }

    const std::string &tile_map::name() const {
        return _name;
    }

    void tile_map::set_name(const std::string &name) {
        _name = name;
    }

    void tile_map::draw(sf::RenderTarget &target, sf::RenderStates states) const {
        for (auto &layer : _map) {
            target.draw(layer.second, states);
        }
    }
} // namespace jrpg
