#include <iostream>
#include "../include/asset_manager.hpp"

namespace jrpg {
    bool asset_manager::load_texture(const std::string &name, const std::string &filename) {
        const auto &it = _textures.find(name);
        // already existing, don't load
        if (it != _textures.end()) {
            return false;
        }
        Texture texture = std::make_shared<sf::Texture>();
        if (!texture->loadFromFile(filename)) {
            return false;
        }
        _textures[name] = texture;
        return true;
    }

    Texture jrpg::asset_manager::get_texture(const std::string &name) {
        const auto &it = _textures.find(name);
        return it == _textures.end() ? nullptr : _textures.at(name);
    }

    bool asset_manager::load_font(const std::string &name, const std::string &filename) {
        Font font = std::make_shared<sf::Font>();
        if (!font->loadFromFile(filename)) {
            return false;
        }
        _fonts[name] = font;
        return true;
    }

    Font jrpg::asset_manager::get_font(const std::string &name) {
        const auto &it = _fonts.find(name);
        return it == _fonts.end() ? nullptr : _fonts.at(name);
    }

    void asset_manager::free_dangling_texture() {
        std::cout << "previously: " << _textures.size() << '\n';
        for (auto it = _textures.begin(); it != _textures.end();) {
            if (it->second.unique()) {
                it = _textures.erase(it);
            } else {
                ++it;
            }
        }
        std::cout << "now: " << _textures.size() << '\n';
    }

    void asset_manager::free_textures() {
        _textures.clear();
    }

    void asset_manager::free_fonts() {
        _fonts.clear();
    }

    void asset_manager::free_dangling_fonts() {
        for (auto it = _fonts.begin(); it != _fonts.end();) {
            if (it->second.unique()) {
                it = _fonts.erase(it);
            } else {
                ++it;
            }
        }
    }
} // namespace jrpg
