#pragma once
#include "PhysicsObject.h"


class Ball : public PhysicsObject
{
private:
	PhysicsObject* paddleReference;
	bool inPlay;
public:
	Ball(PhysicsObject* ref);
	~Ball();
	int lives = 5;
	int score;

	void update(const Ogre::FrameEvent& evt) override;

	void CheckBounds();

	void checkCollision();
	void ReflectVelocity(bool reflectX);
	void setPaddleReference(PhysicsObject* ref);
	void ResetBall();
	void BeginPlay();
};

