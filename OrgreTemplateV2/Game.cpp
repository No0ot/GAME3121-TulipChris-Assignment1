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

    switch (evt.keysym.sym)
    {
    case SDLK_ESCAPE:
        getRoot()->queueEndRendering();
        break;
    case 'a':
        paddleObject->MoveLeft();
        break;
    case 'd':
        paddleObject->MoveRight();
        break;
    default:
        break;
    }
    return true;
}

void Game::CreateScene()
{
    CreateLights();
    CreateBackground();
    CreatePhysicsObjects();
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
    camNode->setPosition(0, 0, 300);

    // and tell it to render into the main window
    getRenderWindow()->addViewport(cam);
    //! [camera]

}

void Game::CreateFrameListener()
{
    Ogre::FrameListener* FrameListener = new PhysicsFrameListener(physicsObjects);
    root->addFrameListener(FrameListener);
}

void Game::CreateBackground()
{
    //The first thing we'll do is create an abstract Plane object. This is not the mesh, it is more of a blueprint.
    Plane plane(Vector3::UNIT_Z, 0);
    //Now we'll ask the MeshManager to create us a mesh using our Plane blueprint. The MeshManager is already keeping track of the resources we loaded when initializing our application. On top of this, it can create new meshes for us.
    MeshManager::getSingleton().createPlane(
        "ground", RGN_DEFAULT,
        plane,
        1500, 1500, 20, 20,
        true,
        1, 5, 5,
        Vector3::UNIT_Y);

    //Now we will create a new Entity using this mesh.
    //We want to tell our SceneManager not to cast shadows from our ground Entity. It would just be a waste. Don't get confused, this means the ground won't cast a shadow, it doesn't mean we can't cast shadows on to the ground.
    Entity* groundEntity = scnMgr->createEntity("ground");
    scnMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
    groundEntity->setCastShadows(false);

    //And finally we need to give our ground a material.
    groundEntity->setMaterialName("Examples/Rockwall");
}

void Game::CreateLights()
{
    // -- tutorial section start --
//! [turnlights]
    scnMgr->setAmbientLight(ColourValue(0.5, 0.5, 0.5));
    //! [turnlights]

    //! [newlight]
    Light* light = scnMgr->createLight("MainLight");
    SceneNode* mainlightNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    mainlightNode->attachObject(light);
    //! [newlight]

    //! [lightpos]
    mainlightNode->setPosition(-80, 80, 50);
    //! [lightpos]
    Light* light1 = scnMgr->createLight("Light1");
    light1->setType(Ogre::Light::LT_POINT);
    // Set Light Color
    light1->setDiffuseColour(1.0f, 1.0f, 1.0f);
    // Set Light Reflective Color
    light1->setSpecularColour(1.0f, 0.0f, 0.0f);
    // Set Light (Range, Brightness, Fade Speed, Rapid Fade Speed)
    light1->setAttenuation(10, 0.5, 0.045, 0.0);
    //! 
    Entity* lightEnt = scnMgr->createEntity("LightEntity", "sphere.mesh");
    SceneNode* lightNode = scnMgr->createSceneNode("LightNode");
    lightNode->attachObject(lightEnt);
    lightNode->attachObject(light1);
    lightNode->setScale(0.01f, 0.01f, 0.01f);
}

void Game::CreatePhysicsObjects()
{
    Ogre::ManualObject* cubeMesh = MyMesh::createCubeMesh("Cube", "FlatVertexColour");
    paddleNode = scnMgr->getRootSceneNode()->createChildSceneNode("paddleNode");
    paddleNode->attachObject(cubeMesh);
    paddleNode->setScale(10.0, 2.0, 2.0);
    paddleNode->setPosition(0, -15, 250);

    paddleObject = new Paddle();
    paddleObject->setNode(paddleNode);
    paddleObject->SetMesh(cubeMesh);

    Ogre::ManualObject* sphereMesh = MyMesh::createSphereMesh("Sphere", "FlatVertexColour", 1.0f);
    ballNode = scnMgr->getRootSceneNode()->createChildSceneNode("ballNode");
    ballNode->attachObject(sphereMesh);
    ballNode->setScale(1.0, 1.0, 1.0);
    ballNode->setPosition(0, 20, 250);

    ballObject = new Ball(paddleObject);
    ballObject->setNode(ballNode);
    ballObject->SetMesh(sphereMesh);

    physicsObjects.push_back(paddleObject);
    physicsObjects.push_back(ballObject);
}
