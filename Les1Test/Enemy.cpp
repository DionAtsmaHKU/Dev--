#include "Enemy.h"

Enemy::Enemy(int r, int x, int y) : enemyPos(x, y), rb(3, 0.998f), enemyCircle(50)
{
}

Enemy::Enemy() : enemyPos(0, -1000000), rb(3, 0.998f), enemyCircle(50)
{
}

Enemy::~Enemy()
{
}

void Enemy::updateEnemy(sf::RenderWindow& window)
{
	if (timer > 1500) {
		rb.addForce(forceToAdd);
		forceToAdd *= -1;
		timer = 0;
	}
	else { timer++; }
	rb.updatePhysics();

	Vector2 moveVector(rb.velocity, 0.15);
	enemyPos = enemyPos + moveVector;

	if (enemyPos.x > 1130)
	{
		enemyPos.x = 1130;
	}
	else if (enemyPos.x < 150)
	{
		enemyPos.x = 150;
	}
	enemyCircle.draw(window, sf::Vector2f(enemyPos.x, enemyPos.y));
}

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
