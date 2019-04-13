#ifndef JRPG_GAME_ENGINE_SINGLETON_HPP
#define JRPG_GAME_ENGINE_SINGLETON_HPP

template <typename T>
class singleton {
  public:
    singleton(const singleton &) = delete;
    singleton(singleton &&) = delete;
    singleton &operator=(const singleton &) = delete;
    singleton &operator=(singleton &&) = delete;

    static T &instance() {
        static T instance;
        return instance;
    }

  protected:
    explicit singleton() = default;
    ~singleton() = default;
};

#endif // JRPG_GAME_ENGINE_SINGLETON_HPP
