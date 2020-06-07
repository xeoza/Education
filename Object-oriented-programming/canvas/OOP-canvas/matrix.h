#ifndef MATRIX_H
#define MATRIX_H


#include "math.h"

class Matrix
{

private:

    double matrix[4][4];

public:

    Matrix();

    void operator *= (double vec[4]) const;

    static void Set_RotateX(Matrix& mat, double d);
    static void Set_RotateY(Matrix& mat, double d);
    static void Set_RotateZ(Matrix& mat, double d);
    static void Set_Scale  (Matrix& mat, double d);

};

#endif // MATRIX_H
