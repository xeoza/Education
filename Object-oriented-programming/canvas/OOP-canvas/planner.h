#ifndef PLANNER_H
#define PLANNER_H

#include "scene.h"
#include "loader.h"
#include "drawer.h"
#include "mainwindow.h"
#include "camera.h"
#include "canvas.h"
#include "modifier.h"
#include "QDebug"
#include "keeper.h"


class Planner
{

private:

    Scene* scene;
    Loader loader;
    Drawer drawer;
    Modifier modifier;
    Keeper keeper;

public:

    Planner();
    ~Planner();
    void setCanvas(const CanvasStruct& canvas);

    void addCamera(Camera& camera);
    void addModel(const char* filename);
    void drawModel();

    void convertModel(ModifiyType type, double delta);
    void clearScene();

    void setScene(Scene *scene);

};

#endif // PLANNER_H
