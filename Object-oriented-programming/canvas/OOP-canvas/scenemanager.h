#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "b_manager.h"
#include "camera.h"
#include "compositeobject.h"

class SceneManager : public B_Manager
{
public:

    SceneManager();

    typedef vector<Camera>::iterator camera_iterator;
    typedef CompositeObject::It object_iterator;

    camera_iterator& currentCamera();
    const camera_iterator& currentCamera() const;

    object_iterator& currentObject();
    const object_iterator& currentObject() const;

private:

    camera_iterator camera;
    object_iterator object;
};

#endif // SCENEMANAGER_H
