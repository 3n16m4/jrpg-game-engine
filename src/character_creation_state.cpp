#include "../include/character_creation_state.hpp"

namespace jrpg {
    character_creation_state::character_creation_state(jrpg::state_machine &machine, sf::RenderWindow &window)
        : state(machine, window) {
        std::cout << "Character Creation State constructor\n";
        init();
    }

    character_creation_state::~character_creation_state() {
        std::cout << "Character Creation State destructor\n";
        cleanup();
    }

    void character_creation_state::init() {
        std::cout << "Character Creation State init\n";
    }

    void character_creation_state::cleanup() {
        // cleanup assets from the asset manager etc.
    }

    void character_creation_state::handle_events() {
    }

    void character_creation_state::handle_inputs() {
    }

    void character_creation_state::update(float deltaTime) {
    }

    void character_creation_state::draw(float deltaTime) {
    }

    void character_creation_state::resume() {
        std::cout << "Resuming Character Creation State\n";
    }

    void character_creation_state::pause() {
        std::cout << "Pausing Character Creation State\n";
    }
}