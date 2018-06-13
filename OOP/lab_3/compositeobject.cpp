#include "compositeobject.h"

CompositeObject::CompositeObject(){}

CompositeObject::~CompositeObject()
{
    this->deleteObjects();
}

bool CompositeObject::add(B_Object *object)
{
    if (object)
        this->objects.push_back(object);

    return true;
}

void CompositeObject::deleteObjects()
{
    for(B_Object* obj : this->objects)
        delete obj;

    this->objects.clear();
}

void CompositeObject::change(const B_Modification& modif)
{
    for (B_Object* obj : this->objects)
        obj->change(modif);

}

B_Object*& CompositeObject::operator[](int index)
{
    return this->objects[index];

}
