#ifndef SCENE_H
#define SCENE_H


#include "compositeobject.h"
#include "camera.h"
#include "filemanager.h"
#include "model.h"
#include "canvas.h"
#include "b_modification.h"
#include "sceneerrors.h"


class Scene
{

private:

    CompositeObject objects;
    vector<Camera> cameras;

public:

    friend class Keeper;
    Scene();
    ~Scene();

    void  addCamera(Camera& camera);
    void addModel(B_Object* model);

    unsigned int modelsCount();
    unsigned int viewersCount();

    void clearScene();
};

#endif // SCENE_H
