#include "../include/menu_state.hpp"

namespace jrpg {
    menu_state::menu_state(state_machine &machine, sf::RenderWindow &window) : state{machine, window} {
        std::cout << "Menu State constructor\n";
        init();
    }

    menu_state::~menu_state() {
        std::cout << "Menu State destructor\n";
        cleanup();
    }

    void menu_state::init() {
        std::cout << "Menu State init\n";

        auto &asset_manager = asset_manager::instance();
        if (!asset_manager.load_texture("menu", "../res/assets/menu.png")) {
            return;
        }

        _sprite.setTexture(*asset_manager.get_texture("menu"), true);
    }

    void menu_state::cleanup() {
        // cleanup assets from the asset manager etc.
        asset_manager::instance().remove_texture("menu");
    }

    void menu_state::handle_events() {
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
                            _machine.last_state();
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

    void menu_state::handle_inputs() {
    }

    void menu_state::update(float deltaTime) {
    }

    void menu_state::draw(float deltaTime) {
        _window.clear();
        _window.draw(_sprite);
        _window.display();
    }

    void menu_state::resume() {
        std::cout << "Resuming Menu State\n";
    }

    void menu_state::pause() {
        std::cout << "Pausing Menu State\n";
    }
}