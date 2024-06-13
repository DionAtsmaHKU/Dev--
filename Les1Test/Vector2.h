#pragma once
#include <cmath>

// This class is a custom Vector2 class, an object with an x, y and length.
// Two vectors can be added to each other or subtracted from each other.

class Vector2
{
public:
	float x = 0;
	float y = 0;

	Vector2(float xStart, float yStart);
	float calcLength();

	Vector2 operator+(Vector2 const& other);
	Vector2 operator-(Vector2 const& other);
};

