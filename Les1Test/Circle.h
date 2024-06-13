#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System/Vector2.hpp"

// This class draws the object's sprite and contains the size of its hitbox
// in the form of the radius of the circle.
class Circle
{
public:
	int radius = 0;

	Circle(int r);
	void draw(sf::RenderWindow& window, sf::Vector2f pos, sf::Sprite sprite);
};
