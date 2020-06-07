#include "vertexmodifications.h"

void RotateX::changeVertex(Vertex * const vertex) const
{
    Matrix mat;

    double alpha = VisibleModification::radiansToDegree(this->delta);
    Matrix::Set_RotateX(mat, alpha);

    double vec[4];

    vertex->getCoordVector(vec);
    mat *= vec;
    vertex->setCoordVector(vec);
}

void RotateY::changeVertex(Vertex * const vertex) const
{
    Matrix mat;

    double alpha = VisibleModification::radiansToDegree(this->delta);
    Matrix::Set_RotateY(mat, alpha);

    double vec[4];

    vertex->getCoordVector(vec);
    mat *= vec;
    vertex->setCoordVector(vec);
}

void RotateZ::changeVertex(Vertex * const vertex) const
{
    Matrix mat;

    double alpha = VisibleModification::radiansToDegree(this->delta);
    Matrix::Set_RotateZ(mat, alpha);

    double vec[4];

    vertex->getCoordVector(vec);
    mat *= vec;
    vertex->setCoordVector(vec);
}

void Scale::changeVertex(Vertex * const vertex) const
{
    Matrix mat;

    Matrix::Set_Scale(mat, this->delta);

    double vec[4];

    vertex->getCoordVector(vec);
    mat *= vec;
    vertex->setCoordVector(vec);
}
