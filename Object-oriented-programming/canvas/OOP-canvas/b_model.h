#ifndef B_MODEL_H
#define B_MODEL_H

#include "visibleobject.h"
#include "line.h"

#include "stdio.h"

#include <vector>
using::std::vector;

class B_Model : public VisibleObject
{
public:

    virtual ~B_Model(){}

    virtual size_t vertexesCount() const                  = 0;
    virtual size_t linesCount()  const                    = 0;

    virtual void addVertex(Vertex& v)                     = 0;
    virtual void addVertex(double x, double y, double z)  = 0;
    virtual void addLine(Line& line)                      = 0;
    virtual void addLine(Vertex* start, Vertex* end)      = 0;

    virtual vector<Line>& getLines()                      = 0;
    virtual vector<Vertex>& getVertexes()                 = 0;

    virtual void change(const B_Modification& modif) = 0;
};

#endif // B_MODEL_H
