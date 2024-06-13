#include "RigidBody.h"
RigidBody::RigidBody(float m, float f) : mass(m), friction(f)
{
}

// Adds an impulse force to the rigidbody
void RigidBody::addForce(float impulse) 
{
	moveForce += impulse;
}

// Updates the object's velocity based on the forces acting on it
void RigidBody::updatePhysics()
{
	deltaTime = deltaClock.restart();
	moveForce *= deltaTime.asSeconds();
	acceleration =  moveForce / mass;
	velocity += acceleration;
	velocity *= friction;
}