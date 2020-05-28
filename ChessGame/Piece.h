#pragma once
#include <iostream>

class Piece {
public:
	enum class SIDE {
		empty = 0,
		white = 1,
		black = 2
	};
	enum class PIECE {
		empty = 0,
		pawn = 1,
		rook = 2,
		knight = 3,
		bishop = 4,
		queen = 5,
		king = 6
	};
	struct Position
	{
		int iRow;
		int iColumn;
	};


	Piece();
	void changeIsMoved();
	bool isMoved();
	void setPiece(int);
	PIECE getPiece();

	bool isEmpty();
	std::string getName();
	SIDE getSide();
	bool canWalk(Position, Position, SIDE, bool);

	bool canWalkPawn(int, int, short, SIDE, bool);
	bool canWalkRook(int, int, SIDE, bool);
	bool canWalkKnight(int, int, SIDE);
	bool canWalkBishop(int, int, SIDE, bool);
	bool canWalkQueen(int, int, SIDE, bool);
	bool canWalkKing(int, int, SIDE);
	void changePawnMove(bool);
	bool getPawnMove();

private:
	bool is_moved = false;
	SIDE side;
	PIECE piece;
	bool firstPawn = false;
};