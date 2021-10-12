#pragma once
#include "Ogre.h"

using namespace Ogre;


class PhysicsObject : public Ogre::MovableObject
{
private:
	Ogre::SceneNode* node;

    float moveSpeed;
    Ogre::Vector3 velocity;
public:
    PhysicsObject();
    ~PhysicsObject();

    void update(const Ogre::FrameEvent& evt); virtual

    Ogre::SceneNode* getNode();
    void setNode(Ogre::SceneNode* newnode);

    //Inherited functions from MovableObject

    /** @copydoc MovableObject::getMovableType */
    const String& getMovableType(void) const;
    /** @copydoc MovableObject::getBoundingBox */
    const AxisAlignedBox& getBoundingBox(void) const;
    /** @copydoc MovableObject::getBoundingRadius */
    Real getBoundingRadius(void) const;
    /** @copydoc MovableObject::_updateRenderQueue */
    void _updateRenderQueue(RenderQueue* queue);
    /// @copydoc MovableObject::visitRenderables
    void visitRenderables(Renderable::Visitor* visitor,
        bool debugRenderables = false);

};

class PhysicsFrameListener : public Ogre::FrameListener
{
private:
    std::vector<PhysicsObject*> physicsObjects;
public:

    PhysicsFrameListener(std::vector<PhysicsObject*> physicsobjects)
    {
        for (auto objects : physicsobjects)
        {
            physicsObjects.push_back(objects);
        }
    }

    bool frameStarted(const Ogre::FrameEvent& evt)
    {
        for (auto objects : physicsObjects)
        {
            objects->update(evt);
        }
        return true;
    }
};

