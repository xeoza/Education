#ifndef ROTATEX_H
#define ROTATEX_H

#include "vertexmodification.h"

class RotateX : public VertexModification
{
public:
    RotateX() : VertexModification() {}

    RotateX(double d) : VertexModification(d) {}

    ~RotateX() {this->delta = 0;}

    void changeVertex(Vertex* const vertex) const;
};


class RotateY : public VertexModification
{
public:
    RotateY() : VertexModification() {}

    RotateY(double d) : VertexModification(d) {}

    ~RotateY() {this->delta = 0;}

    void changeVertex(Vertex* const vertex) const;
};

class RotateZ : public VertexModification
{
public:
    RotateZ() : VertexModification() {}

    RotateZ(double d) : VertexModification(d) {}

    ~RotateZ() {this->delta = 0;}

    void changeVertex(Vertex* const vertex) const;
};

class Scale : public VertexModification
{
public:
    Scale() : VertexModification() {}

    Scale(double d) : VertexModification(d) {}

    ~Scale() {this->delta = 0;}

    void changeVertex(Vertex* const vertex) const;
};
#endif // ROTATEX_H
