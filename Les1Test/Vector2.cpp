#include "Vector2.h"
Vector2::Vector2(float xStart, float yStart) : x(xStart), y(yStart)
{	
}

float Vector2::calcLength()
{
	return sqrt(x * x + y * y);
}

Vector2 Vector2::operator+(Vector2 const& other)
{
	float resultX = x + other.x;
	float resultY = y + other.y;
	Vector2 result{ resultX, resultY };
	return result;
}

Vector2 Vector2::operator-(Vector2 const& other)
{
	float resultX = x - other.x;
	float resultY = y - other.y;
	Vector2 result{ resultX, resultY };
	return result;
}
