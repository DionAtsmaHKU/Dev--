#pragma once
class RigidBody
{
public:
	float mass = 1;
	float totalForce = 0;
	float moveForce = 0;
	float frictionForce = 0;
	float fCo;
	float gravityForce = 0;
	float speed = 0;
	float acceleration = 0;

	RigidBody(float m, float co);
	void updatePhysics(float impulse);
};

