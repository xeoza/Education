#ifndef CABIN_H
#define CABIN_H

#include <QObject>
#include <queue>
#include <list>
#include "doors.h"
#include <iostream>
using namespace std;

#define MOVE_DELAY 1000

class Cabin : public QObject
{
    Q_OBJECT

    enum cabinState
    {
        stop_open,
        stop_close,
        move
    };

    public:
       explicit Cabin();
        ~Cabin() {}

    signals:
        void reachTarget();
        void changedFloor();
        void openDoors();
        void reached();
        void signalReach();

    public slots:
        void slotStopOpen();
        void slotStopClose();
        void slotMove();

    private:
        cabinState state;
        Doors liftDoors;
        QTimer timerMove;
};

#endif // CABIN_H
