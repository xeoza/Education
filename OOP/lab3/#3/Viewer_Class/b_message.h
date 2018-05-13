#ifndef B_MESSAGE_H
#define B_MESSAGE_H


class B_Message
{
public:

    virtual void showErrorMessage(const char* ) = 0;
    virtual void showMessage(const char* )      = 0;
    virtual const char* getFileName()           = 0;
};

#endif // B_MESSAGE_H
