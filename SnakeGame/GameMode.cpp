#include "GameMode.h"

#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Fruit.h"
#include "Snake.h"

GameMode::GameMode()
{
	m_field = new char*[Utils::borderHeight];

	for (size_t i = 0; i < Utils::borderHeight; ++i)
		m_field[i] = new char[Utils::borderWidth];
}

GameMode::~GameMode()
{
	for(size_t i = 0; i < Utils::borderHeight; ++i)
		delete[] m_field[i];

}

void GameMode::GameLoop()
{
	Snake snake = CreateSnake();
	Fruit fruit = CreateFruit();
	Utils::Direction direction = Utils::Direction::STOP;
	while (!EndGame(snake))
	{
		DrawGame(fruit, snake);
		Sleep(150);

		Input(direction);
		snake.Move(direction, fruit);

		if (fruit.IsEaten())
		{
			m_field[fruit.GetPosX()][fruit.GetPosY()] = ' ';
			fruit = CreateFruit();
		}
	}

	RestartGame(snake.GetScore());
}

bool GameMode::EndGame(Snake& snake)
{
	return snake.HitWall(Utils::borderHeight - 1, Utils::borderWidth - 1) || snake.HitTail();
}

Fruit GameMode::CreateFruit()
{
	return Fruit( 1 + std::rand() % (Utils::borderHeight - 2), 1 + std::rand() % (Utils::borderWidth - 2));
}

Snake GameMode::CreateSnake()
{
	return Snake(Utils::borderHeight / 2, Utils::borderWidth / 2);
}

void GameMode::DrawGame(Fruit& fruit, Snake& snake)
{
	COORD cursorPosition;
	cursorPosition.X = 0;
	cursorPosition.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

	// upper border
	for (int i = 0; i < Utils::borderWidth; i++)
		m_field[0][i] = Utils::borderSymbol;

    for (int i = 1; i < Utils::borderHeight; i++)
    {
        for (int k = 0; k < Utils::borderWidth; k++)
        {
            // left border
            if (k == 0)
                m_field[i - 1][k] = Utils::borderSymbol;

			// drawing blank space
             m_field[i][k] = ' ';

            // right border
            if (k == Utils::borderWidth - 1)
				m_field[i][k] = Utils::borderSymbol;

        }

	}
	
	// lower border
	for (int i = 0; i < Utils::borderWidth; i++)
		m_field[Utils::borderHeight - 1][i] = Utils::borderSymbol;

	// drawing snake and fruit on map
	fruit.Draw(m_field);
	snake.Draw(m_field);

	// drawing map
	for (size_t i = 0; i < Utils::borderHeight; i++)
	{
		for (size_t j = 0; j < Utils::borderWidth; j++)
		{
			std::cout << m_field[i][j];
		}

		std::cout << std::endl;
	}

	std::cout << "Score: " << snake.GetScore();
}

void GameMode::Input(Utils::Direction& dir)
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			if (dir != Utils::Direction::DOWN)
				dir = Utils::Direction::UP;
			break;
		case 'a':
			if (dir != Utils::Direction::RIGHT)
				dir = Utils::Direction::LEFT;
			break;
		case 's':
			if (dir != Utils::Direction::UP)
				dir = Utils::Direction::DOWN;
			break;
		case 'd':
			if (dir != Utils::Direction::LEFT)
				dir = Utils::Direction::RIGHT;
			break;
		}
	}
}

void GameMode::RestartGame(int score)
{
	system("cls");

	std::cout << "Game over!" << std::endl;
	std::cout << "Your score: " << score << std::endl;
	std::cout << "Press 1 to restart game." << std::endl;
	std::cout << "Press 0 to exit." << std::endl;

	int n;

	std::cin >> n;

	switch (n)
	{
	case 1:
		GameLoop();
		break;
	case 0:
		break;
	}
}
