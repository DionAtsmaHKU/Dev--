#include "Player.h"

Player::Player(int r) : radius(r)
{
	playerPos = new Vector2(0, 750);
	rb = new RigidBody(10000, 0.5f);
	playerCircle = new Circle(50);
}

Player::~Player()
{
	delete playerPos;
	delete rb;
	delete playerCircle;
}

void Player::updatePlayer(sf::RenderWindow& window)
{
	
	char input;
	std::cin >> input;
	/*
	if (input == 68) 
	{
		playerPos->x += 0.01;
	}
	 */
	rb->updatePhysics(0);
	Vector2 moveVector(rb->speed, 0);
	// playerPos = playerPos + moveVector;
	playerPos->x += 0.01;
	playerCircle->draw(window, sf::Vector2f(playerPos->x, playerPos->y));
}
