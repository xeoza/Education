#include "button.h"

Button::Button(QWidget *parent) : QPushButton(parent)
{
    floorNumber = 0;
    state = released;
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(slotPressed()));
    QObject::connect(this, SIGNAL(resetButton()), this, SLOT(slotReleased()));
}

void Button::setFloorNumber(int number)
{
    this->floorNumber = number;
}

void Button::slotPressed()
{
    if (this->state == released)
    {
        this->state = pressed;
        this->setEnabled(false);
        emit newFloor(floorNumber);
    }
}

void Button::slotReleased()
{
    if (state == pressed)
    {
        this->state = released;
        this->setEnabled(true);
    }
}

