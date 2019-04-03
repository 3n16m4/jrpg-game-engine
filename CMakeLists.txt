cmake_minimum_required(VERSION 3.8)

project(jrpg-game-engine)

set(CMAKE_CXX_STANDARD 17)

# find SFML library
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp include/game.hpp src/game.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} sfml-graphics sfml-audio)