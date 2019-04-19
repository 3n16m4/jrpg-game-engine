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

        jrpg::TileMap map_ground_tiles{};
        jrpg::TileMap map_tree_tiles{};
        jrpg::TileMap map_houses_tiles{};
        jrpg::TileMap map_deco_tiles{};

        jrpg::tilemap_parser parser{};
        jrpg::tilemap_parser parser_2{};
        jrpg::tilemap_parser parser_3{};
        jrpg::tilemap_parser parser_4{};

        try {
            map_ground_tiles = parser.parse("../res/maps/some_map_Ground.csv");
            map_tree_tiles = parser_2.parse("../res/maps/some_map_Trees.csv");
            map_houses_tiles = parser_3.parse("../res/maps/some_map_Houses.csv");
            map_deco_tiles = parser_4.parse("../res/maps/some_map_Deco.csv");
        } catch (const std::runtime_error &e) {
            std::cerr << e.what() << '\n';
            return;
        }

        const auto &map_name = parser.get_name();
        const auto &map_name_2 = parser_2.get_name();
        const auto &map_name_3 = parser_3.get_name();
        const auto &map_name_4 = parser_4.get_name();

        _map = std::make_unique<jrpg::tile_map>(map_name, map_ground_tiles.size(), 20, 30);
        _map_2 = std::make_unique<jrpg::tile_map>(map_name_2, map_tree_tiles.size(), 20, 30);
        _map_3 = std::make_unique<jrpg::tile_map>(map_name_3, map_houses_tiles.size(), 20, 30);
        _map_4 = std::make_unique<jrpg::tile_map>(map_name_4, map_deco_tiles.size(), 20, 30);

        if (!_map->load("../res/tilesets/tileset-shinygold.png", map_ground_tiles, {TILE_SIZE_X, TILE_SIZE_Y}, _map->get_width(),
                        _map->get_height())) {
            return;
        }
        if (!_map_2->load("../res/tilesets/tileset-shinygold.png", map_tree_tiles, {TILE_SIZE_X, TILE_SIZE_Y}, _map_2->get_width(),
                        _map_2->get_height())) {
            return;
        }
        if (!_map_3->load("../res/tilesets/tileset-shinygold.png", map_houses_tiles, {TILE_SIZE_X, TILE_SIZE_Y}, _map_2->get_width(),
                        _map_2->get_height())) {
            return;
        }
        if (!_map_4->load("../res/tilesets/tileset-shinygold.png", map_deco_tiles, {TILE_SIZE_X, TILE_SIZE_Y}, _map_2->get_width(),
                        _map_2->get_height())) {
            return;
        }

        // remove tileset
        auto &asset_manager = asset_manager::instance();
        asset_manager.remove_texture("tileset");
        std::cout << "Textures in asset manager: " << asset_manager.textures_size() << '\n';
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
        _window.draw(*_map_2);
        _window.draw(*_map_3);
        _window.draw(*_map_4);
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
