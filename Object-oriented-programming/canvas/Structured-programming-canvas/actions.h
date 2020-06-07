#ifndef LEVEL_2_H
#define LEVEL_2_H

//#include "3_level.h"
//#include "4_level.h"
//#include "level_5.h"
#include "planner.h"
#include "drawing.h"
#include "calculation.h"
#include "add_calc.h"

struct Point
{
    double x,y,z;
};

struct Line
{
    int from,to;
};

struct PointList
{
    int count;
    struct Point *list;
};

struct LineList
{
    int count;
    struct Line *list;
};

struct Model
{
    struct PointList points;
    struct LineList lines;
};

enum Err move(Model *a,struct Motion m);
enum Err turn(Model *a,struct Turning tur);
enum Err scale(Model *a,struct Sc scl);
struct Model initialize();
enum Err load(Model *a, char *name);
enum Err draw(Model *a, struct Graphics *graph);// .scene);//QGraphicsScene *scene);

#endif // LEVEL_2_H

