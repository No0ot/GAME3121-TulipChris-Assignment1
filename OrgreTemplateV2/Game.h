#pragma once
#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "OgreInput.h"
#include "OgreRTShaderSystem.h"
//#include "PhysicsObject.h"
#include "Paddle.h"
#include <iostream>

using namespace Ogre;
using namespace OgreBites;

class Game 
    : public ApplicationContext
    , public InputListener
{
private:
    SceneManager* scnMgr;
    Root* root;
    std::vector<PhysicsObject*> physicsObjects;
    Ogre::SceneNode* paddleNode;

public:
    Game();
    virtual ~Game() {}

    void setup();
    bool keyPressed(const KeyboardEvent& evt);
    void CreateScene();
    void CreateCamera();

    void CreateFrameListener();
};

