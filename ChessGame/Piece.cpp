#include "Piece.h"

Piece::Piece() {
	this->side = SIDE::empty;
	this->piece = PIECE::empty;
}


void Piece::changeIsMoved() {
	this->is_moved = true;
}

bool Piece::isMoved() {
	return this->is_moved;
}

Piece::PIECE Piece::getPiece() {
	return this->piece;
}
void Piece::setPiece(int iPiece) {
	this->is_moved = false;

	if (iPiece > 0)
		this->side = SIDE::white;
	else if (iPiece < 0)
		this->side = SIDE::black;
	else
		this->side = SIDE::empty;

	this->piece = PIECE(abs(iPiece));
}

bool Piece::isEmpty() {
	return !bool(this->piece);
}

std::string Piece::getName() {
	std::string str;
	switch (this->side)
	{
	case SIDE::white:
		str = "W";
		break;
	case SIDE::black:
		str = "B";
		break;
	default:
		str = "  ";
		break;
	}

	switch (this->piece)
	{
	case PIECE::pawn:
		return str + "P";
	case PIECE::rook:
		return str + "R";
	case PIECE::knight:
		return str + "N";
	case PIECE::bishop:
		return str + "B";
	case PIECE::queen:
		return str + "Q";
	case PIECE::king:
		return str + "K";
	default:
		return str;
	}
}

Piece::SIDE Piece::getSide() {
	return this->side;
}

bool Piece::canWalk(Position from, Position to, SIDE to_side, bool isClearWay) {
	short direction = (this->side == SIDE::white ? 1 : -1);

	int row_diff = to.iRow - from.iRow;
	int col_diff = to.iColumn - from.iColumn;

	if (from.iColumn == to.iColumn && from.iRow == to.iRow)
		return false;

	switch (this->piece)
	{
	case PIECE::pawn:
		return this->canWalkPawn(row_diff, col_diff, direction, to_side, isClearWay);
	case PIECE::rook:
		return this->canWalkRook(row_diff, col_diff, to_side, isClearWay);
	case PIECE::knight:
		return this->canWalkKnight(row_diff, col_diff, to_side);
	case PIECE::bishop:
		return this->canWalkBishop(row_diff, col_diff, to_side, isClearWay);
	case PIECE::queen:
		return this->canWalkQueen(row_diff, col_diff, to_side, isClearWay);
	case PIECE::king:
		return this->canWalkKing(row_diff, col_diff, to_side);
	default:
		return false;
	}
}

bool Piece::canWalkPawn(int row_diff, int col_diff, short direction, SIDE to_side, bool isClearWay) {
	// move on 1 cell
	if (abs(row_diff) == 1 && abs(col_diff) == 0 && row_diff * direction > 0 && to_side == SIDE::empty) {
		return true;
	}

	// kill other piece
	else if (abs(row_diff) == 1 && abs(col_diff) == 1 && row_diff * direction > 0 &&
		to_side != SIDE::empty && to_side != this->side) {
		return true;
	}

	// go on 2 cell
	else if (abs(row_diff) == 2 && abs(col_diff) == 0 && row_diff * direction > 0 &&
		to_side == SIDE::empty && isClearWay && !this->is_moved) {
		return true;
	}
	else
		return false;
}

bool Piece::canWalkRook(int row_diff, int col_diff, SIDE to_side, bool isClearWay) {
	if (row_diff != 0 && col_diff == 0 && to_side != this->side && isClearWay) {
		return true;
	}
	else if (row_diff == 0 && col_diff != 0 && to_side != this->side && isClearWay) {
		return true;
	}
	else
		return false;
}
bool Piece::canWalkKnight(int row_diff, int col_diff, SIDE to_side) {
	if (abs(row_diff) == 2 && abs(col_diff) == 1 && this->side != to_side) {
		return true;
	}
	else if (abs(row_diff) == 1 && abs(col_diff) == 2 && this->side != to_side) {
		return true;
	}
	else
		return false;
}
bool Piece::canWalkBishop(int row_diff, int col_diff, SIDE to_side, bool isClearWay) {
	if (abs(row_diff) == abs(col_diff) && this->side != to_side && isClearWay) {
		return true;
	}
	else
		return false;
}
bool Piece::canWalkQueen(int row_diff, int col_diff, SIDE to_side, bool isClearWay) {
	if (abs(row_diff) == abs(col_diff) && this->side != to_side && isClearWay) {
		return true;
	}
	else if (row_diff != 0 && col_diff == 0 && to_side != this->side && isClearWay) {
		return true;
	}
	else if (row_diff == 0 && col_diff != 0 && to_side != this->side && isClearWay) {
		return true;
	}
	else
		return false;
}
bool Piece::canWalkKing(int row_diff, int col_diff, SIDE to_side) {
	if (abs(row_diff) < 2 && abs(col_diff) < 2 && this->side != to_side) {
		return true;
	}
	return false;
}

void Piece::changePawnMove(bool f) {
	this->firstPawn = f;
}

bool Piece::getPawnMove() {
	return this->firstPawn;
}