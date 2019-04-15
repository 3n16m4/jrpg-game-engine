#ifndef JRPG_GAME_ENGINE_STATE_MACHINE_HPP
#define JRPG_GAME_ENGINE_STATE_MACHINE_HPP

#include <memory>
#include <iostream>
#include <stack>

#include "state.hpp"

namespace jrpg {
    using State = std::unique_ptr<state>;

    class state_machine final : public non_copyable, public non_moveable {
      public:
        explicit state_machine();
        ~state_machine();

        state_machine(const state_machine &) = delete;
        state_machine &operator=(const state_machine &) = delete;

        template <typename T, typename... Targs>
        void push(Targs &&... args) {
            _adding = true;
            _replacing = false;
            _next_state = std::make_unique<T>(args...);
        }

        template <typename T, typename... Targs>
        void replace(Targs &&... args) {
            _adding = true;
            _replacing = true;
            _next_state = std::make_unique<T>(args...);
        }

        void next_state();
        void last_state();
        void quit();

        void handle_events();
        void handle_inputs();
        void update(float deltaTime);
        void draw(float deltaTime);

        void clear();

        bool is_running() const;

      private:
        std::stack<State> _states;
        State _next_state;

        bool _running;
        bool _replacing;
        bool _resuming;
        bool _adding;
    };
} // namespace jrpg

#endif // JRPG_GAME_ENGINE_STATE_MACHINE_HPP
