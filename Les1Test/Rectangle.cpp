#include "Rectangle.h"
#include "Shape.h"

Rectangle::Rectangle(int w, int h) : height(h), width(w)
{
}

float Rectangle::calcArea()
{
	return width * height;
}

void Rectangle::draw(sf::RenderWindow& window)
{
	sf::RectangleShape shape(sf::Vector2f(width, height));
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(50, 100);
	window.draw(shape);
}
