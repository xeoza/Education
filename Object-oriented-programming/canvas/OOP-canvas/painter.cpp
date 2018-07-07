#include "painter.h"
#include "matrix.h"

Painter::Painter(){}


void Painter::setCoordsForProection(std::vector<Vertex> &vertexeses, const Camera& cam)
{

    double dist = cam.getDistance();

    Matrix mat;
    Matrix::Set_Scale(mat, 10/dist);
    double vec[4];

    for(unsigned int i = 0; i < vertexeses.size(); i++)
    {
        vertexeses[i].getCoordVector(vec);
        mat *= vec;
        vertexeses[i].setCoordVector(vec);
    }
}

void Painter::drawLines(B_Canvas &canvas, B_Model& model)
{
    for(const Line& line : model.getLines())
    {
        const Vertex* start = line.getStart();
        const Vertex* end = line.getEnd();

        canvas.drawLine(start->get_X(), start->get_Y(), end->get_X(), end->get_Y());
    }
}


void Painter::draw(B_Canvas &canvas, VisibleObject &object, const Camera& cam)
{
        B_Model& model = (B_Model&)(object);

        std::vector<Vertex> tmpPoints = model.getVertexes();

        this->setCoordsForProection(model.getVertexes(), cam);

        this->drawLines(canvas, model);

        model.getVertexes() = tmpPoints;
}
