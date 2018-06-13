#ifndef LOADER_H
#define LOADER_H

#include "filemanager.h"
#include "b_manager.h"

class Loader : public B_Manager
{
private:

    SourceManager* source;

public:

    Loader();
    ~Loader();

    B_Object* loadObjects(const char* filename);

};

#endif // LOADER_H
