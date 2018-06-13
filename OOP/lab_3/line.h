#ifndef LINE_H
#define LINE_H

#include "visibleobject.h"
#include "vertex.h"

class Line : public VisibleObject
{

private:

    Vertex* v1;
    Vertex* v2;

public:

    Line();
    Line(Vertex*, Vertex*);

    ~Line();

    const Vertex* getStart() const;
    const Vertex* getEnd() const;

    void setStart(Vertex*);
    void setEnd(Vertex*);

    virtual void change(const B_Modification&);
};

#endif // LINE_H
