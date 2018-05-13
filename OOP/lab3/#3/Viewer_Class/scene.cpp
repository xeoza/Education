#include "scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
    this->clearScene();
}

void Scene::clearScene()
{
    this->objects.deleteObjects();
    this->cameras.clear();
}


void Scene::addCamera(Camera &camera)
{
    this->cameras.push_back(camera);
}


void Scene::addModel(B_Object *model)
{
    this->objects.add(model);


}

unsigned int Scene::modelsCount()
{
    return this->objects.size();
}

unsigned int Scene::viewersCount()
{
    return this->cameras.size();
}
