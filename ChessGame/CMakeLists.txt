# CMakeList.txt : CMake project for ChessGame, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (ChessGame "ChessGame.cpp" "ChessGame.h" "Board.cpp" "Board.h" "Piece.cpp" "Piece.h" "Tests.cpp" "Tests.h")

# TODO: Add tests and install targets if needed.
