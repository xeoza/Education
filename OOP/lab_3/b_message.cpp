#include "b_message.h"

class B_Message
{

public:
    virtual void showErrorMessage(const char*) = 0;
    virtual void showMessage(const char*)      = 0;
    virtual const char* getFileName()          = 0;
};
