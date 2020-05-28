#include "Board.h"

Board::Board() {
	this->restartBoard(this->initial_board);
}
void Board::restartBoard(std::array<std::array<int, 8>, 8> init) {
	int i = 0, j = 0;

	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++) 
			this->board[i][j].setPiece(init[i][j]);

	this->who_can_move = Piece::SIDE::white;

	
	std::ifstream readfile("checkpoint.txt");
	if (!readfile) this->saveBoard();
	readfile.close();

}
void Board::printBoard() {
	int i = 0, j = 0;

	std::cout.setf(std::ios::right);
	std::cout.width(20);
	std::cout << "White" << std::endl;
	std::cout << "   a   b   c   d   e   f   g   h" << std::endl;


	std::cout << ' ' << char(201);
	for (i = 0; i < 7; i++)
		std::cout << char(205) << char(205) << char(205) << char(209);
	std::cout << char(205) << char(205) << char(205) << char(187) << std::endl;


	for (i = 0; i < 8; i++) {
		std::cout << 8 - i << char(186);

		for (j = 0; j < 7; j++) {
			std::cout.width(3);
			std::cout << this->board[i][j].getName() << char(179);
		}

		std::cout.width(3);
		std::cout << this->board[i][7].getName() << char(186) << 8 - i << std::endl;


		if (i < 7) {
			std::cout << ' ' << char(199);

			for (j = 0; j < 7; j++) {
				std::cout << char(196) << char(196) << char(196) << char(197);
			}

			std::cout << char(196) << char(196) << char(196) << char(182) << std::endl;
		}

	}

	std::cout << ' ' << char(200);
	for (i = 0; i < 7; i++)
		std::cout << char(205) << char(205) << char(205) << char(207);
	std::cout << char(205) << char(205) << char(205) << char(188) << std::endl;

	std::cout << "   a   b   c   d   e   f   g   h" << std::endl;

	std::cout.setf(std::ios::right);
	std::cout.width(20);
	std::cout << "Black" << std::endl;
}

void Board::saveBoard() {
	int i = 0, j = 0;
	std::ofstream myfile;
	myfile.open("checkpoint.txt");

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++)
			if (this->board[i][j].getSide() == Piece::SIDE::black)
				myfile << int(this->board[i][j].getPiece()) * -1 << ' ';
			else
				myfile << int(this->board[i][j].getPiece()) << ' ';
		myfile << '\n';
	}

	myfile << int(this->who_can_move) << '\n';

	myfile << this->white_king.iRow << ' ' << this->white_king.iColumn << '\n';
	myfile << this->black_king.iRow << ' ' << this->black_king.iColumn << '\n';

	myfile.close();
}

void Board::loadBoard() {
	std::string my_txt;
	int i = 0, j = 0, iPiece = 0;
	int w_k_Row = 0, w_k_Column = 4, b_k_Row = 7, b_k_Column = 4;

	std::ifstream readfile("checkpoint.txt");

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			readfile >> iPiece;
			this->board[i][j].setPiece(iPiece);
		}
	}

	readfile >> iPiece;
	this->who_can_move = Piece::SIDE(iPiece);

	readfile >> w_k_Row;
	readfile >> w_k_Column;
	readfile >> b_k_Row;
	readfile >> b_k_Column;

	this->white_king.iRow = w_k_Row;
	this->white_king.iColumn = w_k_Column;

	this->black_king.iRow = b_k_Row;
	this->black_king.iColumn = b_k_Column;

	readfile.close();
}

Piece::SIDE Board::whoCanMove() {
	return this->who_can_move;
}

bool Board::getCheck() {
	return this->check;
}

void Board::getKingsPosition() {
	// get kings position 
	int i = 0, j = 0;

	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			if (this->board[i][j].getPiece() == Piece::PIECE::king) {
				if (this->board[i][j].getSide() == Piece::SIDE::white) {
					this->white_king.iRow = i;
					this->white_king.iColumn = j;
				}
				else if (this->board[i][j].getSide() == Piece::SIDE::black) {
					this->black_king.iRow = i;
					this->black_king.iColumn = j;
				}
			}
}

