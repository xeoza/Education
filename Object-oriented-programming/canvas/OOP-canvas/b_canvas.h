#ifndef B_CANVAS_H
#define B_CANVAS_H


class B_Canvas
{

public:

    virtual ~B_Canvas(){}

    virtual void clear() = 0;
    virtual void drawLine(double x1,  double y1, double x2, double y2) = 0;
    virtual void drawVertex(double x, double y) = 0;
    virtual bool canvasExists() const = 0;

};

#endif // B_CANVAS_H
