#include "Snake.h"

int main()
{
	std::cout << "\n\nPress N for new game and Q to quit.\n";
	char key = _getch();
	while (key=='n'||key=='N')
	{
		Snake snake;
		snake.start();
		std::cout << "\n\nPress N for new game and Q to quit.\n";
		key = _getch();
	}
	return 0;
}