bool Board::isCheckMate() {
	std::vector <Piece::Position> arrayOfPosition = { this->who_make_check };
	Piece::Position king_pos = (this->who_can_move == Piece::SIDE::white ? white_king : black_king);

	int dir_i = 0, dir_j = 0, i = king_pos.iRow, j = king_pos.iColumn, k = 0;

	if (this->canIMove({ king_pos.iRow, king_pos.iColumn }, { king_pos.iRow - 1, king_pos.iColumn - 1 })) return false;
	if (this->canIMove({ king_pos.iRow, king_pos.iColumn }, { king_pos.iRow + 1, king_pos.iColumn + 1 })) return false;
	if (this->canIMove({ king_pos.iRow, king_pos.iColumn }, { king_pos.iRow - 1, king_pos.iColumn + 1 })) return false;
	if (this->canIMove({ king_pos.iRow, king_pos.iColumn }, { king_pos.iRow + 1, king_pos.iColumn - 1 })) return false;

	if (this->canIMove({ king_pos.iRow, king_pos.iColumn }, { king_pos.iRow - 1, king_pos.iColumn })) return false;
	if (this->canIMove({ king_pos.iRow, king_pos.iColumn }, { king_pos.iRow + 1, king_pos.iColumn })) return false;
	if (this->canIMove({ king_pos.iRow, king_pos.iColumn }, { king_pos.iRow, king_pos.iColumn + 1 })) return false;
	if (this->canIMove({ king_pos.iRow, king_pos.iColumn }, { king_pos.iRow, king_pos.iColumn - 1 })) return false;


	if (this->who_make_check.iRow > king_pos.iRow) dir_i = 1;
	else if (this->who_make_check.iRow < king_pos.iRow) dir_i = -1;

	if (this->who_make_check.iColumn > king_pos.iColumn) dir_j = 1;
	else if (this->who_make_check.iColumn < king_pos.iColumn) dir_j = -1;

	if (this->board[this->who_make_check.iRow][this->who_make_check.iColumn].getPiece() != Piece::PIECE::knight) {
		while (abs(i - this->who_make_check.iRow) > abs(dir_i) || abs(j - this->who_make_check.iColumn) > abs(dir_j)) {
			i += dir_i;
			j += dir_j;

			arrayOfPosition.push_back({ i, j });
		}
	}

	for (k = 0; k < arrayOfPosition.size(); k++)
		for (i = 0; i < 8; i++)
			for (j = 0; j < 8; j++)
				if (this->canIMove({ i, j }, arrayOfPosition[k]))
					return false;

	return true;
}

bool Board::isCheck(Piece::SIDE side, bool fl = false) {
	int i = 0, j = 0;
	Piece::Position from{ 0, 0 };
	Piece::Position to{ 0, 0 };

	if (side == Piece::SIDE::white) {
		to = white_king;
	}
	else if (side == Piece::SIDE::black) {
		to = black_king;
	}

	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++) {
			from.iRow = i;
			from.iColumn = j;

			if (!this->board[i][j].isEmpty() && this->board[i][j].getSide() != side) {
				if (this->canIMove(from, to)) {
					if (fl) this->who_make_check = from;
					return true;
				}
			}
		}
	return false;
}

