#include "Snake.h"

int main()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 }); //Set console cursole position to row 0 column 0
	std::cout << "\n\n\n\n\nPress N for new game and Q to quit.\n";
	char key = _getch();             // Non-buffered non-echoed input
	while (key=='n'||key=='N')
	{
		Snake snake;
		snake.start();
		std::cout << "\n\nPress N for new game and Q to quit.\n";
		key = _getch();
	}
	return 0;
}