#include "../include/play_state.hpp"
#include "../include/menu_state.hpp"

namespace jrpg {
    constexpr static std::size_t TILE_SIZE_X = 16;
    constexpr static std::size_t TILE_SIZE_Y = 16;
    constexpr static std::size_t MAP_WIDTH = 25;
    constexpr static std::size_t MAP_HEIGHT = 32;

    play_state::play_state(state_machine &machine, sf::RenderWindow &window)
        : state(machine, window), _village_map("village_001") {
        std::cout << "Play State constructor\n";
        init();
    }

    play_state::~play_state() {
        std::cout << "Play State destructor\n";
        cleanup();
    }

    void play_state::init() {
        std::cout << "Play State init\n";

        if (!_village_map.load_tileset("../res/tilesets/tileset-shinygold.png")) {
            return;
        }

        // setup map layers
        tile_map_layer ground_layer("../res/maps/some_map_Ground.csv", {TILE_SIZE_X, TILE_SIZE_Y}, MAP_WIDTH,
                                    MAP_HEIGHT);
        tile_map_layer trees_layer("../res/maps/some_map_Trees.csv", {TILE_SIZE_X, TILE_SIZE_Y}, MAP_WIDTH, MAP_HEIGHT);
        tile_map_layer houses_layer("../res/maps/some_map_Houses.csv", {TILE_SIZE_X, TILE_SIZE_Y}, MAP_WIDTH,
                                    MAP_HEIGHT);
        tile_map_layer deco_layer("../res/maps/some_map_Deco.csv", {TILE_SIZE_X, TILE_SIZE_Y}, MAP_WIDTH, MAP_HEIGHT);

        std::cout << "name: " << ground_layer.name() << '\n';
        std::cout << "name: " << trees_layer.name() << '\n';
        std::cout << "name: " << houses_layer.name() << '\n';
        std::cout << "name: " << deco_layer.name() << '\n';

        std::cout << "size: " << ground_layer.size() << '\n';
        std::cout << "size: " << trees_layer.size() << '\n';
        std::cout << "size: " << houses_layer.size() << '\n';
        std::cout << "size: " << deco_layer.size() << '\n';

        std::cout << "width: " << ground_layer.width() << '\n';
        std::cout << "width: " << trees_layer.width() << '\n';
        std::cout << "width: " << houses_layer.width() << '\n';
        std::cout << "width: " << deco_layer.width() << '\n';

        std::cout << "height: " << ground_layer.height() << '\n';
        std::cout << "height: " << trees_layer.height() << '\n';
        std::cout << "height: " << houses_layer.height() << '\n';
        std::cout << "height: " << deco_layer.height() << '\n';

        _village_map.add_layer(0, std::move(ground_layer));
        _village_map.add_layer(1, std::move(trees_layer));
        _village_map.add_layer(2, std::move(houses_layer));
        _village_map.add_layer(3, std::move(deco_layer));

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

        _window.draw(_village_map);

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
