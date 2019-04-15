#ifndef JRPG_GAME_ENGINE_NON_COPYABLE_HPP
#define JRPG_GAME_ENGINE_NON_COPYABLE_HPP

namespace jrpg {
    class non_copyable {
      public:
        non_copyable(const non_copyable &) = delete;
        non_copyable &operator=(const non_copyable &) = delete;

      protected:
        non_copyable() = default;
        ~non_copyable() = default;
    };
} // namespace jrpg

#endif // JRPG_GAME_ENGINE_NON_COPYABLE_HPP
