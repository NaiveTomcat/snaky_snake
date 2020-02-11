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
	direct activeDirect; // Current direction
	direct newDirect;    // Next direction
	terrType map[40][55];
	void init();         // Initialize game
	bool move();         // Move snake
	void end();          // End game
	void draw();         // Draw map and snake
public:
	void start();        //Start game
};

