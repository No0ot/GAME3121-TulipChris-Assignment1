#include "Mesh.h"

MyMesh::MyMesh()
{
}

MyMesh::~MyMesh()
{
}

Ogre::ManualObject* MyMesh::createCubeMesh(Ogre::String name, Ogre::String matName)
{
    Ogre::ManualObject* cube = new Ogre::ManualObject(name);
    cube->begin(matName);

    cube->position(0.5, -0.5, 1.0); cube->colour(1, 0, 0); cube->textureCoord(1, 0);   //0
    cube->position(-0.5, -0.5, 0.0); cube->colour(1, 0, 0); cube->textureCoord(0, 1);  //1
    cube->position(0.5, -0.5, 0.0); cube->colour(1, 0, 0); cube->textureCoord(1, 1);    //2
    cube->position(-0.5, -0.5, 1.0); cube->colour(1, 0, 0); cube->textureCoord(0, 0);   //3
    cube->position(0.5, 0.5, 1.0); cube->colour(1, 0, 0); cube->textureCoord(1, 0);       //4
    cube->position(-0.5, -0.5, 1.0); cube->colour(1, 0, 0); cube->textureCoord(0, 1);   //5 
    cube->position(0.5, -0.5, 1.0); cube->colour(1, 0, 0); cube->textureCoord(1, 1);     //6
    cube->position(-0.5, 0.5, 1.0); cube->colour(1, 0, 0); cube->textureCoord(0, 0);     //7
    cube->position(-0.5, 0.5, 0.0); cube->colour(1, 0, 0); cube->textureCoord(0, 1);    //8
    cube->position(-0.5, -0.5, 0.0); cube->colour(1, 0, 0); cube->textureCoord(1, 1);  //9
    cube->position(-0.5, -0.5, 1.0); cube->colour(1, 0, 0); cube->textureCoord(1, 0);    //10
    cube->position(0.5, -0.5, 0.0); cube->colour(1, 0, 0); cube->textureCoord(0, 1);    //11
    cube->position(0.5, 0.5, 0.0); cube->colour(1, 0, 0); cube->textureCoord(1, 1);      //12
    cube->position(0.5, -0.5, 1.0); cube->colour(1, 0, 0); cube->textureCoord(0, 0);    //13
    cube->position(0.5, -0.5, 0.0); cube->colour(1, 0, 0); cube->textureCoord(1, 0);   //14
    cube->position(-0.5, -0.5, 0.0); cube->colour(1, 0, 0); cube->textureCoord(0, 0);   //15
    //TOP
    cube->position(-0.5, 0.5, 1.0); cube->colour(1, 0.5, 0); cube->textureCoord(1, 0);     //16
    cube->position(0.5, 0.5, 0.0); cube->colour(1, 0.5, 0); cube->textureCoord(0, 1);    //17
    cube->position(-0.5, 0.5, 0.0); cube->colour(1, 0.5, 0); cube->textureCoord(1, 1);   //18
    cube->position(0.5, 0.5, 1.0); cube->colour(1, 0.5, 0); cube->textureCoord(0, 0);      //19

    cube->triangle(0, 1, 2);		cube->triangle(3, 1, 0);
    cube->triangle(4, 5, 6);		cube->triangle(4, 7, 5);
    cube->triangle(8, 9, 10);		cube->triangle(10, 7, 8);
    cube->triangle(4, 11, 12);	cube->triangle(4, 13, 11);
    cube->triangle(14, 8, 12);	cube->triangle(14, 15, 8);
    cube->triangle(16, 17, 18);	cube->triangle(16, 19, 17);
    cube->end();

    return cube;
}
