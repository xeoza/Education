#include "model.h"

Model::Model()
{

}

Model::Model(const Model& model)
{
    this->vertexes = model.vertexes;
    this->lines = model.lines;
}

Model::~Model()
{
    if(this->vertexesCount())
        this->vertexes.clear();

    if(this->linesCount())
        this->lines.clear();
}

Model& Model::operator=(const Model& model)
{
    this->vertexes = model.vertexes;
    this->lines = model.lines;

    return *this;
}


vector<Vertex>& Model::getVertexes()
{
    return this->vertexes;
}

vector<Line>& Model::getLines()
{
    return this->lines;
}

const vector<Vertex>& Model::getVertexes() const
{
    return this->vertexes;
}

const vector<Line>& Model::getLines() const
{
    return this->lines;
}

void Model::addVertex(Vertex& v)
{
    this->vertexes.push_back(v);
}

void Model::addVertex(double x, double y, double z)
{
    this->vertexes.push_back(Vertex(x, y, z));
}

void Model::addLine(Line& line)
{
    this->lines.push_back(line);
}

void Model::addLine(Vertex* start, Vertex* end)
{
    this->lines.push_back(Line(start, end));
}

void Model::change(const B_Modification& modif)
{
    for (Vertex& v : this->vertexes)
        v.change(modif);
}

