#include "Circle.h"
#include "Shape.h"

Circle::Circle(int r) : radius(r)
{
}

float Circle::calcArea()
{
	return 3.14159f * radius * radius;
}

void Circle::draw(sf::RenderWindow& window, sf::Vector2f pos)
{
	sf::CircleShape shape(radius);
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(pos.x, pos.y);
	window.draw(shape);
}
