#pragma once
#include "PhysicsObject.h"


class Ball : public PhysicsObject
{
private:
	PhysicsObject* paddleReference;
public:
	Ball(PhysicsObject* ref);
	~Ball();

	void update(const Ogre::FrameEvent& evt) override;

	void CheckBounds();

	void checkCollision();
	void ReflectVelocity(bool reflectX);
	void setPaddleReference(PhysicsObject* ref);
};

