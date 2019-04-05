#ifndef JRPG_GAME_ENGINE_GAME_HPP
#define JRPG_GAME_ENGINE_GAME_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <string>
#include <ostream>

#include "intro_state.hpp"

namespace jrpg {
    class game {
      public:
        explicit game(std::size_t width, std::size_t height, std::string title, std::size_t framerate = 60);
        ~game() = default;

        void run();

        std::size_t get_width() const;
        std::size_t get_height() const;
        std::size_t get_framerate() const;
        const std::string &get_title() const;

        friend std::ostream &operator<<(std::ostream &os, const game &game);

      private:
        std::size_t _width;
        std::size_t _height;
        std::size_t _framerate;
        std::string _title;

        sf::RenderWindow _window;
        state_machine _machine;
    };
} // namespace jrpg

#endif // JRPG_GAME_ENGINE_GAME_HPP
