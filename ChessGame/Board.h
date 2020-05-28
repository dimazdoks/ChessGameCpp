#pragma once
#include <string>
#include <array>
#include <vector>
#include <fstream>
#include "Piece.h"


class Board {
private:
	std::array<std::array<Piece, 8>, 8> board;
	const std::array<std::array<int, 8>, 8> initial_board{
		{
			{ 2,  3,  4,  5,  6,  4,  3,  2 },
			{ 1,  1,  1,  1,  1,  1,  1,  1 },
			{ 0,  0,  0,  0,  0,  0,  0,  0 },
			{ 0,  0,  0,  0,  0,  0,  0,  0 },
			{ 0,  0,  0,  0,  0,  0,  0,  0 },
			{ 0,  0,  0,  0,  0,  0,  0,  0 },
			{-1, -1, -1, -1, -1, -1, -1, -1 },
			{-2, -3, -4, -5, -6, -4, -3, -2 },
		}
	};

	Piece::SIDE who_can_move = Piece::SIDE::white;

	Piece::Position white_king{ 0, 4 };
	Piece::Position black_king{ 7, 4 };

	Piece::Position who_make_check{ -1, -1 };

	bool check = false;
public:

	Board();
	void printBoard();
	void restartBoard(std::array<std::array<int, 8>, 8>);
	void saveBoard();
	void loadBoard();

	Piece::SIDE whoCanMove();
	bool getCheck();

	void getKingsPosition();
	bool isCheckMate();
	bool isCheck(Piece::SIDE, bool);
	bool haveMove();
	void castling();
	void movePiece(const std::string&, const std::string&);
	bool canIMove(Piece::Position, Piece::Position);
	Piece::SIDE whatSide(Piece::Position);
	bool wayIsClear(Piece::Position, Piece::Position);
	void game();
	void checkMateOrStaleMate();
};