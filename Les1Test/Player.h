#pragma once
#include <iostream>
#include "Vector2.h"
#include "RigidBody.h"
#include "Circle.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class Player
{
public:
	Vector2 playerPos;
	RigidBody rb;
	Circle playerCircle;

	Player(int r);
	void updatePlayer(sf::RenderWindow& window);
};

