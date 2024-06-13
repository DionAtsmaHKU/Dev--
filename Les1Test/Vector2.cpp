#include "Vector2.h"
Vector2::Vector2(float xStart, float yStart) : x(xStart), y(yStart)
{	
}

// Calculates the length of this Vector2
float Vector2::calcLength()
{
	return sqrt(x * x + y * y);
}

// Adds two Vector2's together.
Vector2 Vector2::operator+(Vector2 const& other)
{
	float resultX = x + other.x;
	float resultY = y + other.y;
	Vector2 result{ resultX, resultY };
	return result;
}

// Subtracts two Vector2's from each other.
Vector2 Vector2::operator-(Vector2 const& other)
{
	float resultX = x - other.x;
	float resultY = y - other.y;
	Vector2 result{ resultX, resultY };
	return result;
}
