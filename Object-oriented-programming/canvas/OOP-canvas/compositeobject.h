#ifndef COMPOSITEOBJECT_H
#define COMPOSITEOBJECT_H


#include "visibleobject.h"

#include <vector>
using std::vector;
using std::size_t;

class CompositeObject : public B_Object
{

private:
    vector <B_Object*> objects;

public:

    typedef vector<B_Object*>::iterator It;
    typedef vector<B_Object*>::const_iterator constIt;

    CompositeObject();
    ~CompositeObject();

    It  begin() { return this->objects.begin(); }
    It  end()   { return this->objects.end(); }

    constIt begin() const { return this->objects.begin(); }
    constIt end() const { return this->objects.end(); }

    bool add(B_Object* object);

    void deleteObjects();
    void change(const B_Modification& modif);

    B_Object*& operator[](int index);


    size_t size() const { return this->objects.size(); }
};
#endif // COMPOSITEOBJECT_H
