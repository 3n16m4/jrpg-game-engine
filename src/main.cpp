/**
 * ---------------------------------------------------------------------------------------------------------------------
 * Include rules:
 * ---------------------------------------------------------------------------------------------------------------------
 *
 * 1. include SFML specific headers at the very top, any other external libraries follow next with an empty line
 * 2. standard headers next
 * 3. local project files at the end
 * 4. leave an empty line if there is only 1 include for each different header location
 */

#include <iostream>

#include "../include/game.hpp"

int main() {
    game engine{600, 480, "jrpg game-engine"};
    engine.run();

    return EXIT_SUCCESS;
}