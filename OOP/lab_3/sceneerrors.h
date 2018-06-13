#ifndef SCENEERRORS_H
#define SCENEERRORS_H


#include "b_error.h"

class E_ModelNotLoaded : public B_Error
{
public:
    virtual const char* info()
    {
        return "Model not loaded!";
    }
};


class E_NoViewers : public B_Error
{
public:
    virtual const char* info()
    {
        return "No viewers on the scene!";
    }
};

class E_NoScene : public B_Error
{
public:
    virtual const char* info()
    {
        return "No Scene!";
    }
};

#endif // SCENEERRORS_H
