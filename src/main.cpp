#include "../include/game.hpp"
#include "../include/tile_map.hpp"
#include "../include/tile_map_parser.hpp"

int main() {
    jrpg::game engine{400, 512, "jrpg game-engine"};
    std::cout << engine << '\n';

    engine.run();

    return EXIT_SUCCESS;
}
