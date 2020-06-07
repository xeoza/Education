#include "line.h"

Line::Line() : v1(0), v2(0)
{
}

Line::Line(Vertex* _v1, Vertex* _v2)
    : v1(_v1), v2(_v2)
{

}

Line::~Line()
{
    this->v1 = nullptr;
    this->v2 = nullptr;
}

const Vertex* Line::getStart() const
{
    return this->v1;
}

const Vertex* Line::getEnd() const
{
    return this->v2;
}

void Line::setStart(Vertex* start)
{
    this->v1 = start;
}

void Line::setEnd(Vertex* end)
{
    this->v2 = end;
}

void Line::change(const B_Modification& modif)
{

    this->v1->change(modif);
    this->v2->change(modif);

}
