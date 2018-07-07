#ifndef B_PAINTER_H
#define B_PAINTER_H


#include "b_canvas.h"
#include "b_model.h"
#include "camera.h"

class B_Painter
{

public:

    virtual ~B_Painter(){}

    virtual void draw(B_Canvas& canvas, VisibleObject& object, const Camera& camera) = 0;

};

#endif // B_PAINTER_H
