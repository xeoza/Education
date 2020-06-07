#include "drawer.h"

#include "drawer.h"

Drawer::Drawer() : canvas(new Canvas), painter(new Painter)
{
}

Drawer::~Drawer()
{
    delete painter;
    delete canvas;
}

void Drawer::setCanvasStruct(const CanvasStruct& can)
{
    ((Canvas*)(this->canvas))->setCanvas(can);
}

void Drawer::drawObject(B_Object &object, const Camera &camera)
{

    this->painter->draw(*this->canvas, (VisibleObject&)(object), camera);
}

void Drawer::drawObject(CompositeObject &cobject, const Camera &camera)
{
    for (CompositeObject::constIt it = cobject.begin(), end = cobject.end();
                                        it != end; it++)
    {
        this->painter->draw(*this->canvas, (VisibleObject&)(**it), camera);
    }
}


void Drawer::drawScene(Keeper& keeper, Camera& camera)
{
    this->canvas->clear();

    for (CompositeObject::It it = keeper.objectsBegin(), end = keeper.objectsEnd();
         it != end; it++)
    {
        if((*it)->add(nullptr))
            this->drawObject((**it), camera);
        else
            this->drawObject(**it, camera);

    }

}
