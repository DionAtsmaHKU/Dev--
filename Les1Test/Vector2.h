#pragma once
#include <cmath>

class Vector2
{
public:
	float x = 0;
	float y = 0;
	Vector2(float xStart, float yStart);
	float calcLength();
	Vector2 operator+(Vector2 other);
	Vector2 operator-(Vector2 other);
};

