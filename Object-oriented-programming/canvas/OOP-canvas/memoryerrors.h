#ifndef E_MEMORY_H
#define E_MEMORY_H


#include "b_error.h"

class E_Memory : public B_Error
{
public:
    virtual const char* info()
    {
        return "Error of allocation of memory!";
    }
};

#endif // E_MEMORY_H
