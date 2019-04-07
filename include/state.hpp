#ifndef JRPG_GAME_ENGINE_STATE_HPP
#define JRPG_GAME_ENGINE_STATE_HPP

#include "state_machine.hpp"

namespace jrpg {
    class state_machine;
} // namespace jrpg

namespace sf {
    class RenderWindow;
}

namespace jrpg {
    class state {
      public:
        explicit state(state_machine &machine, sf::RenderWindow &window) : _machine(machine), _window(window) {
        }
        virtual ~state() = default;

        state(const state &) = delete;
        virtual state &operator=(const state &) = delete;

        virtual void init() = 0;
        virtual void cleanup() = 0;

        virtual void handle_events() = 0;
        virtual void handle_inputs() = 0;
        virtual void update(float deltaTime) = 0;
        virtual void draw(float deltaTime) = 0;

        virtual void resume() = 0;
        virtual void pause() = 0;

      protected:
        state_machine &_machine;
        sf::RenderWindow &_window;
    };
} // namespace jrpg

#endif // JRPG_GAME_ENGINE_STATE_HPP
