#pragma once
#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "OgreInput.h"
#include "OgreRTShaderSystem.h"
#include "OgreTrays.h"
#include "Ball.h"
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

    Paddle* paddleObject;
    Ogre::SceneNode* paddleNode;
    Ball* ballObject;
    Ogre::SceneNode* ballNode;

    TrayManager* mTrayMgr;
    TrayListener myTrayListener;
    Label* mInfoLabel;
    Label* mFpsLabel;
    Label* mFps;
    String fpsnum;

    Label* mScoreLabel;
    Label* mScore;
    String scorenum;

    Label* mTpuLabel;
    Label* mTpu;
    String Tpunum;

    Label* mLivesLabel;
    Label* mLives;
    String livesnum;

public:
    Game();
    virtual ~Game() {}


    void setup();
    bool keyPressed(const KeyboardEvent& evt);
    bool keyReleased(const KeyboardEvent& evt);
    void CreateScene();
    void CreateCamera();

    void CreateFrameListener();

    void CreateBackground();
    void CreateLights();
    void CreatePhysicsObjects();
    void CreateUI();

    void UpdateUI(const Ogre::FrameEvent& evt);
};

