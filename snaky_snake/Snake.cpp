#include "Snake.h"


void Snake::init()
{
	//Initialize map
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 55; j++)
		{
			if (i == 0 || i == 39)
				map[i][j] = wall;
			else if (j == 0 || j == 54)
				map[i][j] = wall;
			else
				map[i][j] = air;
		}
	}
	//Initialize snake
	self.push_back(SnakeNode{ {13,16} });
	self.push_back(SnakeNode{ {13,15} });
	self.push_back(SnakeNode{ {13,14} });
	activeDirect = RIGHT;
	//Initialize food
	std::srand(std::time(NULL));
	short tmp1;
	short tmp2;
	for (int i = 0; i < 3; i++)
	{
		tmp1 = std::rand() % 40;
		std::srand(std::rand());
		tmp2 = std::rand() % 55;
		std::srand(std::rand());
		map[tmp1][tmp2] = food;
	}
}
bool Snake::move()
{
	//Handle keydown
	if (_kbhit())
	{
		char key;
		key = _getch();
		switch (key) {
		case 'w':
			newDirect = UP;
			break;
		case 'd':
			newDirect = RIGHT;
			break;
		case 's':
			newDirect = DOWN;
			break;
		case 'a':
			newDirect = LEFT;
			break;
		default:
			newDirect = activeDirect;
		}
	}
	else
		newDirect = activeDirect;
	activeDirect = newDirect;
	//Check direction
	if (std::abs(int(newDirect) - int(activeDirect)) == 2)
		newDirect = activeDirect;
	//Check collidsion
	bool isFood;
	bool isWall;
	SnakeNode nextHead = \
		newDirect == UP ? \
		SnakeNode{ {self.front().pos.X,\
		self.front().pos.Y - 1} }\
		:newDirect == RIGHT ? \
		SnakeNode{ {self.front().pos.X + 1,\
		self.front().pos.Y} }\
		:newDirect == DOWN ? \
		SnakeNode{ {self.front().pos.X,\
		self.front().pos.Y + 1} }
		:SnakeNode{ {self.front().pos.X - 1,\
		self.front().pos.Y} };
	isFood = map[nextHead.pos.Y][nextHead.pos.X] == food;
	isWall = map[nextHead.pos.Y][nextHead.pos.X] == wall;
	if (!isWall)
	{
		self.push_front(nextHead);
		if (!isFood)
			self.pop_back();//move forward
		else
		{
			short tmp1, tmp2;
			tmp1 = std::rand() % 40;//spawn new food
			std::srand(std::rand());
			tmp2 = std::rand() % 55;
			std::srand(std::rand());
			map[tmp1][tmp2] = food;
			map[nextHead.pos.Y][nextHead.pos.X] = air;
		}
		return true;
	}
	else
		return false;
}
void Snake::end()
{
	std::cout << "\fGAME OVER\nYOUR SCORE" << self.size();
	std::cout << "\n\n\a\a\a";
}
void Snake::drow()
{
	COORD coor;
	//Print map
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 55; j++)
		{
			coor.X = j, coor.Y = i;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coor);
			if (map[i][j] == wall)
				printf("X");
			else if (map[i][j] == food)
				printf("0");
			else
				printf(" ");
		}
	}
	//Print snake
	for (SnakeNode node : self)
	{
		coor = node.pos;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coor);
		printf("S");
	}
}
void Snake::start()
{
	init();
	while (move()) {
		drow();
		Sleep(500-3*self.size());
	}
		

	end();

}

