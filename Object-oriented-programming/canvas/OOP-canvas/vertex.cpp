#include "vertex.h"
#include "vertexmodification.h"

Vertex::Vertex(double _x, double _y, double _z) : x(_x), y(_y), z(_z)
{
}

Vertex::Vertex(const Vertex& v) : x(v.x), y(v.y), z(v.z)
{
}


Vertex& Vertex::operator=(const Vertex &v)
{
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;

    return *this;
}

Vertex::~Vertex()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}


void Vertex::change(const B_Modification& modif)
{

   ((const VertexModification&)modif).changeVertex(this);
}


void Vertex::getCoordVector(double vec[4]) const
{
    vec[0] = this->x;
    vec[1] = this->y;
    vec[2] = this->z;
    vec[3] = 1;

}

void Vertex::setCoordVector(double vec[4])
{
    this->x = vec[0];
    this->y = vec[1];
    this->z = vec[2];
}


const double &Vertex::get_X() const
{
    return this->x;
}

const double &Vertex::get_Y() const
{
    return this->y;
}

const double &Vertex::get_Z() const
{
    return this->z;
}

void Vertex::set_X(double x)
{
    this->x = x;
}

void Vertex::set_Y(double y)
{
    this->y = y;
}

void Vertex::set_Z(double z)
{
    this->z = z;
}
