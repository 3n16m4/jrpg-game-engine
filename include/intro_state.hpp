#ifndef JRPG_GAME_ENGINE_INTRO_STATE_HPP
#define JRPG_GAME_ENGINE_INTRO_STATE_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <iostream>

#include "state_machine.hpp"
#include "asset_manager.hpp"

namespace jrpg {
    class intro_state final : public state {
      public:
        explicit intro_state(jrpg::state_machine &machine, sf::RenderWindow &window);
        ~intro_state() override;

        void init() override;
        void cleanup() override;

        void handle_events() override;
        void handle_inputs() override;
        void update(float deltaTime) override;
        void draw(float deltaTime) override;

        void resume() override;
        void pause() override;

      private:
        sf::Sprite _sprite;
        sf::RectangleShape _rect;
        sf::Color _alpha;
    };
} // namespace jrpg

#endif // JRPG_GAME_ENGINE_INTRO_STATE_HPP
