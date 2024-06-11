#pragma once
class RigidBody
{
public:
	float mass = 1;
	float friction;
	float deltaTime = 0.05;
	float velocity = 0;
	float acceleration = 0;
	float moveForce = 0;

	RigidBody(float m, float co);
	void addForce(float impulse);
	void updatePhysics();
};

