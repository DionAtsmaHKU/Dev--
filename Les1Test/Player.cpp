#include "Player.h"
Player::Player(sf::Sprite s) : playerPos(640, 800), rb(10, 0.99f),
							   playerCircle(50), playerSprite(s)
{
}

// Updates the player's position based on the rb physics.
// The player gets moved by user input of arrow keys.
void Player::updatePlayer(sf::RenderWindow& window)
{
	// User input adds force to the rb
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

	// Movement borders
	if (playerPos.x > 1130) 
	{
		playerPos.x = 1130;
	}
	else if (playerPos.x < 150) 
	{
		playerPos.x = 150;
	}

	playerCircle.draw(window, sf::Vector2f(playerPos.x, playerPos.y), 
					  playerSprite);
}
