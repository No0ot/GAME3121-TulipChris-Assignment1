#pragma once
#include "Ogre.h"

class MyMesh
{
private:

public:

	static Ogre::ManualObject* createCubeMesh(Ogre::String name, Ogre::String matName);
	static Ogre::ManualObject* createSphereMesh(Ogre::String name, Ogre::String matName, const float r);
};

