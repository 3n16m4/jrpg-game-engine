#ifndef JRPG_GAME_ENGINE_MENU_STATE_HPP
#define JRPG_GAME_ENGINE_MENU_STATE_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <iostream>

#include "state_machine.hpp"
#include "asset_manager.hpp"

namespace jrpg {
    class menu_state final : public state {
      public:
        explicit menu_state(state_machine &machine, sf::RenderWindow &window);
        ~menu_state() override;

        void init() override;
        void cleanup() override;

        void handle_events() override;
        void handle_inputs() override;
        void update(float deltaTime) override;
        void draw(float deltaTime) override;

        void resume() override;
        void pause() override;

      private:
        sf::Texture _texture;
        sf::Sprite _sprite;
    };
} // namespace jrpg

#endif // JRPG_GAME_ENGINE_MENU_STATE_HPP
