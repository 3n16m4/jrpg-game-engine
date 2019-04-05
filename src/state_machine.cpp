#include "../include/state_machine.hpp"

jrpg::state_machine::state_machine() : _running(false), _adding(false), _replacing(false), _resuming(false) {
}

void jrpg::state_machine::add_state(StateType state, bool replacing) {
    _running = true;
    _adding = true;
    _replacing = replacing;

    _new_state = std::move(state);
}

/**
 * should only be called if there is more than 1 state in the machine
 * else the machine will quit and result in undefined behavior such as trying
 * to call the current state which is not present anymore.
 * in other words, you can only return to a previous state if there is any other
 * state than the current one.
 * calling this->current_state() while there are no states in the machine will
 * result in a segmentation fault ("nullptr-exception")
 */
void jrpg::state_machine::last_state() {
    _resuming = _states.size() > 1;
}

/**
 * called every frame in the game engine loop
 * this state machine can do the following things:
 * - remove states
 * - add states
 * - replace current state
 * - pause current state
 * - resume last state
 *
 */
void jrpg::state_machine::handle_state_machine() {
    // machine got quit signal
    if (!_running) {
        return;
    }
    // handle resuming states
    if (_resuming) {
        // remove current state
        if (!_states.empty()) {
            // TODO: make sure destructor of each state is called before popping
            _states.pop();

            // resume last state
            if (!_states.empty()) {
                _states.top()->resume();
            }
            _resuming = false;
        }
    }
    // handle adding states
    if (_adding) {
        if (!_states.empty()) {
            // replace current state
            if (_replacing) {
                _states.pop();
                // just pause the current state instead of replacing it
            } else {
                _states.top()->pause();
            }
        }
        // add and initialize new state
        _states.push(std::move(_new_state));
        _states.top()->init();
        _adding = false;
    }
}

void jrpg::state_machine::quit() {
    _running = false;
}

jrpg::StateType &jrpg::state_machine::current_state() {
    return _states.top();
}

bool jrpg::state_machine::is_running() const {
    return _running;
}

bool jrpg::state_machine::is_adding() const {
    return _adding;
}

bool jrpg::state_machine::is_replacing() const {
    return _replacing;
}

bool jrpg::state_machine::is_resuming() const {
    return _resuming;
}
