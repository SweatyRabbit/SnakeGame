#include "Fruit.h"

#include "Utils.h"

Fruit::Fruit(int x, int y)
		: m_x(x), m_y(y), m_isEaten(false)
{
}

Fruit::~Fruit()
{
}

void Fruit::Draw(char** field)
{
	field[m_x][m_y] = Utils::fruitSymbol;
}
