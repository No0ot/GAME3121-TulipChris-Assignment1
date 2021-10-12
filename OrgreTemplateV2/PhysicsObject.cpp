#include "PhysicsObject.h"

PhysicsObject::PhysicsObject()
{
	
}

void PhysicsObject::update(const Ogre::FrameEvent& evt)
{
}

Ogre::SceneNode* PhysicsObject::getNode()
{
	return node;
}

void PhysicsObject::setNode(Ogre::SceneNode* newnode)
{
	node = newnode;
}

const String& PhysicsObject::getMovableType(void) const
{
	// TODO: insert return statement here
	return "Physics Object";
}

const AxisAlignedBox& PhysicsObject::getBoundingBox(void) const
{
	// TODO: insert return statement here
	return AxisAlignedBox();
}

Real PhysicsObject::getBoundingRadius(void) const
{
	return Real();
}

void PhysicsObject::_updateRenderQueue(RenderQueue* queue)
{
}

void PhysicsObject::visitRenderables(Renderable::Visitor* visitor, bool debugRenderables)
{
}

PhysicsObject::~PhysicsObject()
{

}
