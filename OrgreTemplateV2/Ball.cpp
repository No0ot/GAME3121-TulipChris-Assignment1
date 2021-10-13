#include "Ball.h"
#include <iostream>

Ball::Ball()
{
	SetMoveSpeed(40.0f);
	SetVelocity(Ogre::Vector3(1.0f, 1.0f, 0.0f));
}

Ball::~Ball()
{
}

void Ball::update(const Ogre::FrameEvent& evt)
{
	getNode()->translate((GetVelocity() * GetMoveSpeed()) * evt.timeSinceLastFrame);
	//SetVelocity(GetVelocity() * 0.95f);

	CheckBounds();
	std::cout << getNode()->getPosition().x<< std::endl;
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
	
}

void Ball::ReflectVelocity(bool reflectX)
{
	if (reflectX)
		SetVelocity(Ogre::Vector3(GetVelocity().x * -1, GetVelocity().y, GetVelocity().z));
	else
		SetVelocity(Ogre::Vector3(GetVelocity().x, GetVelocity().y * -1, GetVelocity().z));

	//std::cout << GetMesh()->getBoundingRadius() << std::endl;
}
