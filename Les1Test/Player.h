#pragma once
#include <iostream>
#include "Vector2.h"
#include "RigidBody.h"
#include "Circle.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

// The player class is the object the user gets to move using the arrow keys.
// It contains a rigidbody, Vector2, collision circle, and sprite.
class Player
{
public:
	float forceToAdd = 100;

	Vector2 playerPos;
	RigidBody rb;
	Circle playerCircle;
	sf::Sprite playerSprite;

	Player(sf::Sprite s);
	void updatePlayer(sf::RenderWindow& window);
};

