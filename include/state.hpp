#ifndef JRPG_GAME_ENGINE_STATE_HPP
#define JRPG_GAME_ENGINE_STATE_HPP

#include "utility/non_copyable.hpp"
#include "utility/non_moveable.hpp"

namespace jrpg {
    class state_machine;
} // namespace jrpg

namespace sf {
    class RenderWindow;
}

namespace jrpg {
    class state : public non_copyable, public non_moveable {
      public:
        explicit state(state_machine &machine, sf::RenderWindow &window) : _machine(machine), _window(window) {
        }
        virtual ~state() = default;

        state(const state &) = delete;
        state(state &&) = delete;
        state &operator=(const state &) = delete;
        state &&operator=(state &) = delete;

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
