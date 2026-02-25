cmake_minimum_required(VERSION 3.10.0)
project(Tetris VERSION 0.1.0 LANGUAGES C CXX)

include_directories(
    include/
)

add_executable(Tetris
    src/Grid.cpp
    src/Square.cpp
    src/Tetromino.cpp
    src/derived_Tetromino.cpp
    src/main.cpp 
    src/tetris_game.cpp
    src/tetris_input.cpp
)

