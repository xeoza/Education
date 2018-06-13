#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <iostream>

using namespace std;

#define OPEN_DELAY 1000
#define CLOSE_DELAY 1000
#define WAIT 1000

class Doors : public QObject
{
    Q_OBJECT

    enum doorsState
    {
        open,
        opening,
        close,
        closing
    };

    public:
        Doors();
        ~Doors() {}

    public slots:
        void slotOpen();
        void slotClose();
        void slotOpening();
        void slotClosing();

    signals:
        void closed();
        void opened();

    private:
        doorsState state;
        QTimer timerOpening;
        QTimer timerClosing;
        QTimer timerWait;
};

#endif // DOORS_H
