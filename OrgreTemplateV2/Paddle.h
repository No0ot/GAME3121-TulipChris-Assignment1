#pragma once
#include "PhysicsObject.h"
#include "Mesh.h"

class Paddle : public PhysicsObject
{
private:

public:
	Paddle();
	~Paddle();

	void update(const Ogre::FrameEvent& evt) override;

	void checkBounds();

	void MoveLeft();
	void MoveRight();
};

