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
	enum direct { UP=1, RIGHT=2, DOWN=3, LEFT=4 };
	enum terrType { wall, food, air};
	struct SnakeNode
	{
		COORD pos;
	};

	typedef std::list<SnakeNode> SnakeList;
	SnakeList self;
	direct activeDirect;
	direct newDirect;
	terrType map[40][55];
	void init();
	bool move();
	void end();
	void draw();
public:
	void start();
};

