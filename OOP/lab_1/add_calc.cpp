#include "planner.h"
#include "actions.h"
#include "drawing.h"
#include "calculation.h"
#include "add_calc.h"

/*        Начало блока преобразований        */
enum Err matrix_mult(double **a, double *b, double *c, int n)
{
    enum Err err=Fine;
    for (int i = 0; i < n; i++)
    {
        if (i >= n)
            err = memorErr;
        for (int j = 0; j < n; j++)
        {
            if (j >= n)
                err = memorErr;
            c[i] = c[i] + b[j] * a[j][i];
        }
    }
    return err;
}
double gradtorad(double x)
{
    return x * PI/ 180;
}
/*        Конец блока преобразований        */
