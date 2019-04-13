#include <iostream>

#include "../include/tile.hpp"

namespace jrpg {
    tile::tile(Texture texture, const sf::Vector2u &size, const sf::Vector2f &pos) : tile{std::move(texture), size} {
        set_tile_position(pos);
    }

    tile::tile(Texture texture, const sf::Vector2u &size)
        : _vertices(sf::Quads, 4), _texture(std::move(texture)), _tile_size(size), _tile_id(0) {
        set_tile_position({0.f, 0.f});
    }

    void tile::set_tile_position(const sf::Vector2f &pos) {
        _vertices[0].position = {getPosition().x, getPosition().y + _tile_size.y};
        _vertices[1].position = {getPosition().x, getPosition().y};
        _vertices[2].position = {getPosition().x + _tile_size.x, getPosition().y};
        _vertices[3].position = {getPosition().x + _tile_size.x, getPosition().y + _tile_size.y};

        setPosition(pos);
    }

    void tile::set_tile_tex_coords(std::size_t tw, std::size_t th) {
        _vertices[0].texCoords = {static_cast<float>(_tile_size.x * tw), static_cast<float>(_tile_size.y * (th + 1))};
        _vertices[1].texCoords = {static_cast<float>(_tile_size.x * tw), static_cast<float>(_tile_size.y * th)};
        _vertices[2].texCoords = {static_cast<float>(_tile_size.x * (tw + 1)), static_cast<float>(_tile_size.y * th)};
        _vertices[3].texCoords = {static_cast<float>(_tile_size.x * (tw + 1)),
                                  static_cast<float>(_tile_size.y * (th + 1))};
    }

    sf::VertexArray &tile::get_vertices() {
        return _vertices;
    }

    const sf::Vector2u &tile::get_tile_size() const {
        return _tile_size;
    }

    void tile::set_tile_id(std::size_t tile_id) {
        _tile_id = tile_id;
    }

    std::size_t tile::get_tile_id() const {
        return _tile_id;
    }

    bool operator==(const tile &t1, const tile &t2) {
        return (t1.getPosition() == t2.getPosition()) && t1._tile_id == t2._tile_id;
    }

    bool operator!=(const tile &t1, const tile &t2) {
        return !(operator==(t1, t2));
    }

    void tile::draw(sf::RenderTarget &target, sf::RenderStates states) const {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = _texture.get();

        // draw the vertex array
        target.draw(_vertices, states);
    }
}