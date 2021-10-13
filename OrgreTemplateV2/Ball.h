#pragma once
#include "PhysicsObject.h"


class Ball : public PhysicsObject
{
private:
public:
	Ball();
	~Ball();

	void update(const Ogre::FrameEvent& evt) override;

	void CheckBounds();

	void checkCollision();
	void ReflectVelocity(bool reflectX);
};

