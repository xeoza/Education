#ifndef MODEL_H
#define MODEL_H

#include <QObject>

#include "b_model.h"
#include "line.h"

class Model : public B_Model
{

private:

    vector<Vertex> vertexes;
    vector<Line> lines;

public:

    Model();
    Model(const Model&);
    ~Model();
    Model& operator=(const Model&);

    size_t vertexesCount() const {return this->vertexes.size();}
    size_t linesCount()  const   {return this->lines.size();}

    void addVertex(Vertex& v);
    void addVertex(double x, double y, double z);
    void addLine(Line& line);
    void addLine(Vertex* start, Vertex* end);

    vector<Line>& getLines();
    vector<Vertex>& getVertexes();

    const vector<Line>& getLines() const;
    const vector<Vertex>& getVertexes() const;

    virtual void change(const B_Modification& modif);
};

#endif // MODEL_H
