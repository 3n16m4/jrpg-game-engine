#ifndef JRPG_GAME_ENGINE_ASSET_MANAGER_HPP
#define JRPG_GAME_ENGINE_ASSET_MANAGER_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include <memory>
#include <string>
#include <unordered_map>

#include "singleton.hpp"

namespace jrpg {
    using Texture = std::shared_ptr<sf::Texture>;
    using Font = std::shared_ptr<sf::Font>;
    using SoundBuffer = std::shared_ptr<sf::SoundBuffer>;

    class asset_manager final : public singleton<asset_manager> {
      public:
        explicit asset_manager() = default;
        ~asset_manager() = default;

        bool exists_texture(const std::string &name);
        bool exists_font(const std::string &name);
        bool exists_sound_buffer(const std::string &name);

        bool load_texture(const std::string &name, const std::string &filename);
        bool load_font(const std::string &name, const std::string &filename);
        bool load_sound_buffer(const std::string &name, const std::string &filename);

        void remove_texture(const std::string &name);
        void remove_font(const std::string &name);
        void remove_sound_buffer(const std::string &name);

        std::size_t textures_size() const; 
        std::size_t fonts_size() const; 
        std::size_t soundbuffers_size() const; 

        // replace with std::optional<T>
        Texture get_texture(const std::string &name);
        Font get_font(const std::string &name);
        SoundBuffer get_sound_buffer(const std::string &name);

        void free_textures();
        void free_fonts();
        void free_sound_buffers();

        void free_dangling_textures();
        void free_dangling_fonts();
        void free_dangling_sound_buffers();

      private:
        std::unordered_map<std::string, Texture> _textures;
        std::unordered_map<std::string, Font> _fonts;
        std::unordered_map<std::string, SoundBuffer> _sound_buffers;
    };
} // namespace jrpg

#endif // JRPG_GAME_ENGINE_ASSET_MANAGER_HPP
