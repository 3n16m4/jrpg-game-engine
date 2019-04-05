#include "../include/intro_state.hpp"

jrpg::intro_state::intro_state(jrpg::state_machine &machine, sf::RenderWindow &window)
    : _machine(machine), _window(window) {
    std::cout << "Into State constructor called @0x" << reinterpret_cast<uintptr_t>(this) << '\n';
}

jrpg::intro_state::~intro_state() {
    std::cout << "Intro State destructor called @0x" << reinterpret_cast<uintptr_t>(this) << '\n';
}

void jrpg::intro_state::init() {
    std::cout << "Intro State init\n";

    // TODO: replace with a resource manager (asset manager)
    _texture.loadFromFile("res/intro.png");
    _sprite.setTexture(_texture, true);

    _alpha = sf::Color(0, 0, 0, 255);

    _rect.setFillColor(_alpha);
    _rect.setSize(static_cast<sf::Vector2f>(_texture.getSize()));
}

void jrpg::intro_state::handle_events() {
    sf::Event event{};

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _machine.quit();
            _window.close();
        }
    }
}

void jrpg::intro_state::handle_inputs() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        std::cout << "replace current state and go to main menu state\n";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        std::cout << "exiting out of intro state...\n";
        _machine.quit();
    }
}

void jrpg::intro_state::update(float deltaTime) {
    if (_alpha.a != 0) {
        --_alpha.a;
        _rect.setFillColor(_alpha);
    }
}

void jrpg::intro_state::draw(float deltaTime) {
    // Clear the previous drawing
    _window.clear();

    _window.draw(_sprite);

    // No need to draw if it's transparent
    if (_alpha.a != 0) {
        _window.draw(_rect);
    }
    _window.display();
}

void jrpg::intro_state::resume() {
    std::cout << "Resuming Intro State\n";
}

void jrpg::intro_state::pause() {
    std::cout << "Pausing Intro State\n";
}
