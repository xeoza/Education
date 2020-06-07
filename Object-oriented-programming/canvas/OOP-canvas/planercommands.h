#ifndef TASKCOMMANDS_H
#define TASKCOMMANDS_H

#include "planercommand.h"

class SimpleCommand : public PlannerCommand
{
public:

    typedef void (Planner::*action)();

    SimpleCommand(Planner* _plan, action _act) : PlannerCommand(_plan), act(_act){}

    void execute()
    {
        (this->plan->*act)();
    }

private:

    action act;
};


class ModifiyCommand : public PlannerCommand
{
public:

    typedef void (Planner::*action)(ModifiyType, double);

    ModifiyCommand(Planner* plan, action _act, ModifiyType _type, double _delta)
         : PlannerCommand(plan), act(_act), type(_type), delta(_delta) {}

    void execute()
    {
        (this->plan->*act)(this->type, this->delta);
    }

private:

    action act;
    ModifiyType type;
    double delta;
};


class LoadCommand : public PlannerCommand
{
public:

    typedef void (Planner::*action)(const char*);

    LoadCommand(Planner* _plan, action _act, const char* _name) :
        PlannerCommand(_plan), act(_act), name(_name){}

    void execute()
    {
        (this->plan->*act)(this->name);
    }

private:

    action act;
    const char* name;

};

class CameraCommand : public PlannerCommand
{
public:

    typedef void (Planner::*action)(Camera&);

    CameraCommand(Planner* _plan, action _act, Camera& cam) :
        PlannerCommand(_plan), act(_act), camera(Camera())
    {
        this->camera.setDistance(cam.getDistance());
    }

    void execute()
    {
        (this->plan->*act)(this->camera);
    }

private:

    action act;
    Camera camera;

};


class CanvasCommand : public PlannerCommand
{
public:

    typedef void (Planner::*action)(const CanvasStruct& );

    CanvasCommand(Planner* _plan, action _act, const CanvasStruct&  can) :
        PlannerCommand(_plan), act(_act)
    {
        canvas.scene = can.scene;
        canvas.pen = can.pen;
    }

    void execute()
    {
        (this->plan->*act)(this->canvas);
    }

private:

    CanvasStruct canvas;
    action act;
};
#endif // TASKCOMMANDS_H
