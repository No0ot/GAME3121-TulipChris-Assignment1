#pragma once
#include "Ogre.h"

using namespace Ogre;


class PhysicsObject
{
private:
	Ogre::SceneNode* node;
    Ogre::ManualObject* mesh;

    float moveSpeed;
    Ogre::Vector3 velocity;
public:
    PhysicsObject();
    ~PhysicsObject();

    virtual void update(const Ogre::FrameEvent& evt) = 0; 

    Ogre::SceneNode* getNode();
    void setNode(Ogre::SceneNode* newnode);

    Ogre::ManualObject* GetMesh();
    void SetMesh(Ogre::ManualObject* newmesh);

    void SetMoveSpeed(float newmovespeed);
    float GetMoveSpeed();

    void SetVelocity(Ogre::Vector3 newvelocity);
    Ogre::Vector3 GetVelocity();
};



