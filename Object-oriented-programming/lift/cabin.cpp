#include "cabin.h"

Cabin::Cabin()
{
    state = stop_close;
    QObject::connect(&timerMove, SIGNAL(timeout()), this, SIGNAL(changedFloor()));
    timerMove.setSingleShot(true);
    QObject::connect(this, SIGNAL(openDoors()),&liftDoors, SLOT(slotOpening()));
    QObject::connect(this, SIGNAL(signalReach()), this, SLOT(slotStopOpen()));
    QObject::connect(&liftDoors, SIGNAL(opened()), this, SLOT(slotStopOpen()));
    QObject::connect(&liftDoors, SIGNAL(closed()), this, SLOT(slotStopClose()));
}

void Cabin::slotMove()
{
    if (state == stop_close || state == move)
    {
        state = move;
        timerMove.start(MOVE_DELAY);
    }
}

void Cabin::slotStopOpen()
{
    if (state == stop_close)
    {
        state = stop_open;
    }
}

void Cabin::slotStopClose()
{
    if (state == move)
    {
        timerMove.stop();
        state = stop_close;
        emit openDoors();
    }
    else if (state == stop_open)
    {
        state = stop_close;
        emit reachTarget();
    }
}

