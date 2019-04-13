# jrpg-game-engine
a simple JRPG game engine written in C++ with SFML

# Include rules:
1. include SFML specific headers at the very top, any other external libraries follow next with an empty line
2. standard headers next
3. local project files at the end
4. leave an empty line if there is only 1 include for each different header location

# TODO
- include testing framework (google-test catch2, boost-test etc..)
- implement tilemap parser for maps created with "Tiled" (https://www.mapeditor.org/)
