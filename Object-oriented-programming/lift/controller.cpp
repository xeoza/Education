#include "controller.h"

Controller::Controller(QWidget *parent) : QWidget(parent)
{
    state = free;
    currentFloor = 1;
    targetFloor = 1;
    liftDirection = stop;
    layout = new QVBoxLayout();
    this->setLayout(layout);
    QObject::connect(this, SIGNAL(workAgain(int)), this, SLOT(controllerWork(int)));
    for (int i = FLOOR_COUNT; i > 0; i--)
    {
        Button *btn = new Button();
        btn->setText(QString::number(i));
        btn->setFloorNumber(i);
        layout->addWidget(btn);
        QObject::connect(btn, SIGNAL(newFloor(int)), this, SLOT(controllerWork(int)));
        buttons[i - 1] = btn;
    }
    for (int i = 0; i < FLOOR_COUNT; i++)
        floors[i] = false;
}

Controller::~Controller()
{
    for (int i = 0; i < FLOOR_COUNT; i++)
        delete buttons[i];
    delete layout;
}

void Controller::controllerWork(int number)
{
    if (state == free || state == service)
    {
        state = work;
    }
    if (state == work)
    {
        this->floors[number - 1] = true;
        findTarget(number);
        targetFloor = number;
        emit toFloor();
    }
}

void Controller::changeCurrentFloor()
{
    if (currentFloor == targetFloor)
    {
        std::cout << "На " << currentFloor << " этаже" << endl;
        state = service;
        emit reached();
    }
    else
    {
        std::cout << "Проезжаю " << currentFloor << endl;
        if (currentFloor < targetFloor)
            currentFloor++;
        else
            currentFloor--;
        emit keepMoving();
    }
}

bool Controller::findTarget(int &target)
{
    if (liftDirection == up || liftDirection == down)
    {
        int step = (liftDirection == up) ? 1 : -1;
        for (int i = currentFloor - 1; i < FLOOR_COUNT && i >= 0; i += step)
        {
            if (floors[i])
            {
                target = i+1;
                return true;
            }
        }
        if (liftDirection == up)
            liftDirection = down;
        else
            liftDirection = up;
        step = -step;
        for (int i = currentFloor - 1; i < FLOOR_COUNT && i >= 0; i += step)
        {
            if (floors[i])
            {
                target = i+1;
                return true;
            }
        }
    }
    else
    {
        int i;
        for (i = 0; i < FLOOR_COUNT && !floors[i]; i++);

        if (floors[i])
        {
            target = i+1;
            if (target > currentFloor)
                liftDirection = up;
            else
                liftDirection = down;
            return true;
        }
    }
    return false;
}

void Controller::controllerFree()
{
    int number = currentFloor;
    if (state == work || state == service)
    {
        liftDirection = stop;
        state = free;
        this->floors[number - 1] = false;
        emit buttons[number - 1]->resetButton();
    }
    if (findTarget(number))
    {
        emit workAgain(number);
    }
}


