#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>

#include "sourcemanager.h"
#include "fileerrors.h"
#include "memoryerrors.h"
#include "stdio.h"

class FileManager : public SourceManager
{
private:

    FILE* file;

    void openFile(const char* fileName);
    void closeFile();

    bool readModelsCount(unsigned int& count);
    bool readCount(unsigned int& count);
    bool readVertex(double& x, double& y, double& z);
    bool readLine(unsigned int& v1, unsigned int& v2);

    void readLines(Model* model);
    void readVertexes(Model* model);

    Model* readModel();

public:

    FileManager();
    ~FileManager(){}

    B_Object* createModel(const char* fileName);
};

#endif // FILEMANAGER_H
