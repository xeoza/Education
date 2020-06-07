#include "canvas.h"

Canvas::Canvas()
{

}

Canvas::~Canvas()
{
    this->clear();
    this->canvas.scene = nullptr;
}

void Canvas::setCanvas(const CanvasStruct &c)
{
    this->canvas.scene = c.scene;
    this->canvas.pen = c.pen;
}

void Canvas::setCanvas(QGraphicsScene *s, QPen p)
{
    this->canvas.scene = s;
    this->canvas.pen = p;
}

void Canvas::clear()
{
    if(!this->canvas.scene)
        throw E_NoCanvas();

    this->canvas.scene->clear();

}

void Canvas::drawLine(double x1, double y1, double x2, double y2)
{
    if(!this->canvas.scene)
        throw E_NoCanvas();

    this->canvas.scene->addLine(x1, y1, x2, y2, this->canvas.pen);
}

void Canvas::drawVertex(double x, double y)
{
    if(!this->canvas.scene)
        throw E_NoCanvas();

    this->canvas.scene->addLine(x, y, x, y, this->canvas.pen);
}

bool Canvas::canvasExists() const
{
    return this->canvas.scene != nullptr;
}
