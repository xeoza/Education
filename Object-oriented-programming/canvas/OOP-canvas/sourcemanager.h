#ifndef SOURCEMANAGER_H
#define SOURCEMANAGER_H

#include "model.h"
#include "compositeobject.h"

class SourceManager
{

public:
    virtual ~SourceManager(){}
    virtual B_Object* createModel(const char* fileName) = 0;

};

#endif // SOURCEMANAGER_H
