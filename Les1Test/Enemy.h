#pragma once
#include "Vector2.h"
#include "RigidBody.h"
#include "Circle.h"
#include "Player.h"
#include "Score.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>

// The enemy class concerns the objects that fall from the top of the screen,
// which the player has to try and catch. The enemies swing from side to side.
// This class also checks if collision with the player is occurring. 
// It contains a rigidbody, Vector2, collision circle, and sprite.
class Enemy
{
public:
	int timer = 0;
	int swingTime = 1000;
	float speed = 300;
	float forceToAdd = 1000;

	Vector2 enemyPos;
	RigidBody rb;
	Circle enemyCircle;
	sf::Sprite enemySprite;

	sf::Clock deltaClock;
	sf::Time deltaTime;

	Enemy();
	void updateEnemy(sf::RenderWindow& window);
	void checkCollion(Player player, Score& score);
};

