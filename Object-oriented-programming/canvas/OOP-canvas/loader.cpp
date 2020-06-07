#include "loader.h"

Loader::Loader() : source ( new FileManager)
{

}

Loader::~Loader()
{
    delete source;
}

B_Object* Loader::loadObjects(const char *filename)
{
    return this->source->createModel(filename);
}
