#pragma once

#include <vector>

#include "Render.h"
#include "Utils.h"

class Fruit;

class SnakeBody
{
public:
	SnakeBody(int x, int y);
	~SnakeBody();

	int GetPosX(); // return x snake coordinate
	int GetPosY(); // return y snake coordinate

	void SetPosX(int x); // setting new x coordinate for snake to make it move
	void SetPosY(int y); // setting new y coordinate for snake to make it move

	bool operator == (SnakeBody& snakeBody); // overriding operator == to compare SnakBody with SnakeBody

private:
	int m_x, m_y;
};

class Snake : public Render
{
public:
	Snake(int originPosX, int originPosY);
	~Snake();
	
	bool HitTail(); // check if snake is crosses its tail
	bool HitFruit(Fruit& fruit); // check if snake crosses food
	bool HitWall(int wallX, int wallY); // check if snake crosses boards

	int GetScore(); // get player score

	void Move(Utils::Direction dir, Fruit& fruit); // moving snake and check if there was food on its road

	virtual void Draw(char** field) override; // drawing snake symbol

private:
	int m_score;
	std::vector<SnakeBody> m_snake;
};

