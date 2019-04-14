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
- include testing framework (google-test catch2, boost-test etc..)
