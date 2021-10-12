#pragma once
#include "Ogre.h"

class MyMesh
{
private:

public:
	Ogre::ManualObject* meshobject;
	MyMesh();
	~MyMesh();

	static Ogre::ManualObject* createCubeMesh(Ogre::String name, Ogre::String matName);
};

