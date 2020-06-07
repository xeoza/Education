#include "planner.h"
#include "actions.h"
#include "drawing.h"
#include "calculation.h"
#include "add_calc.h"

/*          Начало блока преобразований         */
void clearConv(struct Conv *data, int n)
{
    for (int i = 0; i < n; i++)
        free(data->a[i]);
    free(data->a);
    free(data->b);
    free(data->c);
    free(data);
    return ;
}
struct Conv *get_conv(enum Err *err)
{
    struct Conv *move = (struct Conv *)malloc(sizeof( struct Conv ));
    if (!move)
    {
        *err = memorErr;
        return nullptr;
    }
    *err = get_matrix(move, 4);
    *err = get_vectors(move, 4);
    return move;
}
void init_move(double **a,struct Motion m)
{
        a[0][0]=1;
        a[0][1]=0;
        a[0][2]=0;
        a[0][3]=0;

        a[1][0]=0;
        a[1][1]=1;
        a[1][2]=0;
        a[1][3]=0;

        a[2][0]=0;
        a[2][1]=0;
        a[2][2]=1;
        a[2][3]=0;

        a[3][0]=m.dx;
        a[3][1]=m.dy;
        a[3][2]=m.dz;
        a[3][3]=1;
        return ;
}
void init_scale(double **a,struct Sc m)
{

        a[0][0]=m.sx;
        a[0][1]=0;
        a[0][2]=0;
        a[0][3]=0;

        a[1][0]=0;
        a[1][1]=m.sy;
        a[1][2]=0;
        a[1][3]=0;

        a[2][0]=0;
        a[2][1]=0;
        a[2][2]=m.sz;
        a[2][3]=0;

        a[3][0]=0;
        a[3][1]=0;
        a[3][2]=0;
        a[3][3]=1;
        return ;
}
enum Err choice(struct Conv *turn,struct Turning tur)
{
    Err err = Fine;
    switch (tur.turntype)
    {
        case OX:
            init_OX(turn->a, tur.angle);
            break;
        case OY:
            init_OY(turn->a, tur.angle);
            break;
        case OZ:
            init_OZ(turn->a, tur.angle);
            break;
        default:
            err=unKnown;
            break;
    }
    return err;
}



enum Err convert_points(struct Model *a, struct Conv *move)
{
    Err err = Fine;
    for (int i = 0; i < a->points.count; i++)
    {
        if (err == Fine)
        {
            init_point(move->b, a->points.list[i]);
            err = convert_point(&a->points.list[i], move->a, move->b, move->c);
        }
    }
    return err;
}
/*         Конец блока преобразований              */


/*        Начало блока заргузки       */

enum Err try_open(FILE **f, char *name)
{
    *f = fopen(name, "r");
    if (!(*f))
        return noFile;
    else
        return Fine;
}

enum Err loadpoints(struct PointList points, FILE *f)
{
    Err err = try_load_num_points(&f, &points.count);

    if (err != Fine)  return err;

    err = allocate_mem_points(points);
    struct Point point;
    for (int i = 0; i < points.count && (err == try_load_point(f, &point)) == Fine; i++)
    {
        points.list[i] = point;
    }
    if (err != Fine)
        free_mem_points(points);
    return err;
}

enum Err loadlines(struct LineList lines, FILE *f)
{
    Err err = try_load_num_lines(&f, &lines.count);

    if (err != Fine) return err;

    err = allocate_mem_lines(lines);
    struct Line line;
    for (int i = 0; i < lines.count && (err == try_load_line(f, &line)) == Fine; i++)
    {
        lines.list[i] = line;
    }
    if (err != Fine)
        free_mem_lines(lines);
    return err;
}

/*        Конец блока заргузки       */

/*        Начало блока отрисовки       */
void Clear(struct Graphics *graph)//QGraphicsScene *scene)/убрать мртвый код
{
    graph->scene->addRect(graph->ax, graph->ay, graph->bx, graph->by, QPen (Qt::white), QBrush (Qt::white));
    return;
}

enum Err drawlines(struct Model *a, struct Graphics *graph)//QGraphicsScene *scene)
{
    Err err = Fine;
    for (int i = 0; i < a->lines.count && err == Fine; i++)
    {
        err = drawline(a->points, a->lines.list[i].from, a->lines.list[i].to, graph);
    }
    return err;
}
/*         Конец блока отрисовки       */
