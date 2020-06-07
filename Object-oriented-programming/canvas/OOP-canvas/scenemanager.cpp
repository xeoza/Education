#include "scenemanager.h"

SceneManager::SceneManager()
{
}

SceneManager::camera_iterator& SceneManager::currentCamera()
{
    return this->camera;
}

const SceneManager::camera_iterator& SceneManager::currentCamera() const
{
    return this->camera;
}

SceneManager::object_iterator& SceneManager::currentObject()
{
    return this->object;
}

const SceneManager::object_iterator& SceneManager::currentObject() const
{
    return this->object;
}
