#include "planner.h"
#include "actions.h"
#include "drawing.h"
#include "calculation.h"
#include "add_calc.h"
#include <stdio.h>
/*       Начало блока преобразований    */

enum Err get_matrix(struct Conv *m,int n)
{
    Err err = Fine;
    m->a = (double **)malloc(n * sizeof(double*));
    if (!m->a)
        err = memorErr;
    for(int i = 0; i < n; i++)
    {
        m->a[i]=(double *)malloc(n*sizeof(double));
        if (!m->a[i])
            err = memorErr;
    }
    if (err != Fine)
    {
        for(int i = 0; i < n; i++)
        {
            free(m->a[i]);
        }
        free(m->a);
    }
    return err;
}

enum Err get_vectors(struct Conv *m,int n)
{
    Err err = Fine;
    m->b = (double *)malloc(n * sizeof(double));
    if (!m->b)
        err = memorErr;
    m->c = (double *)malloc(n * sizeof(double));
    if (!m->c)
        err = memorErr;

    return err;
}


void init_OX(double **a,double angle)
{
    a[0][0]=1;
    a[0][1]=0;
    a[0][2]=0;
    a[0][3]=0;

    a[1][0]=0;
    a[1][1]=cos(gradtorad(angle));
    a[1][2]=sin(gradtorad(angle));
    a[1][3]=0;

    a[2][0]=0;
    a[2][1]=-sin(gradtorad(angle));
    a[2][2]=cos(gradtorad(angle));
    a[2][3]=0;

    a[3][0]=0;
    a[3][1]=0;
    a[3][2]=0;
    a[3][3]=1;
    return ;
}

void init_OY(double **a,double angle)
{
    a[0][0]=cos(gradtorad(angle));
    a[0][1]=0;
    a[0][2]=-sin(gradtorad(angle));
    a[0][3]=0;

    a[1][0]=0;
    a[1][1]=1;
    a[1][2]=0;
    a[1][3]=0;

    a[2][0]=sin(gradtorad(angle));
    a[2][1]=0;
    a[2][2]=cos(gradtorad(angle));
    a[2][3]=0;

    a[3][0]=0;
    a[3][1]=0;
    a[3][2]=0;
    a[3][3]=1;
    return ;
}

void init_OZ(double **a,double angle)
{
    a[0][0]=cos(gradtorad(angle));
    a[0][1]=sin(gradtorad(angle));
    a[0][2]=0;
    a[0][3]=0;

    a[1][0]=-sin(gradtorad(angle));
    a[1][1]=cos(gradtorad(angle));
    a[1][2]=0;
    a[1][3]=0;

    a[2][0]=0;
    a[2][1]=0;
    a[2][2]=1;
    a[2][3]=0;

    a[3][0]=0;
    a[3][1]=0;
    a[3][2]=0;
    a[3][3]=1;
    return ;
}
void init_point(double *c,struct Point p)
{
    c[0]=p.x;
    c[1]=p.y;
    c[2]=p.z;
    c[3]=1;
    return ;
}

enum Err convert_point(struct Point *p,double **b,double *c,double *d)
{
    d[0]=0;
    d[1]=0;
    d[2]=0;
    d[3]=0;
    Err err = matrix_mult(b,c,d,4);
    if (err == Fine)
    {
        p->x=d[0];
        p->y=d[1];
        p->z=d[2];
    }
    return err;
}

/*       Конец блока преобразований    */

/*       Начало блока загрузки    */


enum Err try_load_num_points(FILE **f,int *n)
{
    int m;
    Err err = Fine;

    if (fscanf(*f, "%d\n", &m) != 1)
        err = corrupted;

    if (m<=0)
        err = corrupted;

    *n = m;
    return err;
}
enum Err allocate_mem_points(struct PointList points)
{
    Err err = Fine;
    points.list = (struct Point *)malloc(points.count * sizeof(struct Point));
    if (!points.list)
        err = memorErr;

    return err;
}
void free_mem_points(struct PointList points)
{
    free(points.list);
}

enum Err try_load_point(FILE *f,struct Point *point)
{
    Err err = Fine;
    if (!fscanf(f, "%lf%lf%lf\n", &point->x, &point->y, &point->z))
        err = corrupted;

    return err;
}
enum Err try_load_num_lines(FILE **f,int *n)
{
    int m;
    Err err = Fine;

    if (!fscanf(*f, "%d\n", &m))
        err = corrupted;

    if (m <= 0)
        err = corrupted;

    *n = m;
    return err;
}
enum Err allocate_mem_lines(struct LineList lines)
{
    Err err = Fine;
    lines.list = (struct Line *)malloc(lines.count * sizeof(struct Line));
    if (!lines.list)
        err = memorErr;
    return err;
}

void free_mem_lines(struct LineList lines)
{
    free(lines.list);
}

enum Err try_load_line(FILE *f, struct Line *line)
{
    Err err = Fine;
    if (!fscanf(f, "%d %d\n", &line->from, &line->to))
        err = corrupted;
    return err;
}

void ClearModel(struct Model *mdl)
{
    mdl->lines.count = 0;
    mdl->points.count = 0;
    if (mdl->points.list)
        free(mdl->points.list);
    if (mdl->lines.list)
        free(mdl->lines.list);
    mdl->lines.list = nullptr;
    mdl->points.list = nullptr;
}

/*         Конец блока загрузки             */

/*         Начало блока отрисовки             */
enum Err drawline(struct PointList p,int from,int to,struct Graphics *graph)//QGraphicsScene *scene)
{
    Err err = Fine;
    //QPen pen(Qt::black);
    if (p.count<=0)
        return errDraw;

    if ((from > p.count-1) || (to > p.count-1))
        err = errDraw;
    else
        graph->scene->addLine(p.list[from].x, p.list[from].y, p.list[to].x, p.list[to].y, QPen (Qt::black));

    return err;
}
/*         Конец блока отрисовки             */
