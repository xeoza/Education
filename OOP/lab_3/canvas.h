#ifndef CANVAS_H
#define CANVAS_H


#include "b_canvas.h"
#include "canvaserrors.h"
#include "model.h"
#include <QGraphicsScene>

struct CanvasStruct
{
    QGraphicsScene* scene;
    QPen pen;
};

class Canvas : public B_Canvas
{

private:
    CanvasStruct canvas;

public:
    Canvas();
    ~Canvas();

    void setCanvas(const CanvasStruct&);
    void setCanvas(QGraphicsScene* , QPen);

    void clear();
    void drawLine(double x1, double y1, double x2, double y2);
    void drawVertex(double x, double y);

    bool canvasExists() const;
};

#endif // CANVAS_H
