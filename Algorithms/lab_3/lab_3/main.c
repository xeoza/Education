#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 0
#define INC_ARGV_DATA -1
#define FILE_ERR -2
#define MEMORY_ERR -3
#define INC_INP_DATA -4
#define FEW_POINTS -5

typedef struct spline_tuple splain_tuple_t;

struct spline_tuple
{
    double a, b, c, d;
};

int fscan_table(FILE *f_src, double **x, double **y, int *cn_p)
{
    int rc = OK;

    if (fscanf(f_src, "%d", cn_p) != 1)
        return INC_INP_DATA;

    //if (*cn_p < 3)
    //    return FEW_POINTS;

    double *x_t, *y_t;

    x_t = malloc(*cn_p * sizeof(double));

    if (x_t == NULL)
        return MEMORY_ERR;

    y_t = malloc(*cn_p * sizeof(double));

    if (y_t == NULL)
    {
        free(x_t);

        return MEMORY_ERR;
    }

    printf("%4s %5s\n", "X", "Y");
    for (int i = 0; i < *cn_p; i++)
        if (fscanf(f_src, "%lf %lf", &x_t[i], &y_t[i]) != 2)
        {
            free(x_t);
            free(y_t);

            return INC_INP_DATA;
        }
        else
            printf("%4.2lf %5.2lf\n", x_t[i], y_t[i]);
    printf("\n");
    
    *x = x_t;
    *y = y_t;

    return rc;
}

splain_tuple_t *build_splain(int n, double *x, double *y)
{
    splain_tuple_t *splains = calloc(n + 1, sizeof(splain_tuple_t));
    
    for (int i = 0; i < n + 1; i++)
        splains[i].a = y[i];
    
    double h[n + 1], l[n + 1];
    
    for (int k = 1; k < n + 1; k++)
    {
        h[k] = x[k] - x[k - 1];
        l[k] = (y[k] - y[k - 1]) / h[k];
    }
    
    double delta[n + 1], lambda[n + 1];
    
    delta[1] = -h[2] / (2 * (h[1] + h[2]));
    lambda[1] = 1.5 * (l[2] - l[1]) / (h[1] + h[2]);
    
    for (int k = 3; k < n + 1; k++)
    {
        delta[k - 1] = -h[k] / (2 * h[k - 1] + 2 * h[k] + h[k - 1] * delta[k - 2]);
        lambda[k - 1] = (3 * l[k] - 3 * l[k - 1] - h[k - 1] * lambda[k - 2]) /
                (2 * h[k - 1] + 2 * h[k] + h[k - 1] * delta[k - 2]);
    }
    
    splains[0].c = 0;
    splains[n].c = 0;
    
    for (int k = n; k >= 2; k--)
        splains[k - 1].c = delta[k - 1] * splains[k].c + lambda[k - 1];

    for (int k = 1; k < n + 1; k++)
    {
        splains[k].d = (splains[k].c - splains[k - 1].c) / (3 * h[k]);
        splains[k].b = l[k] + (2 * splains[k].c * h[k] + h[k] * splains[k - 1].c) / 3;
    }
    
    return splains;
}

double f(splain_tuple_t *splains, int n, double *x, double x_p)
{
    double res = 0;
    
    for (int k = 1; k < n + 1; k++)
        if (x_p >= x[k - 1] && x_p <= x[k])
        {
            res = splains[k].a + splains[k].b * (x_p - x[k]) + splains[k].c *
                    pow(x_p - x[k], 2) + splains[k].d * pow(x_p - x[k], 3);
            
            break;
        }
    
    return res;
}

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);

    int rc = OK;
    
    FILE *f_src;
    
    if (argc != 2)
    {
        printf("Inccorect argv data\n");
        
        return INC_ARGV_DATA;
    }
    
    f_src = fopen(argv[1], "r");
    
    if (!f_src)
    {
        printf("Can't open file\n");
        
        return FILE_ERR;
    }
    
    double *x = NULL, *y = NULL;
    int cn_p = 0;
    
    rc = fscan_table(f_src, &x, &y, &cn_p);

    fclose(f_src);
    
    if (rc != OK)
    {
        if (rc == INC_INP_DATA)
            printf("Inccorect input data\n");
        else if (rc == MEMORY_ERR)
            printf("Memory error\n");
        else if (rc == FEW_POINTS)
            printf("Count of points < 3\n");
        
        return rc;
    }
    
    splain_tuple_t *splines = build_splain(cn_p - 1, x, y);

    double x_p = 1, y_p = 0;
    printf("Input x: ");

    rc = scanf("%lf", &x_p);

    if (rc != 1)
        return INC_INP_DATA;
    else
        rc = OK;

    y_p = f(splines, cn_p - 1, x, x_p);

    printf("f(%.2lf) = %.5lf\n", x_p, y_p);

    printf("\nShow coeff? : [Y/n] ");
    char ch;

    scanf("%*c%c", &ch);

    if (ch == 'y' || ch == 'Y')
    {
        printf("\n%7s %7s %7s %7s\n", "A", "B", "C", "D");
        for (int i = 1; i < cn_p; i++)
            printf("%7.4lf %7.4lf %7.4lf %7.4lf\n", splines[i].a, splines[i].b,
                   splines[i].c, splines[i].d);
    }

    return rc;
}
