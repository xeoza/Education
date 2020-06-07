#include "lift.h"

Lift::Lift()
{
    QObject::connect(&controlPanel, SIGNAL(toFloor()), &liftCabin, SLOT(slotMove()));
    QObject::connect(&controlPanel, SIGNAL(reached()), &liftCabin, SLOT(slotStopClose()));
    QObject::connect(&controlPanel, SIGNAL(keepMoving()), &liftCabin, SLOT(slotMove()));
    QObject::connect(&liftCabin, SIGNAL(changedFloor()), &controlPanel, SLOT(changeCurrentFloor()));
    QObject::connect(&liftCabin, SIGNAL(reachTarget()), &controlPanel, SLOT(controllerFree()));
}

QWidget* Lift::getButtonPanel()
{
    return & controlPanel;
}
