#ifndef JRPG_GAME_ENGINE_NON_MOVEABLE_HPP
#define JRPG_GAME_ENGINE_NON_MOVEABLE_HPP

namespace jrpg {
    class non_moveable {
      public:
        non_moveable(non_moveable &&) = delete;
        non_moveable &operator=(non_moveable &&) = delete;

      protected:
        non_moveable() = default;
        ~non_moveable() = default;
    };
} // namespace jrpg

#endif // JRPG_GAME_ENGINE_NON_MOVEABLE_HPP
