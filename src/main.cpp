#include "../include/game.hpp"
#include "../include/tile_map.hpp"
#include "../include/tilemap_parser.hpp"

int main() {
    jrpg::game engine{640, 480, "jrpg game-engine"};
    std::cout << engine << '\n';

    engine.run();

    return EXIT_SUCCESS;
}
