#ifndef DRAWER_H
#define DRAWER_H

#include "b_manager.h"
#include "canvas.h"
#include "painter.h"
#include "compositeobject.h"
#include "keeper.h"

class Drawer : public B_Manager
{
private:

    B_Canvas *canvas;
    B_Painter *painter;

    void drawObject(B_Object &object, const Camera &camera);
    void drawObject(CompositeObject &cobject, const Camera &camera);

public:
    Drawer();
    ~Drawer();

    void setCanvasStruct(const CanvasStruct& can);
    void drawScene(Keeper &keeper, Camera& camera);
};

#endif // DRAWER_H
