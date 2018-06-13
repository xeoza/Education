#ifndef ALL_H
#define ALL_H
#include <qgraphicsview.h>
#define PI 3.14159265359

#include "data.h"

Err entry_p(Action act,struct Data data,QGraphicsView *view);

Err move(Model *a,struct Motion m);
Err turn(Model *a,struct Turning tur);
Err scale(Model *a,struct Sc scl);
Model* initialize();
Err load(Model *a, char *name);
Err draw(Model *a,QGraphicsScene *scene);

void init_move(double **a,Motion m);
Err convert_points(Model *a, struct Conv *move);
Err choice(struct Conv *turn,struct Turning tur);
void init_scale(double **a,struct Sc m);
Err try_open(FILE **f, char *name);
Err loadpoints(Model *a,FILE *f);
Err loadlines(Model *a,FILE *f);
int check(Model *a,Err err);
void Clear(QGraphicsScene *scene);
Err drawlines(Model *a,QGraphicsScene *scene);
struct Conv *get_conv(Err *err);

void init_point(double *c,struct Point p);
Err convert_point(struct Point *p,double **b,double *c,double *d);
void init_OX(double **a,double angle);
void init_OY(double **a,double angle);
void init_OZ(double **a,double angle);
void ClearModel(Model *mdl);
Err try_load_num_points(FILE **f,int *n);
Err allocate_mem_points(Model *a);
Err try_load_point(FILE *f,struct Point *point);
Err try_load_num_lines(FILE **f,int *n);
Err allocate_mem_lines(Model *a);
Err try_load_line(FILE *f,struct Line *line);
Err drawline(struct PointList p,int from,int to,QGraphicsScene *scene);
Err get_matrix(struct Conv *m,int n);
Err get_vectors(struct Conv *m,int n);



Err matrix_mult(double **a,double *b,double *c,int n);
double gradtorad(double x);
#endif // ALL_H

