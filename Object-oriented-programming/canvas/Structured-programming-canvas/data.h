#ifndef DATA_H
#define DATA_H
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
enum t_type{OX,OY,OZ};
struct Motion
{
    int dx,dy,dz;
};

struct Turning
{
    t_type turntype;
    double angle;
};

struct Sc
{
    double sx,sy,sz;
};

struct Conv{
    double **a;
    double *b;
    double *c;
};



struct Data
{
    union {
         char *name;
        struct Motion move;
        struct Turning turn;
        struct Sc scale;
    };
};
enum Action{Init,Load,Draw,Turn,Move,Scale};

enum Err{errInit,noFile,corrupted,errDraw,errTurn,errMove,errScale,memorErr,unKnown,Fine};

Err entry_p(Action act,struct Data data,QGraphicsView *view);
#endif // DATA_H

