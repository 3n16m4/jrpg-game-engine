#ifndef JRPG_GAME_ENGINE_INTRO_STATE_HPP
#define JRPG_GAME_ENGINE_INTRO_STATE_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <iostream>

#include "state_machine.hpp"

namespace jrpg {
    class intro_state : public state {
      public:
        explicit intro_state(state_machine &machine, sf::RenderWindow &window);
        ~intro_state() override;

        void init() override;

        void handle_events() override;
        void handle_inputs() override;
        void update(float deltaTime) override;
        void draw(float deltaTime) override;

        void resume() override;
        void pause() override;

      private:
        state_machine &_machine;
        sf::RenderWindow &_window;

        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::RectangleShape _rect;
        sf::Color _alpha;
    };
} // namespace jrpg

#endif // JRPG_GAME_ENGINE_INTRO_STATE_HPP
