#include <sstream>
#include <fstream>

#include "../include/game.hpp"
#include "../include/tile_map.hpp"

int main() {
    /*jrpg::game engine{640, 480, "jrpg game-engine"};
    std::cout << engine << '\n';

    engine.run();*/

    constexpr std::size_t TILE_SIZE_X = 16;
    constexpr std::size_t TILE_SIZE_Y = 16;

    std::vector<int32_t> level;
    level.reserve(10 * 12);

    std::ifstream file("../res/maps/map_001.csv");

    std::stringstream ss;
    if (file) {
        ss << file.rdbuf();
        file.close();
    }

    std::string str;
    while (std::getline(ss, str, ',')) {
        const auto &tile_id = std::stoi(str);
        level.emplace_back(tile_id);
    }

    jrpg::tile_map map("map_001", level.size(), 10, 12);
    if (!map.load("../res/pokemon_emerald.png", level, {TILE_SIZE_X, TILE_SIZE_Y}, 10, 12)) {
        return EXIT_FAILURE;
    }

    std::cout << "map name: " << map.get_name() << '\n';
    std::cout << map.get_tiles().size() << " tiles in TileMap\n";

    // Create the main window
    // Width = Map Size Width * Tile Size Width
    // Height = Map Size Height * Tile Size Height
    // = n x n pixels
    std::cout << map.get_width() << ", " << map.get_height() << '\n';

    const auto pixel_width = map.get_width() * TILE_SIZE_X;
    const auto pixel_height = map.get_height() * TILE_SIZE_Y;

    sf::RenderWindow window(sf::VideoMode(pixel_width, pixel_height), "SFML window");
    window.setSize({512, 512});
    window.setFramerateLimit(60);

    // Start the game loop
    while (window.isOpen()) {
        // Process events
        sf::Event event{};
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                    // map.clear();
                    // remove tile at position (6, 6) in points or 96px * 96px
                    map.remove({96.f, 96.f});
                    std::cout << map.get_tiles().size() << " tiles in TileMap\n";
                }
            }
        }
        // Clear screen
        window.clear();
        // Draw
        window.draw(map);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
