#include "../include/play_state.hpp"
#include "../include/menu_state.hpp"

namespace jrpg {
    play_state::play_state(state_machine &machine, sf::RenderWindow &window) : state(machine, window) {
        std::cout << "Play State constructor\n";
    }

    play_state::~play_state() {
        std::cout << "Play State destructor\n";
        cleanup();
    }

    void play_state::init() {
        std::cout << "Play State init\n";

        auto &asset_manager = asset_manager::instance();
        if (!asset_manager.load_texture("play", "../res/play.png")) {
            return;
        }

        _sprite.setTexture(*asset_manager.get_texture("play"), true);
    }

    void play_state::cleanup() {
        // cleanup assets from the asset manager etc.
    }

    void play_state::handle_events() {
        sf::Event event{};

        while (_window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    _machine.quit();
                    _window.close();
                    break;

                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Escape:
                            _machine.quit();
                            break;

                        case sf::Keyboard::M:
                            _machine.push<menu_state>(_machine, _window);
                            break;

                        default:
                            break;
                    }
                    break;

                default:
                    break;
            }
        }
    }

    void play_state::handle_inputs() {
    }

    void play_state::update(float deltaTime) {
    }

    void play_state::draw(float deltaTime) {
        _window.clear();
        _window.draw(_sprite);
        _window.display();
    }

    void play_state::resume() {
        std::cout << "Resuming Play State\n";
    }

    void play_state::pause() {
        std::cout << "Pausing Play State\n";
    }
} // namespace jrpg
