#ifndef MY_EXCEPTIONS_H
#define MY_EXCEPTIONS_H

#include <exception>
#include <string>

using namespace std;

class cEBaseException : public std::exception
{
protected:
    string err_info;
public:
    cEBaseException(const string &fileName, const string &className, const int line, char *time, const string &info)
    {
        err_info = "\nFile: " +
                fileName +
                "\nClass: " +
                className +
                "\nLine: " +
                std::to_string(line) +
                "\nTime: " +
                time +
                "\nInfo:" +
                info;
    }

    virtual string what()
    {
        return "My base exception." + err_info;
    }
};
class cEIndexException : public cEBaseException
{
public:
    cEIndexException(const string &fileName, const string &className, const int line, char *time, const string &info):
        cEBaseException(fileName, className, line, time, info)
    {
    }
    string what()
    {
        return "Array index is out of range!" + err_info;
    }
};

class cEMemoryException : public cEBaseException
{
public:
    cEMemoryException(const string &fileName, const string &className, const int line, char *time, const string &info):
        cEBaseException(fileName, className, line, time, info)
    {
    }

    string what()
    {
        return "Couldn't allocate memory for array data!" + err_info;
    }
};

class cEIteratorException : public cEBaseException
{
public:
    cEIteratorException(const string &fileName, const string &className, const int line, char *time, const string &info):
        cEBaseException(fileName, className, line, time, info)
    {
    }

    string what()
    {
        return "shared_ptr hasn't object!" + err_info;
    }
};

#endif // MY_EXCEPTIONS_H
