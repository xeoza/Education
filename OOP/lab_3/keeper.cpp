#include "keeper.h"

Keeper::Keeper(): scene(0), camIndex(0), modIndex(0)
{

}

void Keeper::setScene(Scene *_scene)
{
    this->scene = _scene;
}

void Keeper::incCameraIndex()
{
    this->camIndex++;
}

B_Object*& Keeper::currentModel()
{
    return this->scene->objects[this->modIndex-1];
}

Camera& Keeper::currentCamera()
{
    return this->scene->cameras[this->camIndex-1];
}

CompositeObject::It Keeper::objectsBegin()
{
    return this->scene->objects.begin();
}

CompositeObject::It Keeper::objectsEnd()
{
    return this->scene->objects.end();

}

void Keeper::incModelIndex()
{
    this->modIndex++;
}
