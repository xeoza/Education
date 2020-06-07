#include "planner.h"

Planner::Planner() : loader(Loader()), drawer(Drawer()), modifier(Modifier()),keeper(Keeper())
{
    this->scene = nullptr;
}

Planner::~Planner()
{
    this->scene = nullptr;
}

void Planner::setCanvas(const CanvasStruct &canvas)
{
    if(!this->scene)
        throw E_NoScene();

    this->drawer.setCanvasStruct(canvas);
}

void Planner::addCamera(Camera &camera)
{
    if(!this->scene)
        throw E_NoScene();
    this->scene->addCamera(camera);
    this->keeper.incCameraIndex();
}

void Planner::addModel(const char *filename)
{
    if(!this->scene)
        throw E_NoScene();

    B_Object* obj = this->loader.loadObjects(filename);

    this->scene->addModel(obj);
    this->keeper.incModelIndex();

}

void Planner::drawModel()
{
    if(!this->scene)
        throw E_NoScene();

    if(!this->scene->modelsCount())
        throw E_ModelNotLoaded();

    if(!this->scene->viewersCount())
        throw E_NoViewers();

    this->drawer.drawScene(this->keeper, this->keeper.currentCamera());
}

void Planner::convertModel(ModifiyType type, double delta)
{
    if(!this->scene)
        throw E_NoScene();

    if(!this->scene->modelsCount())
        throw E_ModelNotLoaded();

    this->modifier.modifyObject(*this->keeper.currentModel(), type, delta);
}

void Planner::clearScene()
{
    if(!this->scene)
        throw E_NoScene();

    this->scene->clearScene();
}

void Planner::setScene(Scene *scene)
{
    this->scene = scene;
    this->keeper.setScene(this->scene);
}
