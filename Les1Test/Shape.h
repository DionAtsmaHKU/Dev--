#pragma once
#include "SFML/Graphics.hpp"

class Shape
{
public:
	Shape();
	void setAlpha(float a);
	virtual float calcArea();
	virtual void draw(sf::RenderWindow& window);
};