bool Board::haveMove() {
	int i = 0, j = 0, dirr = (this->who_can_move == Piece::SIDE::white ? 1 : -1);

	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++) {
			if (this->board[i][j].getSide() == this->who_can_move) {

				switch (this->board[i][j].getPiece())
				{
				case Piece::PIECE::pawn:
					if (this->canIMove({ i, j }, { i + dirr, j })) return true;
					if (this->canIMove({ i, j }, { i + 2 * dirr, j })) return true;
					if (this->canIMove({ i, j }, { i + dirr, j + 1 })) return true;
					if (this->canIMove({ i, j }, { i + dirr, j - 1 })) return true;
					break;
				case Piece::PIECE::rook:
					if (this->canIMove({ i, j }, { i - 1, j })) return true;
					if (this->canIMove({ i, j }, { i + 1, j })) return true;
					if (this->canIMove({ i, j }, { i, j + 1 })) return true;
					if (this->canIMove({ i, j }, { i, j - 1 })) return true;
					break;
				case Piece::PIECE::knight:
					if (this->canIMove({ i, j }, { i + 2, j + 1 })) return true;
					if (this->canIMove({ i, j }, { i + 2, j - 1 })) return true;
					if (this->canIMove({ i, j }, { i - 2, j + 1 })) return true;
					if (this->canIMove({ i, j }, { i - 2, j - 1 })) return true;

					if (this->canIMove({ i, j }, { i + 1, j + 2 })) return true;
					if (this->canIMove({ i, j }, { i + 1, j - 2 })) return true;
					if (this->canIMove({ i, j }, { i - 1, j + 2 })) return true;
					if (this->canIMove({ i, j }, { i - 1, j - 2 })) return true;

					break;
				case Piece::PIECE::bishop:
					if (this->canIMove({ i, j }, { i - 1, j - 1 })) return true;
					if (this->canIMove({ i, j }, { i + 1, j + 1 })) return true;
					if (this->canIMove({ i, j }, { i - 1, j + 1 })) return true;
					if (this->canIMove({ i, j }, { i + 1, j - 1 })) return true;

					break;
				case Piece::PIECE::king:
					if (this->canIMove({ i, j }, { i - 1, j - 1 })) return true;
					if (this->canIMove({ i, j }, { i + 1, j + 1 })) return true;
					if (this->canIMove({ i, j }, { i - 1, j + 1 })) return true;
					if (this->canIMove({ i, j }, { i + 1, j - 1 })) return true;

					if (this->canIMove({ i, j }, { i - 1, j })) return true;
					if (this->canIMove({ i, j }, { i + 1, j })) return true;
					if (this->canIMove({ i, j }, { i, j + 1 })) return true;
					if (this->canIMove({ i, j }, { i, j - 1 })) return true;
					break;
				case Piece::PIECE::queen:
					if (this->canIMove({ i, j }, { i - 1, j - 1 })) return true;
					if (this->canIMove({ i, j }, { i + 1, j + 1 })) return true;
					if (this->canIMove({ i, j }, { i - 1, j + 1 })) return true;
					if (this->canIMove({ i, j }, { i + 1, j - 1 })) return true;

					if (this->canIMove({ i, j }, { i - 1, j })) return true;
					if (this->canIMove({ i, j }, { i + 1, j })) return true;
					if (this->canIMove({ i, j }, { i, j + 1 })) return true;
					if (this->canIMove({ i, j }, { i, j - 1 })) return true;
					break;
				default:
					break;
				}
			}
		}
	return false;
}


Piece::SIDE Board::whatSide(Piece::Position _position) {
	return this->board[_position.iRow][_position.iColumn].getSide();
}

bool Board::wayIsClear(Piece::Position from, Piece::Position to) {
	int i = from.iRow, j = from.iColumn;

	int row_dir = 0;
	int column_dir = 0;

	if (from.iRow > to.iRow) row_dir = -1;
	else if (from.iRow < to.iRow) row_dir = 1;

	if (from.iColumn > to.iColumn) column_dir = -1;
	else if (from.iColumn < to.iColumn) column_dir = 1;


	if (abs(from.iRow - to.iRow) == abs(from.iColumn - to.iColumn) ||
		abs(from.iRow - to.iRow) != 0 && abs(from.iColumn - to.iColumn) == 0 ||
		abs(from.iRow - to.iRow) == 0 && abs(from.iColumn - to.iColumn) != 0) {

		while (abs(i - to.iRow) > abs(row_dir) || abs(j - to.iColumn) > abs(column_dir)) {
			i += row_dir;
			j += column_dir;

			if (!this->board[i][j].isEmpty())
				return false;
		}
	}
	return true;
}

