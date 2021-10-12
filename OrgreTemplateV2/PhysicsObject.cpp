#include "PhysicsObject.h"

PhysicsObject::PhysicsObject()
{
	
}

Ogre::SceneNode* PhysicsObject::getNode()
{
	return node;
}

void PhysicsObject::setNode(Ogre::SceneNode* newnode)
{
	node = newnode;
}

Ogre::ManualObject* PhysicsObject::GetMesh()
{
	return mesh;
}

void PhysicsObject::SetMesh(Ogre::ManualObject* newmesh)
{
	mesh = newmesh;
}

void PhysicsObject::SetMoveSpeed(float newmovespeed)
{
	moveSpeed = newmovespeed;
}

float PhysicsObject::GetMoveSpeed()
{
	return moveSpeed;
}

void PhysicsObject::SetVelocity(Ogre::Vector3 newvelocity)
{
	velocity = newvelocity;
}

Ogre::Vector3 PhysicsObject::GetVelocity()
{
	return velocity;
}

PhysicsObject::~PhysicsObject()
{

}
