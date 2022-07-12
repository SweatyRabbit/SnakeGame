#pragma once

#include "Utils.h"

class Fruit;
class Snake;

class GameMode
{
public:
	GameMode();
	~GameMode();
	 
	 void GameLoop(); // starting the game

private:
	bool EndGame(Snake& snake); // check if game lost

	Fruit CreateFruit(); // creating food on map
	Snake CreateSnake(); // creating snake on map

	void DrawGame(Fruit& fruit, Snake& snake); // drawing map and snake with food

	void Input(Utils::Direction& dir); // checking what button user pressed to move snake

	void RestartGame(int score); // restarting the game if user lose

private:
	char** m_field;
};

