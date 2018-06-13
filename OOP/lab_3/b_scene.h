#ifndef B_SCENE_H
#define B_SCENE_H

#include "filemanager.h"
#include "model.h"
#include "canvas.h"
#include "b_modification.h"
#include "sceneerrors.h"
#include "camera.h"

class B_Scene
{

public:

    virtual ~B_Scene(){}
    virtual void clearScene()                = 0;

    virtual void addCamera(Camera& camera)   = 0;
    virtual void addModel(B_Object* model)   = 0;

    virtual unsigned int modelsCount()       = 0;
    virtual unsigned int viewersCount()      = 0;
};

#endif // B_SCENE_H
