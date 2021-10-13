#pragma once
#include "PhysicsObject.h"
#include "Mesh.h"

class Paddle : public PhysicsObject
{
private:

public:
	Paddle();
	~Paddle();

	bool moveLeft;
	bool moveRight;
	void update(const Ogre::FrameEvent& evt) override;

	void CheckBounds();

	void MoveLeft();
	void MoveRight();
};

