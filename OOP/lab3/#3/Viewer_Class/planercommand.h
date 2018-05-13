#ifndef PLANNERCOMMAND_H
#define PLANNERCOMMAND_H

#include "b_command.h"
#include "planner.h"

class PlannerCommand : public B_Command
{
protected:

    Planner* plan;
public:

    PlannerCommand(Planner* _plan): plan(_plan){}
};

#endif // PLANNERCOMMAND_H
