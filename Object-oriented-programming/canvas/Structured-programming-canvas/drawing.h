#ifndef LEVEL_3_H
#define LEVEL_3_H
//#include "4_level.h"
#include "planner.h"
#include "actions.h"
#include "calculation.h"
#include "add_calc.h"

struct Conv{
    double **a;
    double *b;
    double *c;
};
void clearConv(struct Conv *data, int n);
void init_move(double **a,struct Motion m);
enum Err convert_points(struct Model *a, struct Conv *move);
enum Err choice(struct Conv *turn,struct Turning tur);
void init_scale(double **a,struct Sc m);
enum Err try_open(FILE **f, char *name);
enum Err loadpoints(struct Model *a, FILE *f);
enum Err loadlines(struct Model *a, FILE *f);
void Clear(struct Graphics *graph);//QGraphicsScene *scene);
enum Err drawlines(struct Model *a, struct Graphics *graph);//QGraphicsScene *scene);
struct Conv *get_conv(Err *err);

#endif // LEVEL_3_H

