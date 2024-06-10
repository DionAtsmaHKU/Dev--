#include "RigidBody.h"

RigidBody::RigidBody(float m, float co) : mass(m), fCo(co)
{
	gravityForce = 9.8 * mass;
}

void RigidBody::updatePhysics(float impulse)
{
	moveForce += impulse;
	frictionForce = fCo * -gravityForce;
	totalForce = moveForce + frictionForce;

	acceleration = totalForce / mass;
	speed += acceleration;
}