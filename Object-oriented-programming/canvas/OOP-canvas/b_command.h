#ifndef B_COMMAND_H
#define B_COMMAND_H


class B_Command
{
public:
    virtual ~B_Command(){}
    virtual void execute () = 0;
};

#endif // B_COMMAND_H
