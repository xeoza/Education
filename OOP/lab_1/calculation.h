#ifndef LEVEL_4_H
#define LEVEL_4_H
#include "planner.h"
#include "actions.h"
#include "drawing.h"
//enum Err{errInit,noFile,corrupted,errDraw,errTurn,errMove,errScale,memorErr,unKnown,Fine};
#include "add_calc.h"
void init_point(double *c,struct Point p);
enum Err convert_point(struct Point *p,double **b,double *c,double *d);
void init_OX(double **a,double angle);
void init_OY(double **a,double angle);
void init_OZ(double **a,double angle);
void ClearModel(struct Model *);
enum Err try_load_num_points(FILE **f,int *n);
enum Err allocate_mem_points(struct PointList points);
enum Err try_load_point(FILE *f,struct Point *point);
enum Err try_load_num_lines(FILE **f,int *n);
enum Err allocate_mem_lines(struct LineList lines);
enum Err try_load_line(FILE *f,struct Line *line);
enum Err drawline(struct PointList p,int from,int to,struct Graphics *graph);//QGraphicsScene *scene);
enum Err get_matrix(struct Conv *m,int n);
enum Err get_vectors(struct Conv *m,int n);
void free_mem_points(struct PointList points);
void free_mem_lines(struct LineList lines);

#endif // LEVEL_4_H

