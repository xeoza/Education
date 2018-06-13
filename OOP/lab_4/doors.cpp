#include "doors.h"

Doors::Doors()
{
    state = close;
    QObject::connect(&timerOpening, SIGNAL(timeout()), this, SLOT(slotOpen()));
    QObject::connect(&timerClosing, SIGNAL(timeout()), this, SLOT(slotClose()));
    QObject::connect(&timerWait, SIGNAL(timeout()), this, SLOT(slotClosing()));
    timerOpening.setSingleShot(true);
    timerClosing.setSingleShot(true);
    timerWait.setSingleShot(true);
}

void Doors::slotOpen()
{
    if (state == opening)
    {
        state = open;
        std::cout << "Двери открыты" << endl;
        emit opened();        
        timerWait.start(WAIT);
    }
}

void Doors::slotClose()
{
    if (state == closing)
    {
        state = close;
        std::cout << "Двери закрыты" << endl;
        emit closed();
    }
}

void Doors::slotOpening()
{    
    if (state == close)
    {
        std::cout << "Двери открываются" << endl;
        state = opening;
        timerOpening.start(OPEN_DELAY);
    }
}

void Doors::slotClosing()
{
    if (state == open)
    {
        std::cout << "Двери закрываются" << endl;
        state = closing;
        timerClosing.start(CLOSE_DELAY);
    }
}

