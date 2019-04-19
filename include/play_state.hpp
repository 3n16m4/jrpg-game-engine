#ifndef JRPG_GAME_ENGINE_PLAY_STATE_HPP
#define JRPG_GAME_ENGINE_PLAY_STATE_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <iostream>
#include <memory>

#include "state_machine.hpp"
#include "asset_manager.hpp"
#include "tile_map.hpp"
#include "tilemap_parser.hpp"

namespace jrpg {
    class play_state final : public state {
      public:
        explicit play_state(state_machine &machine, sf::RenderWindow &window);
        ~play_state() override;

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

        std::unique_ptr<jrpg::tile_map> _map;
        std::unique_ptr<jrpg::tile_map> _map_2;
        std::unique_ptr<jrpg::tile_map> _map_3;
        std::unique_ptr<jrpg::tile_map> _map_4;

        bool _paused{};
    };
} // namespace jrpg

#endif // JRPG_GAME_ENGINE_PLAY_STATE_HPP
