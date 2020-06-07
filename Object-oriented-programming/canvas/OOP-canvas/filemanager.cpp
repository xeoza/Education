#include "filemanager.h"

FileManager::FileManager() : file(NULL)
{}


void FileManager::openFile(const char *fileName)
{
    if ((this->file = fopen(fileName, "r")) == NULL)
            throw E_OpenFile();
}


void FileManager::closeFile()
{
    fclose(this->file);
}

bool FileManager::readCount(unsigned int& count)
{
    return  ((fscanf (this->file, "%u:", &count)) == 1);
}

bool FileManager::readVertex(double& x, double& y, double& z)
{
    return ((fscanf (this->file, "%lf %lf %lf", &x, &y, &z)) == 3);
}


bool FileManager::readLine(unsigned int& v1, unsigned int& v2)
{
    return ((fscanf (file, "%u %u", &v1, &v2)) == 2);
}

bool FileManager::readModelsCount(unsigned int &count)
{
    return  ((fscanf (this->file, "(%u)", &count)) == 1);
}

void FileManager::readVertexes(Model *model)
{
    unsigned int count;

    if(!this->readCount(count))
        throw E_ReadFile();

    double x, y, z;

    unsigned int i;
    for (i = 0; i < count && readVertex(x, y, z); i++)
    {
        model->addVertex(x, y, z);
    }

    if(i < count)
        throw  E_ReadFile();
}

void FileManager::readLines(Model *model)
{
    unsigned int count;

    if(!this->readCount(count))
        throw E_ReadFile();

    unsigned int v1, v2;
    unsigned int vertexesCount = model->vertexesCount();

    unsigned int i;
    for (i = 0; i < count             &&
                readLine(v1,v2)       &&
                v1 - 1 <  vertexesCount  &&
                v2 - 1 <  vertexesCount; i++)
    {
        model->addLine(&(model->getVertexes()[v1 - 1]), &(model->getVertexes()[v2 - 1]));
    }

    if(i < count)
        throw E_ReadFile();

}


Model* FileManager::readModel()
{
    Model* model = new Model();

    if(!model)
        throw E_Memory();

    this->readVertexes(model);
    this->readLines(model);

    return model;
}


B_Object* FileManager::createModel(const char *fileName)
{

    this->openFile(fileName);

    unsigned int count;

    if(!this->readModelsCount(count))
    {
        this->closeFile();
        throw E_ReadFile();
    }

    if(count == 1)
    {
        B_Object* object = nullptr;
        try
        {
            object = this->readModel();

        }
        catch(B_Error& err)
        {
            delete object;
            this->closeFile();

            throw;
        }

        return object;
    }


    CompositeObject* cobject = new CompositeObject;

    if(!cobject)
    {
        this->closeFile();
        throw E_Memory();
    }

    try
    {
        for(unsigned i = 0; i < count; i++)
        {
            cobject->add(this->readModel());
        }
    }
    catch(B_Error& err)
    {
        cobject->deleteObjects();
        delete cobject;

        this->closeFile();

        throw;
    }

    this->closeFile();

    return cobject;
}
