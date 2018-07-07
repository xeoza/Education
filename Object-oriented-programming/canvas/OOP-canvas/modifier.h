#ifndef MODIFIER_H
#define MODIFIER_H

#include "vertexmodifications.h"
#include "cameramodifications.h"
#include "b_error.h"

enum ModifiyType{

    ROTATEX,
    ROTATEY,
    ROTATEZ,

    SCALE,

    CAMERA_MOVE
};


class E_UndefinedType : public B_Error
{
public:
    virtual const char* info()
    {
        return "Undefined type of change!";
    }
};

class Modifier
{
private:

    B_Modification* getModify(ModifiyType type);

public:

    Modifier();

    void modifyObject(B_Object &object, ModifiyType type, double delta);
};

#endif // MODIFIER_H
