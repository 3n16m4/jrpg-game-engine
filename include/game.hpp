#ifndef JRPG_GAME_ENGINE_GAME_HPP
#define JRPG_GAME_ENGINE_GAME_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <string>

class game {
  public:
    explicit game(std::size_t width, std::size_t height, std::string title, std::size_t framerate = 60);
    ~game() = default;

    void run();

  private:
    std::size_t _width;
    std::size_t _height;
    std::size_t _framerate;
    std::string _title;

    sf::RenderWindow _window;
};

#endif // JRPG_GAME_ENGINE_GAME_HPP
