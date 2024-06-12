#include "Player.h"

Player::Player(int r) : playerPos(640, 800), rb(30, 0.99f), playerCircle(50)
{
}


void Player::updatePlayer(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rb.addForce(-forceToAdd);
	} 
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
	{
		rb.addForce(forceToAdd);
	}
	rb.updatePhysics();

	Vector2 moveVector(rb.velocity, 0);
	playerPos = playerPos + moveVector;

	if (playerPos.x > 1130) 
	{
		playerPos.x = 1130;
	}
	else if (playerPos.x < 150) 
	{
		playerPos.x = 150;
	}

	playerCircle.draw(window, sf::Vector2f(playerPos.x, playerPos.y));
}
