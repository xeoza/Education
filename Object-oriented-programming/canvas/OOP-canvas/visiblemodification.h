#ifndef VISIBLEMODIFICATION_H
#define VISIBLEMODIFICATION_H


#include "b_modification.h"
#include "vertex.h"

class VisibleModification : public B_Modification
{

public:


    virtual ~VisibleModification(){}

    static double radiansToDegree(double);

};

#endif // VISIBLEMODIFICATION_H
