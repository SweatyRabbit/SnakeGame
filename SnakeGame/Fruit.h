#pragma once

#include "Render.h"


class Fruit : public Render
{
public:
	Fruit(int x, int y);
	~Fruit();

	int GetPosX() { return m_x; } // returning x position of food on map
	int GetPosY() { return m_y; } // returning y position of food on map

	void SetIsEaten(bool eaten) { m_isEaten = eaten; } // setting new value depending on case if the snake ate food or not
	bool IsEaten() { return m_isEaten; } // returning boolean value

	virtual void Draw(char** field) override; // drawing food symbol

private:
	int m_x, m_y;
	bool m_isEaten;
};

