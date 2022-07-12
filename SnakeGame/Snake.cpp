#include "Snake.h"


#include "Fruit.h"
#include "Utils.h"

Snake::Snake(int originPosX, int originPosY)
		: m_score(0)
{
	SnakeBody head(originPosX, originPosY);
	m_snake.push_back(head);
}

Snake::~Snake()
{
}

bool Snake::HitTail()
{
	for (int i = 1; i < m_snake.size(); i++)
	{
		if (m_snake[i] == m_snake[0])
			return true;
	}
	return false;
}

bool Snake::HitFruit(Fruit& fruit)
{
	if (m_snake[0].GetPosX() == fruit.GetPosX() && m_snake[0].GetPosY() == fruit.GetPosY())
		return true;

	return false;
}

bool Snake::HitWall(int wallX, int wallY)
{
	if ((m_snake[0].GetPosX() == wallX || m_snake[0].GetPosY() == wallY) ||
		(m_snake[0].GetPosX() == 0 || m_snake[0].GetPosY() == 0))
		return true;

	return false;
}

int Snake::GetScore()
{
	return m_score;
}

void Snake::Move(Utils::Direction dir, Fruit& fruit)
{
	int oldPosX = m_snake[0].GetPosX();
	int oldPosY = m_snake[0].GetPosY();
	for (int i = 1; i < m_snake.size(); i++)
	{
		int currentXPos = m_snake[i].GetPosX();
		int currentYPos = m_snake[i].GetPosY();
		m_snake[i].SetPosX(oldPosX);
		m_snake[i].SetPosY(oldPosY);
		oldPosX = currentXPos;
		oldPosY = currentYPos;
	}

	switch (dir) // changes snake`s head coordinates depending on a direction
	{
	case Utils::Direction::LEFT:
		m_snake[0].SetPosY(m_snake[0].GetPosY() - 1);
		break;
	case Utils::Direction::RIGHT:
		m_snake[0].SetPosY(m_snake[0].GetPosY() + 1);
		break;
	case Utils::Direction::UP:
		m_snake[0].SetPosX(m_snake[0].GetPosX() - 1);
		break;
	case Utils::Direction::DOWN:
		m_snake[0].SetPosX(m_snake[0].GetPosX() + 1);
		break;
	default:
		break;
	}

	if (HitFruit(fruit))
	{
		fruit.SetIsEaten(true);
		SnakeBody body(oldPosX, oldPosY);
		m_snake.push_back(body);
		m_score++;
	}
}

void Snake::Draw(char** field)
{
	for (auto& item : m_snake)
	{
		field[item.GetPosX()][item.GetPosY()] = Utils::snakeSymbol;
	}
}

SnakeBody::SnakeBody(int x, int y)
		: m_x(x), m_y(y)
{
}

SnakeBody::~SnakeBody()
{
}

int SnakeBody::GetPosX()
{
	return m_x;
}

int SnakeBody::GetPosY()
{
	return m_y;
}

void SnakeBody::SetPosX(int x)
{
	m_x = x;
}

void SnakeBody::SetPosY(int y)
{
	m_y = y;
}

bool SnakeBody::operator==(SnakeBody& snakeBody)
{
	if (snakeBody.GetPosX() == m_x && snakeBody.GetPosY() == m_y)
		return true;

	return false;
}