bool Board::canIMove(Piece::Position from, Piece::Position to) {
	Piece buff_piece;
	buff_piece.setPiece(0);


	if (from.iColumn > 7 || from.iRow > 7 || to.iColumn > 7 || to.iRow > 7 ||
		from.iColumn < 0 || from.iRow < 0 || to.iColumn < 0 || to.iRow < 0) {
		return false;
	}

	// is it piece?
	if (this->board[from.iRow][from.iColumn].isEmpty()) {
		return false;
	}

	if (!this->board[from.iRow][from.iColumn].canWalk(from, to, whatSide(to), wayIsClear(from, to))) {
		// en passant 
		if (this->board[from.iRow][from.iColumn].getPiece() != Piece::PIECE::pawn || !this->board[from.iRow][to.iColumn].getPawnMove()) {
			return false;
		}
	}

	// move piece
	buff_piece = this->board[to.iRow][to.iColumn];
	this->board[to.iRow][to.iColumn] = this->board[from.iRow][from.iColumn];
	this->board[from.iRow][from.iColumn].setPiece(0);


	// get kings position 
	getKingsPosition();

	// is now check?
	if (this->isCheck(this->who_can_move, false)) {
		this->board[from.iRow][from.iColumn] = this->board[to.iRow][to.iColumn];
		this->board[to.iRow][to.iColumn] = buff_piece;

		// get kings position 
		getKingsPosition();

		//std::cout << "CHECK! Change your move!!!" << std::endl;
		return false;
	}

	this->board[from.iRow][from.iColumn] = this->board[to.iRow][to.iColumn];
	this->board[to.iRow][to.iColumn] = buff_piece;

	// get kings position 
	getKingsPosition();
	return true;
}

void Board::castling() {
	if (this->who_can_move == Piece::SIDE::white) {
		if (!this->board[0][0].isMoved() && !this->board[0][4].isMoved() &&
			this->board[0][1].isEmpty() && this->board[0][2].isEmpty() && this->board[0][3].isEmpty() &&
			!this->board[0][0].isEmpty() && !this->board[0][4].isEmpty()) {

			this->board[0][3] = this->board[0][0];
			this->board[0][0].setPiece(0);

			this->board[0][2] = this->board[0][4];
			this->board[0][4].setPiece(0);

			this->who_can_move = Piece::SIDE::black;
		}
		else if (!this->board[0][4].isMoved() && !this->board[0][7].isMoved() &&
			this->board[0][5].isEmpty() && this->board[0][6].isEmpty() &&
			!this->board[0][4].isEmpty() && !this->board[0][7].isEmpty()) {

			this->board[0][5] = this->board[0][7];
			this->board[0][7].setPiece(0);

			this->board[0][6] = this->board[0][4];
			this->board[0][4].setPiece(0);

			this->who_can_move = Piece::SIDE::black;
		}
		else {
			std::cout << "You can't castling now..." << std::endl;
			system("pause");
		}
	}
	else {
		if (!this->board[7][0].isMoved() && !this->board[7][4].isMoved() &&
			this->board[7][1].isEmpty() && this->board[7][2].isEmpty() && this->board[7][3].isEmpty() &&
			!this->board[7][0].isEmpty() && !this->board[7][4].isEmpty()) {

			this->board[7][3] = this->board[7][0];
			this->board[7][0].setPiece(0);

			this->board[7][2] = this->board[7][4];
			this->board[7][4].setPiece(0);

			this->who_can_move = Piece::SIDE::white;
		}
		else if (!this->board[7][4].isMoved() && !this->board[7][7].isMoved() &&
			this->board[7][5].isEmpty() && this->board[7][6].isEmpty() &&
			!this->board[7][4].isEmpty() && !this->board[7][7].isEmpty()) {

			this->board[7][5] = this->board[7][7];
			this->board[7][7].setPiece(0);

			this->board[7][6] = this->board[7][4];
			this->board[7][4].setPiece(0);

			this->who_can_move = Piece::SIDE::white;
		}
		else {
			std::cout << "You can't castling now..." << std::endl;
			system("pause");
		}
	}
}

