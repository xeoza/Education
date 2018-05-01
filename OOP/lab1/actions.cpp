#include "planner.h"
#include "actions.h"
#include "drawing.h"
#include "calculation.h"
#include "add_calc.h"

//enum Err loadpoints(struct Model *a, FILE *f);

/*            Начало блока преобразований         */
enum Err move(struct Model *a,struct Motion m)
{
    if (a->lines.list==nullptr)
        return noFile;
    if (a->points.count<=0)
        return errMove;

    Err err=Fine;
    struct Conv *move=get_conv(&err);
    if (err==Fine)
    {
        init_move(move->a,m);
        err=convert_points(a,move);
    }
    clearConv(move,4);
    return err;
}

enum Err turn(struct Model *a,struct Turning tur)//2уровень
{
    if(a->lines.list==nullptr)
        return noFile;
    if (a->points.count<=0)
        return errTurn;

    Err err=Fine;
    struct Conv *turn=get_conv(&err);
    if (err==Fine)
    {
        err=choice(turn,tur);
        err=convert_points(a,turn);
    }
    clearConv(turn,4);
    return err;
}

enum Err scale(struct Model *a,struct Sc scl)//2уровень
{
    if(a->lines.list==nullptr)
        return noFile;
    if (a->points.count<=0)
        return errScale;

    Err err=Fine;
    struct Conv *scale=get_conv(&err);
    if (err==Fine)
    {
        init_scale(scale->a,scl);
        err=convert_points(a,scale);
    }
    clearConv(scale,4);
    return err;
}
/*            Конец блока преобразований         */

/*            Начало блока инициализации         */
struct Model initialize()
{
    struct Model p_mkl;
    struct Model *mdl = &p_mkl;
    mdl->lines.count=0;
    mdl->points.count=0;
    mdl->lines.list=nullptr;
    mdl->points.list=nullptr;
    return *mdl;
}
/*            Конец блока инициализации         */

/*            Начало блока загрузки         */

enum Err load(struct Model *a, char *name)//проверка на существование данных в модели. Изменение только после успеха считывания
{
    FILE *infile;
    Err err = try_open(&infile, name);

    if (err != Fine ) return err;

    struct Model temp = initialize();

    err = loadpoints(&temp, infile);
    if (err == Fine)
       err = loadlines(&temp, infile);
    fclose(infile);

    if (err == Fine)//исправить
    {
        ClearModel(a);
        *a = temp;//очистить А по памяти
    }
    else
        ClearModel(&temp);

    return err;

}
/*            Конец блока загрузки         */
/*            Начало блока отрисовки         */
enum Err draw(struct Model *a, struct Graphics *graph)//QGraphicsScene *scene)//graphics.scene)//QGraphicsScene *scene)
{
    if (a == nullptr) return errDraw;

    Clear(graph);
    Err err = drawlines(a, graph);
    return err;
}

/*            Конец блока отрисовки         */
