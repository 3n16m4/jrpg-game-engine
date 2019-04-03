#include "../include/game.hpp"

game::game(std::size_t width, std::size_t height, std::string title, std::size_t framerate) {
    _width = width;
    _height = height;
    _framerate = framerate;
    _title = std::move(title);
}

void game::run() {
    _window.create(sf::VideoMode(_width, _height), _title);
    _window.setFramerateLimit(_framerate);

    while (_window.isOpen()) {
        // event processing
        sf::Event event{};

        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                _window.close();
            }
        }

        // handle keyboard input

        // activate the window for OpenGL rendering
        _window.setActive(true);

        // clear the whole window before rendering a new frame
        _window.clear();

        // draw graphical entities

        // end of the current frame, display the contents on the screen
        _window.display();
    }
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
