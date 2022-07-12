#pragma once


class Render
{
public:
	virtual ~Render() {}

	virtual void Draw(char** field) = 0;
};

