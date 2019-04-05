#include "../include/game.hpp"

jrpg::game::game(std::size_t width, std::size_t height, std::string title, std::size_t framerate) {
    _width = width;
    _height = height;
    _framerate = framerate;
    _title = std::move(title);

    _machine.add_state(StateType(std::make_unique<intro_state>(_machine, _window)));
}

void jrpg::game::run() {
    _window.create(sf::VideoMode(_width, _height), _title);
    _window.setFramerateLimit(_framerate);

    while (_window.isOpen() && _machine.is_running()) {
        _machine.handle_state_machine();

        // handle input, update and draw each game state
        _machine.current_state()->handle_events();
        _machine.current_state()->handle_inputs();
        _machine.current_state()->update(0.0f);
        _machine.current_state()->draw(0.0f);
    }

    // cleanup if necessary
    std::cout << "Statemachine or window not running anymore.\n";
}

std::size_t jrpg::game::get_width() const {
    return _width;
}

std::size_t jrpg::game::get_height() const {
    return _height;
}

std::size_t jrpg::game::get_framerate() const {
    return _framerate;
}

const std::string &jrpg::game::get_title() const {
    return _title;
}

std::ostream &jrpg::operator<<(std::ostream &os, const jrpg::game &game) {
    os << "_width: " << game._width << " _height: " << game._height << " _framerate: " << game._framerate
       << " _title: " << game._title;
    return os;
}