void Board::movePiece(const std::string& str_from, const std::string& str_to) {
	Piece::Position from{ 0,0 };
	Piece::Position to{ 0,0 };

	if (str_from.length() != 2 && str_to.length() != 2) {
		std::cout << "You should write command like \"Move A2 A4\"!" << std::endl;
		system("pause");
		return;
	}

	from.iRow = 8 - (str_from[1] - '0');
	from.iColumn = toupper(str_from[0]) - 'A';

	to.iRow = 8 - (str_to[1] - '0');
	to.iColumn = toupper(str_to[0]) - 'A';

	if (from.iColumn > 7 || from.iRow > 7 || to.iColumn > 7 || to.iRow > 7 ||
		from.iColumn < 0 || from.iRow < 0 || to.iColumn < 0 || to.iRow < 0) {
		std::cout << "Incorrect command!" << std::endl;
		system("pause");
		return;
	}

	// get kings position 
	getKingsPosition();

	// check who can move now
	// can i move this?
	if (this->board[from.iRow][from.iColumn].getSide() == who_can_move && this->canIMove(from, to)) {
		// kill piece en passat 
		if (this->board[from.iRow][from.iColumn].getPiece() == Piece::PIECE::pawn && this->board[to.iRow][to.iColumn].isEmpty() &&
			abs(from.iColumn - to.iColumn) == abs(from.iRow - to.iRow)) {
			this->board[from.iRow][to.iColumn].setPiece(0);
		}

		// moving
		this->board[to.iRow][to.iColumn] = this->board[from.iRow][from.iColumn];
		this->board[from.iRow][from.iColumn].setPiece(0);

		// check can you en passat
		if (this->board[to.iRow][to.iColumn].getPiece() == Piece::PIECE::pawn) {
			if (abs(from.iRow - to.iRow) == 2 && abs(from.iColumn - to.iColumn) == 0) {
				this->board[to.iRow][to.iColumn].changePawnMove(true);
			}
			else {
				this->board[to.iRow][to.iColumn].changePawnMove(false);
			}
		}


		this->board[to.iRow][to.iColumn].changeIsMoved();

		//check turning pawn on other pieces
		if (this->board[to.iRow][to.iColumn].getPiece() == Piece::PIECE::pawn) {

			if (this->board[to.iRow][to.iColumn].getSide() == Piece::SIDE::white && to.iRow == 7 ||
				this->board[to.iRow][to.iColumn].getSide() == Piece::SIDE::black && to.iRow == 0) {
				std::cout << "You can change your pawn on other piece." << std::endl;
				std::cout << "What would you like? (rock = 1, knight = 2, bishop = 3, queen = 4)." << std::endl;

				int p;
				std::cin >> p;

				this->board[to.iRow][to.iColumn].setPiece(p + 1);
			}
		}

		// change players
		this->who_can_move == Piece::SIDE::white ? this->who_can_move = Piece::SIDE::black : this->who_can_move = Piece::SIDE::white;
	}
	else {
		std::cout << "You can't move this." << std::endl;
		system("pause");
	}
	// <!-- --- --- --!>

}

void Board::game() {

	const std::string exit = "EXIT";
	const std::string move = "MOVE";
	const std::string save = "SAVE";
	const std::string load = "LOAD";
	const std::string restart = "RESTART";
	const std::string castling = "CASTLING";

	std::string strCommand = exit, from = "a0", to = "a0";

	bool bGame = true;

	while (bGame) {
		system("cls");

		this->printBoard();

		// check or mate or stalemate
		checkMateOrStaleMate();

		std::cout << "Write your command: ";
		std::cin >> strCommand;


		std::for_each(strCommand.begin(), strCommand.end(), [](char& c) {
			c = ::toupper(c);
			});


		if (strCommand == exit) {
			bGame = false;
		}
		else if (strCommand == save) {
			this->saveBoard();
		}
		else if (strCommand == load) {
			this->loadBoard();
		}
		else if (strCommand == castling) {
			this->castling();
		}
		else if (strCommand == restart) {
			this->restartBoard(this->initial_board);
		}
		else if (strCommand == move) {
			std::cin >> from >> to;

			this->movePiece(from, to);
		}
		else {
			std::cout << "Incorrect command! ";
			system("pause");
		}
	}
}

void Board::checkMateOrStaleMate() {
	// check for other player
	if (this->isCheck(this->whoCanMove(), true)) {
		if (this->isCheckMate()) {

			std::cout << "CHECKMATE!!!";
			if (this->who_can_move == Piece::SIDE::white)
				std::cout << " Black win!" << std::endl;
			else if (this->who_can_move == Piece::SIDE::black)
				std::cout << " White win!" << std::endl;

			std::cout << "Restarting. ";
			system("pause");

			this->restartBoard(this->initial_board);

			system("cls");
			this->printBoard();
		}
		else
			std::cout << "CHECK. Save your King!!!" << std::endl;
	}
	else if (!this->haveMove()) {

		std::cout << "STALEMATE!!!" << std::endl;

		std::cout << "Restarting. ";
		system("pause");

		this->restartBoard(this->initial_board);

		system("cls");
		this->printBoard();
	}
}