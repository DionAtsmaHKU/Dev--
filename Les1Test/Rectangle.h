#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
private:
	int height = 0;
	int width = 0;
public:
	Rectangle(int w, int h);
	float calcArea();
	void draw(sf::RenderWindow& window);
};