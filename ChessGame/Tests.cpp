#include "Tests.h"

void Tests::testing() {
	Board newBoard;

	checkT1(newBoard);
	checkT2(newBoard);
	checkT3(newBoard);
	checkT4(newBoard);
	checkT5(newBoard);

	std::cout << "Exit tests: ";
	system("pause");
}

void Tests::reload(Board newBoard) {
	system("cls");
	newBoard.printBoard();
	newBoard.checkMateOrStaleMate();
}
void Tests::checkT1(Board newBoard) {
	newBoard.restartBoard(t1);
	reload(newBoard);

	std::cout << "test #0" << std::endl;
	std::cout << "MOVE GG AA" << std::endl;
	newBoard.movePiece("GG", "AA");

	reload(newBoard);

	std::cout << "test #0" << std::endl;
	std::cout << "MOVE A4 A6" << std::endl;
	newBoard.movePiece("A4", "A6");

	reload(newBoard);

	std::cout << "test #0" << std::endl;
	std::cout << "MOVE A2 A4" << std::endl;
	newBoard.movePiece("A2", "A4");

	reload(newBoard);
	
	std::cout << "Next test. ";
	system("pause");

	newBoard.restartBoard(t2);
	reload(newBoard);

	std::cout << "test #1" << std::endl;
	std::cout << "MOVE A7 A5" << std::endl;
	newBoard.movePiece("A7", "A5");

	system("pause");
	reload(newBoard);

	std::cout << "test #1" << std::endl;
	std::cout << "MOVE B2 B4" << std::endl;
	newBoard.movePiece("B2", "B4");

	system("pause");
	reload(newBoard);

	std::cout << "test #1" << std::endl;
	std::cout << "MOVE A5 B4" << std::endl;
	newBoard.movePiece("A5", "B4");

	system("pause");
	reload(newBoard);


	std::cout << "test #1" << std::endl;
	std::cout << "MOVE G2 G4" << std::endl;
	newBoard.movePiece("G2", "G4");

	system("pause");
	reload(newBoard);

	std::cout << "test #1" << std::endl;
	std::cout << "MOVE C5 B4" << std::endl;
	newBoard.movePiece("C5", "B4");

	reload(newBoard);

	std::cout << "test #1" << std::endl;
	std::cout << "MOVE C5 D4" << std::endl;
	newBoard.movePiece("C5", "D4");

	reload(newBoard);

	std::cout << "test #1" << std::endl;
	std::cout << "MOVE H7 H6" << std::endl;
	newBoard.movePiece("H7", "H6");

	system("pause");
	reload(newBoard);

	std::cout << "test #1" << std::endl;
	std::cout << "MOVE C2 C4" << std::endl;
	newBoard.movePiece("C2", "C4");

	system("pause");
	reload(newBoard);

	std::cout << "test #1" << std::endl;
	std::cout << "MOVE B4 C3" << std::endl;
	newBoard.movePiece("B4", "C3");

	system("pause");
	reload(newBoard);

	std::cout << "test #1" << std::endl;
	std::cout << "MOVE G4 G3" << std::endl;
	newBoard.movePiece("G4", "G3");

	reload(newBoard);
	std::cout << "Next test. ";
	system("pause");
}
void Tests::checkT2(Board newBoard) {
	newBoard.restartBoard(t3);
	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE A8 A4" << std::endl;
	newBoard.movePiece("A8", "A4");

	system("pause");
	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE A1 A5" << std::endl;
	newBoard.movePiece("A1", "A5");

	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE A1 A4" << std::endl;
	newBoard.movePiece("A1", "A4");

	system("pause");
	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE B8 C6" << std::endl;
	newBoard.movePiece("B8", "C6");

	system("pause");
	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE A4 C6" << std::endl;
	newBoard.movePiece("A4", "C6");

	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE A4 C4" << std::endl;
	newBoard.movePiece("A4", "C4");

	system("pause");
	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE D8 A5" << std::endl;
	newBoard.movePiece("D8", "A5");

	system("pause");
	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE C4 C3" << std::endl;
	newBoard.movePiece("C4", "C3");

	system("pause");
	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE A5 D2" << std::endl;
	newBoard.movePiece("A5", "D2");

	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE A5 C3" << std::endl;
	newBoard.movePiece("A5", "C3");

	system("pause");
	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE E1 D2" << std::endl;
	newBoard.movePiece("E1", "D2");

	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE B1 C3" << std::endl;
	newBoard.movePiece("B1", "C3");

	system("pause");
	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE F8 F3" << std::endl;
	newBoard.movePiece("F8", "F3");

	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE F8 A3" << std::endl;
	newBoard.movePiece("F8", "A3");

	system("pause");
	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE F1 H3" << std::endl;
	newBoard.movePiece("F1", "H3");

	system("pause");
	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "CASTLING" << std::endl;
	newBoard.castling();

	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE E8 F7" << std::endl;
	newBoard.movePiece("E8", "F7");

	system("pause");
	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE G1 E2" << std::endl;
	newBoard.movePiece("G1", "E2");

	system("pause");
	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE F7 F8" << std::endl;
	newBoard.movePiece("F7", "F8");

	system("pause");
	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "CASTLING" << std::endl;
	newBoard.castling();

	system("pause");
	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE G8 F6" << std::endl;
	newBoard.movePiece("G8", "F6");

	system("pause");
	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE D1 D6" << std::endl;
	newBoard.movePiece("D1", "D6");

	system("pause");
	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE H8 H7" << std::endl;
	newBoard.movePiece("H8", "H7");

	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE F8 G8" << std::endl;
	newBoard.movePiece("F8", "G8");

	system("pause");
	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE D6 D8" << std::endl;
	newBoard.movePiece("D6", "D8");

	system("pause");
	reload(newBoard);

	std::cout << "test #2" << std::endl;
	std::cout << "MOVE F6 E8" << std::endl;
	newBoard.movePiece("F6", "E8");

	system("pause");
	reload(newBoard);
	
	std::cout << "Next test. ";
	system("pause");
}
void Tests::checkT3(Board newBoard) {
	//CHECKMATE

	newBoard.restartBoard(t1);
	reload(newBoard);

	std::cout << "test #3" << std::endl;
	std::cout << "MOVE E7 E5" << std::endl;
	newBoard.movePiece("E7", "E5");

	system("pause");
	reload(newBoard);

	std::cout << "test #3" << std::endl;
	std::cout << "MOVE E2 E4" << std::endl;
	newBoard.movePiece("E2", "E4");

	system("pause");
	reload(newBoard);

	std::cout << "test #3" << std::endl;
	std::cout << "MOVE F8 C5" << std::endl;
	newBoard.movePiece("F8", "C5");

	system("pause");
	reload(newBoard);

	std::cout << "test #3" << std::endl;
	std::cout << "MOVE B1 C3" << std::endl;
	newBoard.movePiece("B1", "C3");

	system("pause");
	reload(newBoard);

	std::cout << "test #3" << std::endl;
	std::cout << "MOVE D8 H4" << std::endl;
	newBoard.movePiece("D8", "H4");

	system("pause");
	reload(newBoard);

	std::cout << "test #3" << std::endl;
	std::cout << "MOVE G1 H3" << std::endl;
	newBoard.movePiece("G1", "H3");

	system("pause");
	reload(newBoard);

	std::cout << "test #3" << std::endl;
	std::cout << "MOVE H4 F2" << std::endl;
	newBoard.movePiece("H4", "F2");

	//system("pause");
	reload(newBoard);
	std::cout << "Next test. ";
	system("pause");
}
void Tests::checkT4(Board newBoard) {
	//STALEMATE

	newBoard.restartBoard(t4);
	reload(newBoard);

	std::cout << "test #4" << std::endl;
	std::cout << "MOVE G1 G6" << std::endl;
	newBoard.movePiece("G1", "G6");

	system("pause");
	reload(newBoard);
}
void Tests::checkT5(Board newBoard) {
	//PROMOTION PAWN

	newBoard.restartBoard(t5);
	reload(newBoard);

	std::cout << "test #5" << std::endl;
	std::cout << "MOVE B2 B1" << std::endl;
	newBoard.movePiece("B2", "B1");

	reload(newBoard);
}