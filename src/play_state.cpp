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

        // initialize the map
        _map = std::make_unique<tile_map>("village_001");
        if (!_map->load_tileset("../res/tilesets/tileset-shinygold.png")) {
            return;
        }

        // setup map layers
        tile_map_layer ground_layer("../res/maps/some_map_Ground.csv", {TILE_SIZE_X, TILE_SIZE_Y}, 25, 32);
        tile_map_layer trees_layer("../res/maps/some_map_Trees.csv", {TILE_SIZE_X, TILE_SIZE_Y}, 25, 32);
        tile_map_layer houses_layer("../res/maps/some_map_Houses.csv", {TILE_SIZE_X, TILE_SIZE_Y}, 25, 32);
        tile_map_layer deco_layer("../res/maps/some_map_Deco.csv", {TILE_SIZE_X, TILE_SIZE_Y}, 25, 32);

        _map->add_layer(0, std::move(ground_layer));
        _map->add_layer(1, std::move(trees_layer));
        _map->add_layer(2, std::move(houses_layer));
        _map->add_layer(3, std::move(deco_layer));

        /*
         *
         * tile_map:
         * -    contains all layers for the necessary map [done]
         * -    add layers / remove layers [done]
         * -    can load a tileset [done]
         * -    has a mapname from constructor [done]
         * -    drawable (draws all loaded layers) [done]
         *
         * tile_map *map = new tile_map("village_001", width, height);
         *
         * tile_map_layer:
         * -    has std::vector<tile> tiles for each layer containing width and height [done]
         * -    loads tiles into layers using parser [done]
         * -    add / remove tiles from layer [done]
         * -    clear whole layer [done]
         * -    drawable [done]
         * -    layer derives name from parsed layer [done]
         *
         * tile_map_layer *ground_layer = new tile_map_layer("ground.csv", width, height);
         * tile_map_layer *trees_layer = new tile_map_layer("trees.csv", width, height);
         *
         * map.add_layer(&ground_layer);
         * map.add_layer(&trees_layer);
         *
         * in draw method:
         *
         * _window.draw(map);   this will call the overriden draw method in tile_map and render
         *                      each layer accordingly.
         */

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
