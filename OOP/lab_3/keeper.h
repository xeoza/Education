#ifndef KEEPER_H
#define KEEPER_H
#include "scene.h"
#include "b_manager.h"

class Keeper : public B_Manager
{

private:

    Scene *scene;
    int camIndex;
    int modIndex;

public:
    Keeper();

    void setScene(Scene* _scene);

    void incModelIndex();
    void incCameraIndex();

    B_Object*& currentModel();
    Camera& currentCamera();

    CompositeObject::It objectsBegin();
    CompositeObject::It objectsEnd();
};

#endif // KEEPER_H
