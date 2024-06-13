#include "Circle.h"
Circle::Circle(int r) : radius(r)
{
}

// Draws the circle based on the radius, given position and given sprite.
void Circle::draw(sf::RenderWindow& window, sf::Vector2f pos,
	sf::Sprite sprite)
{
	sprite.setPosition(pos.x, pos.y);
	sprite.setOrigin(radius, radius); // Makes pos the centre of the circle
	sprite.setScale(1.5f, 1.5f);
	window.draw(sprite);
}
