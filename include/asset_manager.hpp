#ifndef JRPG_GAME_ENGINE_ASSET_MANAGER_HPP
#define JRPG_GAME_ENGINE_ASSET_MANAGER_HPP

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <memory>
#include <string>
#include <unordered_map>

namespace jrpg {
    using Texture = std::shared_ptr<sf::Texture>;
    using Font = std::shared_ptr<sf::Font>;

    class asset_manager {
      public:
        explicit asset_manager() = default;
        ~asset_manager() = default;

        bool load_texture(const std::string &name, const std::string &filename);
        Texture get_texture(const std::string &name);

        bool load_font(const std::string &name, const std::string &filename);
        Font get_font(const std::string &name);

        void free_textures();
        void free_fonts();

      private:
        std::unordered_map<std::string, Texture> _textures;
        std::unordered_map<std::string, Font> _fonts;
    };
} // namespace jrpg

#endif // JRPG_GAME_ENGINE_ASSET_MANAGER_HPP
