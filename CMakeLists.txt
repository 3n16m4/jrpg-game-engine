cmake_minimum_required(VERSION 3.8)

project(jrpg-game-engine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra")

# find SFML library
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp include/game.hpp src/game.cpp include/state.hpp include/state_machine.hpp src/state_machine.cpp include/intro_state.hpp src/intro_state.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} sfml-graphics sfml-audio)