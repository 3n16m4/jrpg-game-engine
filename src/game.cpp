#include "../include/game.hpp"

namespace jrpg {
    game::game(std::size_t width, std::size_t height, std::string title, std::size_t framerate) {
        _width = width;
        _height = height;
        _framerate = framerate;
        _title = std::move(title);

        _machine.push<intro_state>(_machine, _window);
    }

    void game::run() {
        _window.create(sf::VideoMode(_width, _height), _title, sf::Style::Titlebar | sf::Style::Close);
        _window.setFramerateLimit(_framerate);

        while (_window.isOpen() && _machine.is_running()) {
            // handle input, update and draw each game state
            _machine.next_state();
            _machine.handle_events();
            _machine.handle_inputs();
            _machine.update(0.0f);
            _machine.draw(0.0f);
        }

        // cleanup if necessary
        std::cout << "Statemachine or window not running anymore.\n";
    }

    std::size_t game::get_width() const {
        return _width;
    }

    std::size_t game::get_height() const {
        return _height;
    }

    std::size_t game::get_framerate() const {
        return _framerate;
    }

    const std::string &game::get_title() const {
        return _title;
    }

    std::ostream &operator<<(std::ostream &os, const game &game) {
        os << "_width: " << game._width << " _height: " << game._height << " _framerate: " << game._framerate
           << " _title: " << game._title;
        return os;
    }
} // namespace jrpg
