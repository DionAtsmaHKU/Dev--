#pragma once
#include <SFML/System/Clock.hpp>

// This class allows the objects to move with physics and determines an
// object's velocity based on its mass and the forces acting on it.
class RigidBody
{
public:
	float mass = 1;
	float friction;
	float velocity = 0;
	float acceleration = 0;
	float moveForce = 0;

	sf::Clock deltaClock;
	sf::Time deltaTime;

	RigidBody(float m, float co);
	void addForce(float impulse);
	void updatePhysics();
};

