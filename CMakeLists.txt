cmake_minimum_required(VERSION 3.8)

project(jrpg-game-engine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra")

# find SFML library
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(${CMAKE_PROJECT_NAME}
        src/main.cpp include/game.hpp src/game.cpp include/state.hpp include/intro_state.hpp src/intro_state.cpp
        include/asset_manager.hpp src/asset_manager.cpp include/menu_state.hpp src/menu_state.cpp
        include/play_state.hpp src/play_state.cpp include/state_machine.hpp src/state_machine.cpp include/tile.hpp
        src/tile.cpp include/tile_map.hpp src/tile_map.cpp include/singleton.hpp include/tile_map_parser.hpp src/tile_map_parser.cpp include/utility/non_copyable.hpp include/utility/non_moveable.hpp include/character_creation_state.hpp src/character_creation_state.cpp include/tile_map_layer.hpp src/tile_map_layer.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} sfml-graphics sfml-audio)