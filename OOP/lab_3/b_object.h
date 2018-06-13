#ifndef B_OBJECT_H
#define B_OBJECT_H


#include "b_modification.h"

class B_Object
{
public:

    virtual ~B_Object(){}

    virtual bool add(B_Object*) {return false;}
    virtual void change(const B_Modification& modif) = 0;
};

#endif // B_OBJECT_H
