#ifndef VERTEXMODIFICATION_H
#define VERTEXMODIFICATION_H
#include "visiblemodification.h"

class VertexModification : public VisibleModification
{

protected:

    double delta;

public:
    VertexModification() : delta(0){}
    VertexModification(double d) : delta(d){}
    virtual ~VertexModification(){}

    void setDelta(double d)
    {
        this->delta = d;
    }

    double getDelta() const
    {
        return this->delta;
    }

    virtual void changeVertex(Vertex* const vertex) const = 0;


};

#endif // VERTEXMODIFICATION_H
