#ifndef SINGLETON_H
#define SINGLETON_H


template <typename T>
class Singleton
{
public:
    static T* instance()
    {
        if(!myInstance)
            myInstance = new T;
        return myInstance;
    }

    ~Singleton()
    {
        delete myInstance;
    }

private:
    static T* myInstance;
    Singleton(const Singleton&) {}

};

template <typename T>
T* Singleton<T>::myInstance = nullptr;

#endif // SINGLETON_H
