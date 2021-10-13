#include "Ball.h"
#include <iostream>

Ball::Ball(PhysicsObject* ref)
{
	SetMoveSpeed(40.0f);
	SetVelocity(Ogre::Vector3(1.0f, 1.0f, 0.0f));
	paddleReference = ref;
}

Ball::~Ball()
{
}

void Ball::update(const Ogre::FrameEvent& evt)
{
	getNode()->translate((GetVelocity() * GetMoveSpeed()) * evt.timeSinceLastFrame);
	//SetVelocity(GetVelocity() * 0.95f);

	CheckBounds();
	checkCollision();
	//std::cout << getNode()->getPosition().x<< std::endl;
}

void Ball::CheckBounds()
{
	
	//Left side
	if (getNode()->getPosition().x < -26.0f)
	{
		ReflectVelocity(true);
	}
	//Right side
	if (getNode()->getPosition().x > 26.0f)
	{
		ReflectVelocity(true);
	}
	//Top side
	if (getNode()->getPosition().y < 21.0f)
	{
		ReflectVelocity(false);
	}
	//Bottom side
	if (getNode()->getPosition().y > -21.0f)
	{
		ReflectVelocity(false);
	}
}

void Ball::checkCollision()
{
	if (paddleReference->getNode()->getPosition().x - (paddleReference->getNode()->getScale().x / 2) < getNode()->getPosition().x &&
		paddleReference->getNode()->getPosition().x + (paddleReference->getNode()->getScale().x / 2) > getNode()->getPosition().x &&
		getNode()->getPosition().y < paddleReference->getNode()->getPosition().y + (paddleReference->getNode()->getScale().y / 2))
	{
		//std::cout << "COLLISION" << std::endl;
		ReflectVelocity(false);
	}
}

void Ball::ReflectVelocity(bool reflectX)
{
	if (reflectX)
		SetVelocity(Ogre::Vector3(GetVelocity().x * -1, GetVelocity().y, GetVelocity().z));
	else
		SetVelocity(Ogre::Vector3(GetVelocity().x, GetVelocity().y * -1, GetVelocity().z));

	//std::cout << GetMesh()->getBoundingRadius() << std::endl;
}

void Ball::setPaddleReference(PhysicsObject* ref)
{
	paddleReference = ref;
}
