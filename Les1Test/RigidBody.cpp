#include "RigidBody.h"

RigidBody::RigidBody(float m, float f) : mass(m), friction(f)
{
}

void RigidBody::addForce(float impulse) 
{
	moveForce += impulse;
}

void RigidBody::updatePhysics()
{
	moveForce *= deltaTime;
	acceleration =  moveForce / mass;
	velocity += acceleration;
	velocity *= friction;
}