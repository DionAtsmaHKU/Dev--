#pragma once
#include "Shape.h"
#include "SFML/System/Vector2.hpp"

class Circle : public Shape
{
public:
	int radius = 0;
	Circle(int r);
	float calcArea();
	void draw(sf::RenderWindow& window, sf::Vector2f pos);
};
