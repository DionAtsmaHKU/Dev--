#pragma once
#include "Vector2.h"
#include "RigidBody.h"
#include "Circle.h"
#include "Player.h"
#include "Score.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class Enemy
{
public:
	int timer = 0;
	int swingTime = 750;
	float speed = 0.3f;
	float forceToAdd = 20;
	Vector2 enemyPos;
	RigidBody rb;
	Circle enemyCircle;

	Enemy(int r, int x, int y);
	Enemy();
	~Enemy();
	void updateEnemy(sf::RenderWindow& window);
	void checkCollion(Player player, Score& score);
};

