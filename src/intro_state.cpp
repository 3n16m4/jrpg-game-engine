#include "../include/intro_state.hpp"
#include "../include/play_state.hpp"

namespace jrpg {
    intro_state::intro_state(jrpg::state_machine &machine, sf::RenderWindow &window) : state{machine, window} {
        std::cout << "Intro State constructor\n";
        init();
    }

    intro_state::~intro_state() {
        std::cout << "Intro State destructor\n";
        cleanup();
    }

    void intro_state::init() {
        std::cout << "Intro State init\n";

        auto &asset_manager = asset_manager::instance();
        if (!asset_manager.load_texture("intro", "../res/assets/intro.png")) {
            return;
        }

        const auto &intro_texture = asset_manager.get_texture("intro");
        _sprite.setTexture(*intro_texture, true);

        _alpha = sf::Color(0, 0, 0, 255);

        _rect.setFillColor(_alpha);
        _rect.setSize(static_cast<sf::Vector2f>(intro_texture->getSize()));
    }

    void intro_state::cleanup() {
        // cleanup assets from the asset manager etc.
        asset_manager::instance().remove_texture("intro");
    }

    void intro_state::handle_events() {
        sf::Event event{};

        while (_window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    _machine.quit();
                    _window.close();
                    break;

                case sf::Event::KeyPressed: {
                    switch (event.key.code) {
                        case sf::Keyboard::Space:
                            _machine.replace<play_state>(_machine, _window);
                            break;

                        case sf::Keyboard::Escape:
                            _machine.quit();
                            break;

                        default:
                            break;
                    }
                    break;
                }

                default:
                    break;
            }
        }
    }

    void intro_state::handle_inputs() {
    }

    void intro_state::update(float deltaTime) {
        if (_alpha.a != 0) {
            --_alpha.a;
            _rect.setFillColor(_alpha);
        }
    }

    void intro_state::draw(float deltaTime) {
        // Clear the previous drawing
        _window.clear();

        _window.draw(_sprite);

        // No need to draw if it's transparent
        if (_alpha.a != 0) {
            _window.draw(_rect);
        }
        _window.display();
    }

    void intro_state::resume() {
        std::cout << "Resuming Intro State\n";
    }

    void intro_state::pause() {
        std::cout << "Pausing Intro State\n";
    }
} // namespace jrpg
