#ifndef JRPG_GAME_ENGINE_CHARACTER_CREATION_STATE_HPP
#define JRPG_GAME_ENGINE_CHARACTER_CREATION_STATE_HPP

#include <SFML/Graphics/Sprite.hpp>

#include <iostream>

#include "state_machine.hpp"
#include "asset_manager.hpp"

namespace jrpg {
    class character_creation_state final : public state {
      public:
        explicit character_creation_state(jrpg::state_machine &machine, sf::RenderWindow &window);
        ~character_creation_state() override;

        void init() override;
        void cleanup() override;

        void handle_events() override;
        void handle_inputs() override;
        void update(float deltaTime) override;
        void draw(float deltaTime) override;

        void resume() override;
        void pause() override;
    };
} // namespace jrpg

#endif // JRPG_GAME_ENGINE_CHARACTER_CREATION_STATE_HPP
