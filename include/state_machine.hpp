#ifndef JRPG_GAME_ENGINE_STATE_MACHINE_HPP
#define JRPG_GAME_ENGINE_STATE_MACHINE_HPP

#include <memory>
#include <stack>

#include "state.hpp"

namespace jrpg {
    using StateType = std::unique_ptr<state>;

    class state_machine {
      public:
        explicit state_machine();
        ~state_machine() = default;

        state_machine(const state_machine &) = delete;
        state_machine &operator=(const state_machine &) = delete;

        void add_state(StateType state, bool replacing = true);
        void last_state();

        void handle_state_machine();
        void quit();

        StateType &current_state();

        bool is_running() const;
        bool is_adding() const;
        bool is_replacing() const;
        bool is_resuming() const;

      private:
        std::stack<StateType> _states;
        StateType _new_state;

        bool _running;
        bool _adding;
        bool _replacing;
        bool _resuming;
    };
} // namespace jrpg

#endif // JRPG_GAME_ENGINE_STATE_MACHINE_HPP
