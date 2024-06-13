#include "Enemy.h"
Enemy::Enemy() : enemyPos(0, -1000000), rb(5, 0.999f), enemyCircle(50)
{
}

// Updates the enemy's position based on the rb physics.
// The enemy floats from side to side based on a timer that adds
// impulse forces to the enemy's rb.
void Enemy::updateEnemy(sf::RenderWindow& window)
{
	deltaTime = deltaClock.restart();

	// Enemy swinging movement
	if (timer > swingTime) {
		rb.addForce(forceToAdd);
		forceToAdd *= -1;
		timer = 0;
	}
	else { timer++; }
	rb.updatePhysics();

	Vector2 moveVector(rb.velocity, speed * deltaTime.asSeconds());
	enemyPos = enemyPos + moveVector;

	// Movement borders
	if (enemyPos.x > 1130)
	{
		enemyPos.x = 1130;
	}
	else if (enemyPos.x < 150)
	{
		enemyPos.x = 150;
	}
	enemyCircle.draw(window, sf::Vector2f(enemyPos.x, enemyPos.y), 
					 enemySprite);
}

// Checks whether the enemy is currently colliding with the player.
// If the sum of the radii is greater than the distance between the
// positions, the two collide and the enemy gets teleported off-screen.
// Every collision a point gets added to the platers score.
void Enemy::checkCollion(Player player, Score& score) {
	float radiiSum = enemyCircle.radius + player.playerCircle.radius;
	Vector2 enemyToPlayer = enemyPos - player.playerPos;
	float distance = enemyToPlayer.calcLength();

	if (radiiSum >= distance)
	{
		enemyPos.y = 3000;
		score.score++;
	}
}
