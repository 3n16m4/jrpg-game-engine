#ifndef JRPG_GAME_ENGINE_TILE_HPP
#define JRPG_GAME_ENGINE_TILE_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace jrpg {
    using Texture = std::shared_ptr<sf::Texture>;

    class tile : public sf::Drawable, public sf::Transformable {
      public:
        explicit tile(Texture texture, const sf::Vector2u &size, const sf::Vector2f &pos);
        explicit tile(Texture texture, const sf::Vector2u &size);
        ~tile() override = default;

        void set_tile_position(const sf::Vector2f &pos);
        void set_tile_tex_coords(std::size_t tw, std::size_t th);

        sf::VertexArray &get_vertices();

        const sf::Vector2u &get_tile_size() const;

        void set_tile_id(std::size_t tile_id);
        std::size_t get_tile_id() const;

        friend bool operator==(const tile &t1, const tile &t2);
        friend bool operator!=(const tile &t1, const tile &t2);

      protected:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

      private:
        sf::VertexArray _vertices;
        Texture _texture;
        sf::Vector2u _tile_size;
        std::size_t _tile_id;
    };
} // namespace jrpg

#endif // JRPG_GAME_ENGINE_TILE_HPP
