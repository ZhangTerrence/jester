cmake_minimum_required(VERSION 3.29)
project(jester)

set(CMAKE_CXX_STANDARD 23)

add_executable(jester main.cpp
        src/bitboard.hpp
        src/bitboard.cpp
        src/pieces.cpp
        src/pieces.hpp
        src/board.cpp
        src/board.hpp
        src/game.cpp
        src/game.hpp
)
