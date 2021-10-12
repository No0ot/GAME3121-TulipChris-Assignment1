#include "Game.h"

Game::Game()
    : ApplicationContext("GAME3121 - TulipChris - Assignment1")
{
}

void Game::setup()
{
    // do not forget to call the base first
    ApplicationContext::setup();
    addInputListener(this);

    // get a pointer to the already created root
    root = getRoot();
    scnMgr = root->createSceneManager();

    // register our scene with the RTSS
    RTShader::ShaderGenerator* shadergen = RTShader::ShaderGenerator::getSingletonPtr();
    shadergen->addSceneManager(scnMgr);

    CreateScene();
    CreateCamera();
    CreateFrameListener();
}

bool Game::keyPressed(const KeyboardEvent& evt)
{
    if (evt.keysym.sym == SDLK_ESCAPE)
    {
        getRoot()->queueEndRendering();
    }
    return true;
}

void Game::CreateScene()
{
    PhysicsObject* newPaddle = new Paddle();
    paddleNode = scnMgr->getRootSceneNode()->createChildSceneNode("paddleNode");
    newPaddle->setNode(paddleNode);
    physicsObjects.push_back(newPaddle);
    paddleNode->attachObject(newPaddle);

    // -- tutorial section start --
    //! [turnlights]
    scnMgr->setAmbientLight(ColourValue(0.5, 0.5, 0.5));
    //! [turnlights]

    //! [newlight]
    Light* light = scnMgr->createLight("MainLight");
    SceneNode* lightNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    lightNode->attachObject(light);
    //! [newlight]

    //! [lightpos]
    lightNode->setPosition(-80, 80, 50);
    //! [lightpos]
}

void Game::CreateCamera()
{
    //! [camera]
    SceneNode* camNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    // create the camera
    Camera* cam = scnMgr->createCamera("myCam");
    cam->setNearClipDistance(5); // specific to this sample
    cam->setAutoAspectRatio(true);
    camNode->attachObject(cam);
    camNode->setPosition(0, 47, 222);

    // and tell it to render into the main window
    getRenderWindow()->addViewport(cam);
    //! [camera]

}

void Game::CreateFrameListener()
{
    Ogre::FrameListener* FrameListener = new PhysicsFrameListener(physicsObjects);
    root->addFrameListener(FrameListener);
}
