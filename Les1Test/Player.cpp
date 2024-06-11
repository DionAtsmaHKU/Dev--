#include "Player.h"

Player::Player(int r) : radius(r), playerPos(800, 750), rb(20, 0.99f), playerCircle(50)
{
}


void Player::updatePlayer(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rb.addForce(-3);
	} 
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
	{
		rb.addForce(3);
	}
	rb.updatePhysics();

	Vector2 moveVector(rb.velocity, 0);
	playerPos = playerPos + moveVector;

	if (playerPos.x > 1400) 
	{
		playerPos.x = 1400;
	}
	else if (playerPos.x < 200) 
	{
		playerPos.x = 200;
	}

	playerCircle.draw(window, sf::Vector2f(playerPos.x, playerPos.y));
}
