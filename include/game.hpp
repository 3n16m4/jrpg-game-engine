#ifndef JRPG_GAME_ENGINE_GAME_HPP
#define JRPG_GAME_ENGINE_GAME_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <string>
#include <ostream>

#include "intro_state.hpp"

#include "utility/non_copyable.hpp"
#include "utility/non_moveable.hpp"

namespace jrpg {
    class game final : public non_copyable, public non_moveable {
      public:
        explicit game(std::size_t width, std::size_t height, std::string title, std::size_t framerateLimit = 60);
        ~game() = default;

        void run();

        std::size_t get_width() const;
        std::size_t get_height() const;
        std::size_t get_framerate_limit() const;
        const std::string &get_title() const;

        friend std::ostream &operator<<(std::ostream &os, const game &game);

      private:
        std::size_t _width;
        std::size_t _height;
        std::size_t _framerate_limit;
        std::string _title;

        sf::RenderWindow _window;
        state_machine _machine;
    };
} // namespace jrpg

#endif // JRPG_GAME_ENGINE_GAME_HPP
