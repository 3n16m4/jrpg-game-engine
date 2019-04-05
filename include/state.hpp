#ifndef JRPG_GAME_ENGINE_STATE_HPP
#define JRPG_GAME_ENGINE_STATE_HPP

namespace jrpg {
    class state {
      public:
        virtual ~state() = default;

        virtual void init() = 0;

        virtual void handle_events() = 0;
        virtual void handle_inputs() = 0;
        virtual void update(float deltaTime) = 0;
        virtual void draw(float deltaTime) = 0;

        virtual void resume() = 0;
        virtual void pause() = 0;
    };
} // namespace jrpg

#endif // JRPG_GAME_ENGINE_STATE_HPP
