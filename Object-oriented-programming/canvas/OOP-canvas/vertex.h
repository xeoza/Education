#ifndef VERTEX_H
#define VERTEX_H


#include "visibleobject.h"


class VisibleModification;

class Vertex : public VisibleObject
{

private:

    double x;
    double y;
    double z;

public:
    Vertex(double, double, double);
    Vertex(const Vertex&);
    Vertex& operator=(const Vertex&);

    ~Vertex();

    const double& get_X() const;
    const double& get_Y() const;
    const double& get_Z() const;

    void set_X(double);
    void set_Y(double);
    void set_Z(double);

    void getCoordVector(double vec[4]) const;
    void setCoordVector(double vec[4]);

    virtual void change(const B_Modification &modif);
};

#endif // VERTEX_H
