#include "matrix.h"

Matrix::Matrix()
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            this->matrix[i][j] = 0;
}

void Matrix::Set_RotateX(Matrix &mat, double d)
{
    mat.matrix[0][0] = 1; mat.matrix[0][1] = 0;       mat.matrix[0][2] = 0;      mat.matrix[0][3] = 0;
    mat.matrix[1][0] = 0; mat.matrix[1][1] = cos(d);  mat.matrix[1][2] = sin(d); mat.matrix[1][3] = 0;
    mat.matrix[2][0] = 0; mat.matrix[2][1] = -sin(d); mat.matrix[2][2] = cos(d); mat.matrix[2][3] = 0;
    mat.matrix[3][0] = 0; mat.matrix[3][1] = 0;       mat.matrix[3][2] = 0;     mat.matrix[3][3] = 1;
}

void Matrix::Set_RotateY(Matrix &mat, double d)
{
    mat.matrix[0][0] = cos(d);  mat.matrix[0][1] = 0;  mat.matrix[0][2] = sin(d); mat.matrix[0][3] = 0;
    mat.matrix[1][0] = 0;       mat.matrix[1][1] = 1;  mat.matrix[1][2] = 0;      mat.matrix[1][3] = 0;
    mat.matrix[2][0] = -sin(d); mat.matrix[2][1] = 0;  mat.matrix[2][2] = cos(d); mat.matrix[2][3] = 0;
    mat.matrix[3][0] = 0;       mat.matrix[3][1] = 0;  mat.matrix[3][2] = 0;      mat.matrix[3][3] = 1;
}

void Matrix::Set_RotateZ(Matrix &mat, double d)
{
    mat.matrix[0][0] = cos(d);  mat.matrix[0][1] = sin(d);  mat.matrix[0][2] = 0; mat.matrix[0][3] = 0;
    mat.matrix[1][0] = -sin(d); mat.matrix[1][1] = cos(d);  mat.matrix[1][2] = 0; mat.matrix[1][3] = 0;
    mat.matrix[2][0] = 0;       mat.matrix[2][1] = 0;       mat.matrix[2][2] = 1; mat.matrix[2][3] = 0;
    mat.matrix[3][0] = 0;       mat.matrix[3][1] = 0;       mat.matrix[3][2] = 0; mat.matrix[3][3] = 1;
}

void Matrix::Set_Scale(Matrix &mat, double d)
{
    mat.matrix[0][0] = d;  mat.matrix[0][1] = 0;  mat.matrix[0][2] = 0; mat.matrix[0][3] = 0;
    mat.matrix[1][0] = 0;  mat.matrix[1][1] = d;  mat.matrix[1][2] = 0; mat.matrix[1][3] = 0;
    mat.matrix[2][0] = 0;  mat.matrix[2][1] = 0;  mat.matrix[2][2] = d; mat.matrix[2][3] = 0;
    mat.matrix[3][0] = 0;  mat.matrix[3][1] = 0;  mat.matrix[3][2] = 0; mat.matrix[3][3] = 1;
}


void Matrix::operator *=(double vec[4]) const
{
    double tmp[4];

    for(int i = 0; i < 4; i++)
    {
        tmp[i] = vec[i];
        vec[i] = 0;
    }

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            vec[i] += this->matrix[i][j] * tmp[j];

}
