#include "modifier.h"

Modifier::Modifier()
{

}

B_Modification* Modifier::getModify(ModifiyType type)
{
    B_Modification* mod = 0;

    switch(type)
    {
        case ROTATEX:
        {
            mod = new RotateX;
            break;
        }
        case ROTATEY:
        {
            mod = new RotateY;
            break;
        }
        case ROTATEZ:
        {
            mod = new RotateZ;
            break;
        }
        case SCALE:
        {
            mod = new Scale;

            break;
        }
        case CAMERA_MOVE:
        {
            mod = new CameraMove;
            break;
        }
        default:
            break;
    }

    return mod;
}



void Modifier::modifyObject(B_Object& object, ModifiyType type, double delta)
{
    B_Modification* modif = this->getModify(type);

    if(!modif)
        throw E_UndefinedType();

    modif->setDelta(delta);

    object.change(*modif);

    delete modif;
}

