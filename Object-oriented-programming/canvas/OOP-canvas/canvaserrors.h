#ifndef E_NOCANVAS_H
#define E_NOCANVAS_H

#include "b_error.h"

class E_NoCanvas : public B_Error
{
public:
    virtual const char* info()
    {
        return "No canvas to draw!";
    }
};

#endif // E_NOCANVAS_H
