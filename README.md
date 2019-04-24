# jrpg-game-engine
a simple JRPG game engine written in C++ with SFML

## what it can do so far
- add and switch to different states
- load and get assets efficiently
- add tiles to tilemaps
- load tilemaps from .csv files

# Include rules:
1. include SFML specific headers at the very top, any other external libraries follow next with an empty line
2. standard headers next
3. local project files at the end
4. leave an empty line if there is only 1 include for each different header location

# TODO
- implement map layers in tilemap parser and tilemap ( PoC currently works, just encapsulate it and more cleanly :) )

using std::vector<tile> = Layer;
using std::vector<Layer> = Map;

Map.at(0) = Layer 0
Map.at(1) = Layer 1
...
Map.at(n) = Layer n

rendering:
for (auto &map : Map) {
    for (auto &tile : Layer) {
        target.draw(tile, states);
    }
}

1. go through map
2. go through each tile in layer
3. render the current tile

- include testing framework (google-test catch2, boost-test etc..)
