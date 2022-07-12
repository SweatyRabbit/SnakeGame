#pragma once

namespace Utils
{
	const char fruitSymbol = 'O';
	const char snakeSymbol = '*';

	const int borderWidth = 30;
	const int borderHeight = 20;
	const char borderSymbol = '+';

	enum class Direction
	{
		STOP = 0,
		LEFT,
		RIGHT,
		UP,
		DOWN
	};
}

