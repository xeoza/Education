#ifndef LEVEL_1_H
#define LEVEL_1_H

//#include "level_5.h"
#include <QGraphicsView>
//#include "level_2.h"
struct Graphics
{
    QGraphicsView *view;
    QGraphicsScene *scene;
    int ax = -250;
    int ay = -250;
    int bx = 500;
    int by = 500;
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

struct Data
{
    union {
         char *name;
        struct Motion move;
        struct Turning turn;
        struct Sc scale;
    };
};
enum Action{Init,Load,Draw,Turn,Move,Scale,FreeAll};
enum Err {errInit,noFile,corrupted,errDraw,errTurn,errMove,errScale,memorErr,unKnown,Fine};
enum Err entry_p(Action act,struct Data *data = nullptr,struct Graphics *graph = nullptr);//QGraphicsView *view);
#endif // LEVEL_1_H

