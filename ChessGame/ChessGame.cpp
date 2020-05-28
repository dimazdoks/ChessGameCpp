// ChessGame.cpp : Defines the entry point for the application.
//

#include "ChessGame.h"

void help() {
	system("cls");
	std::cout.width(20);
	std::cout << "Game:" << std::endl;
	std::cout << "1.If you want save game, write: \"SAVE\"." << std::endl;
	std::cout << "2.If you want load game, write: \"LOAD\"." << std::endl;
	std::cout << "3.If you want restart game, write: \"RESTART\"." << std::endl;
	std::cout << "4.If you want move piece, write like this: \"MOVE b7 b5\"." << std::endl;
	std::cout << "5.If you want make castling, write: \"castling\"." << std::endl;
	std::cout << "6.If game over, you can restarting it, press ENTER." << std::endl;

	std::cout << std::endl;
	std::cout.width(20);
	std::cout << "Testing:" << std::endl;
	std::cout << "If you want testing, you only \nneed to press enter and \nwatching simulation of game." << std::endl;

	std::cout << "Closing help: ";
	system("pause");

}

int main() {
	Tests tests;
	Board newBoard;
	bool bMenu = true;

	std::string str;

	while (bMenu) {
		system("cls");

		std::cout.width(66);

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "CHESS GAME" << std::endl;

		std::cout << std::endl;

		std::cout.width(75);
		std::cout << "1. Write \"START\" to play game." << std::endl;
		std::cout.width(76);
		std::cout << "2. Write \"TEST\" to testing game." << std::endl;
		std::cout.width(86);
		std::cout << "3. Write \"HELP\" to read how to play or testing game." << std::endl;
		std::cout.width(76);
		std::cout << "4. Write \"EXIT\" to exit game.\n" << std::endl;

		std::cout.width(67);
		std::cout << "Write command: ";
		std::cin >> str;

		std::for_each(str.begin(), str.end(), [](char& c) {
			c = ::toupper(c);
			});

		if (str == "START") {
			newBoard.game();
		}
		else if (str == "TEST") {
			tests.testing();
		}
		else if (str == "EXIT") {
			bMenu = false;
		}
		else if (str == "HELP") {
			help();
		}
	}
}