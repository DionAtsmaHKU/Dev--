#pragma once
#include "Shape.h"
#include "SFML/System/Vector2.hpp"

class Circle : public Shape
{
private:
	int radius = 0;
public:
	Circle(int r);
	float calcArea();
	void draw(sf::RenderWindow& window, sf::Vector2f pos);
};
