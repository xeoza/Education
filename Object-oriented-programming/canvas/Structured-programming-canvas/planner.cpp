#include "planner.h"
#include <QGraphicsView>
#include "actions.h"
#include "drawing.h"
#include "calculation.h"
#include "add_calc.h"

enum Err entry_p(Action act,struct Data *data, struct Graphics *graph)//QGraphicsView *view)//1уровень
{
    static Model model = initialize();
    Err err = Fine;

    switch (act)
    {
        case Init:
        {
            break;
        }
        case Load:
        {
            err = load(&model, data->name);
            break;
        }
        case Move:
        {
            err = move(&model, data->move);
            break;
        }
        case Turn:
        {
            err = turn(&model, data->turn);
            break;
        }
        case Scale:
        {
            err = scale(&model, data->scale);
            break;
        }
        case Draw:
        {
            err = draw(&model, graph);
            break;
        }
        case FreeAll:
        {
            ClearModel(&model);
            err = Fine;
            break;
        }
        default:
            err = unKnown;
    }

    return err;
}
