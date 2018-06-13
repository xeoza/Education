#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include "button.h"
#include <iostream>

using namespace std;

#define FLOOR_COUNT 9

class Controller : public QWidget
{
    Q_OBJECT

    enum controllerState
    {
        free,
        work,
        service
    };

    enum Direction
    {
        up,
        down,
        stop
    };
    public:
        explicit Controller(QWidget *parent = 0);
        ~Controller();

    signals:
        void toFloor();
        void reached();
        void keepMoving();
        void workAgain(int number);

    public slots:
        void controllerFree();
        void changeCurrentFloor();

    private slots:
        void controllerWork(int number);

    private:
        controllerState state;
        int currentFloor;
        int targetFloor;
        bool floors[FLOOR_COUNT];
        Button* buttons[FLOOR_COUNT];
        QVBoxLayout *layout;
        Direction liftDirection;
        bool findTarget(int &target);
};

#endif // CONTROLLER_H
