#pragma once
#include <list>
#include <Windows.h>
#include <dos.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <iostream>

class Snake
{
private:
	enum direct { UP, RIGHT, DOWN, LEFT };
	enum terrType { wall, food, air};
	struct SnakeNode
	{
		COORD pos;
	};

	typedef std::list<SnakeNode> SnakeList;
	SnakeList self;
	direct activeDirect;
	direct newDirect;
	terrType map[25][30];
	void init();
	bool move();
	void end();
	void drow();
public:
	void start();
};

