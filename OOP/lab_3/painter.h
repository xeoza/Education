#ifndef PAINTER_H
#define PAINTER_H

#include "b_painter.h"

class Painter : public B_Painter
{

private:

    void setCoordsForProection(std::vector<Vertex>& vertexeses, const Camera& cam);
    void drawLines(B_Canvas& canvas, B_Model& model);

public:

    Painter();
    ~Painter(){}

    void draw(B_Canvas& canvas, VisibleObject& object, const Camera& cam);
};

#endif // PAINTER_H
