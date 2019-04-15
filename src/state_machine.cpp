#include "../include/state_machine.hpp"

namespace jrpg {
    state_machine::state_machine() : _running(true), _replacing(false), _resuming(false), _adding(false) {
        std::cout << "State Machine constructor\n";
    }

    state_machine::~state_machine() {
        std::cout << "State Machine destructor\n";
        clear();
    }

    void state_machine::next_state() {
        if (_resuming) {
            if (!_states.empty()) {
                _states.pop();
            }
            if (!_states.empty()) {
                _states.top()->resume();
            }
            _resuming = false;
        }
        if (_adding) {
            if (!_states.empty()) {
                if (_replacing) {
                    _states.pop();
                } else {
                    _states.top()->pause();
                }
            }
            _states.push(std::move(_next_state));
            _adding = false;
        }
    }

    void state_machine::last_state() {
        _resuming = true;
    }

    void state_machine::quit() {
        _running = false;
    }

    void state_machine::clear() {
        _running = false;
        _replacing = false;
        _resuming = false;
        _adding = false;

        while (!_states.empty()) {
            _states.pop();
        }
    }

    bool state_machine::is_running() const {
        return _running;
    }

    void state_machine::handle_events() {
        if (!_states.empty()) {
            _states.top()->handle_events();
        }
    }

    void state_machine::handle_inputs() {
        if (!_states.empty()) {
            _states.top()->handle_inputs();
        }
    }

    void state_machine::update(float deltaTime) {
        if (!_states.empty()) {
            _states.top()->update(deltaTime);
        }
    }

    void state_machine::draw(float deltaTime) {
        if (!_states.empty()) {
            _states.top()->draw(deltaTime);
        }
    }
} // namespace jrpg
