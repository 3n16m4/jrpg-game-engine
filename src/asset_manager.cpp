#include "../include/asset_manager.hpp"

namespace jrpg {
    bool asset_manager::exists_texture(const std::string &name) {
        return _textures.find(name) != _textures.end();
    }

    bool asset_manager::exists_font(const std::string &name) {
        return _fonts.find(name) != _fonts.end();
    }

    bool asset_manager::exists_sound_buffer(const std::string &name) {
        return _sound_buffers.find(name) != _sound_buffers.end();
    }

    bool asset_manager::load_texture(const std::string &name, const std::string &filename) {
        if (exists_texture(name)) {
            return false;
        }

        Texture texture = std::make_shared<sf::Texture>();
        if (!texture->loadFromFile(filename)) {
            return false;
        }
        _textures.emplace(name, std::move(texture));
        return true;
    }

    bool asset_manager::load_font(const std::string &name, const std::string &filename) {
        if (exists_font(name)) {
            return false;
        }

        Font font = std::make_shared<sf::Font>();
        if (!font->loadFromFile(filename)) {
            return false;
        }
        _fonts.emplace(name, std::move(font));
        return true;
    }

    bool asset_manager::load_sound_buffer(const std::string &name, const std::string &filename) {
        if (exists_sound_buffer(name)) {
            return false;
        }

        SoundBuffer sound_buffer = std::make_shared<sf::SoundBuffer>();
        if (!sound_buffer->loadFromFile(filename)) {
            return false;
        }
        _sound_buffers.emplace(name, std::move(sound_buffer));
        return true;
    }

    void asset_manager::remove_texture(const std::string &name) {
        _textures.erase(name);
    }

    void asset_manager::remove_font(const std::string &name) {
        _fonts.erase(name);
    }

    void asset_manager::remove_sound_buffer(const std::string &name) {
        _sound_buffers.erase(name);
    }

    Texture asset_manager::get_texture(const std::string &name) {
        return !exists_texture(name) ? nullptr : _textures.at(name);
    }

    Font asset_manager::get_font(const std::string &name) {
        return !exists_font(name) ? nullptr : _fonts.at(name);
    }

    SoundBuffer asset_manager::get_sound_buffer(const std::string &name) {
        return !exists_sound_buffer(name) ? nullptr : _sound_buffers.at(name);
    }

    void asset_manager::free_textures() {
        _textures.clear();
    }

    void asset_manager::free_fonts() {
        _fonts.clear();
    }

    void asset_manager::free_sound_buffers() {
        _sound_buffers.clear();
    }

    void asset_manager::free_dangling_textures() {
        for (auto it = _textures.begin(); it != _textures.end();) {
            if (it->second.unique()) {
                it = _textures.erase(it);
            } else {
                ++it;
            }
        }
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

    void asset_manager::free_dangling_sound_buffers() {
        for (auto it = _sound_buffers.begin(); it != _sound_buffers.end();) {
            if (it->second.unique()) {
                it = _sound_buffers.erase(it);
            } else {
                ++it;
            }
        }
    }
} // namespace jrpg
