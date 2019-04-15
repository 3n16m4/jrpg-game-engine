#include "../include/play_state.hpp"
#include "../include/menu_state.hpp"

namespace jrpg {
    constexpr std::size_t TILE_SIZE_X = 16;
    constexpr std::size_t TILE_SIZE_Y = 16;

    play_state::play_state(state_machine &machine, sf::RenderWindow &window) : state(machine, window) {
        std::cout << "Play State constructor\n";
        init();
    }

    play_state::~play_state() {
        std::cout << "Play State destructor\n";
        cleanup();
    }

    void play_state::init() {
        std::cout << "Play State init\n";

        /*auto &asset_manager = asset_manager::instance();
        if (!asset_manager.load_texture("play", "../res/assets/play.png")) {
            return;
        }

        _sprite.setTexture(*asset_manager.get_texture("play"), true);*/

        jrpg::TileMap map_tiles{};
        jrpg::tilemap_parser parser{};

        try {
            map_tiles = parser.parse("../res/maps/map_002.csv");
        } catch (const std::runtime_error &e) {
            std::cerr << e.what() << '\n';
            return;
        }

        const auto &map_name = parser.get_name();
        _map = std::make_unique<jrpg::tile_map>(map_name, map_tiles.size(), 20, 30);

        if (!_map->load("../res/tilesets/pokemon_emerald.png", map_tiles, {TILE_SIZE_X, TILE_SIZE_Y}, _map->get_width(),
                        _map->get_height())) {
            return;
        }
    }

    void play_state::cleanup() {
        // cleanup assets from the asset manager etc.
    }

    void play_state::handle_events() {
        sf::Event event{};

        while (_window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    _machine.quit();
                    _window.close();
                    break;

                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Escape:
                            _machine.quit();
                            break;

                        case sf::Keyboard::M:
                            _machine.push<menu_state>(_machine, _window);
                            break;

                        default:
                            break;
                    }
                    break;

                default:
                    break;
            }
        }
    }

    void play_state::handle_inputs() {
        // don't handle any inputs when this state is paused
        if (_paused) {
            return;
        }
    }

    void play_state::update(float deltaTime) {
        // don't update anything (also not anything?) when this state is paused
        if (_paused) {
            return;
        }
    }

    void play_state::draw(float deltaTime) {
        // don't render anything (really not anything?) when this state is paused
        if (_paused) {
            return;
        }
        _window.clear();
        _window.draw(*_map);
        _window.display();
    }

    void play_state::resume() {
        std::cout << "Resuming Play State\n";
        _paused = false;
    }

    void play_state::pause() {
        std::cout << "Pausing Play State\n";
        _paused = true;
    }
} // namespace jrpg
