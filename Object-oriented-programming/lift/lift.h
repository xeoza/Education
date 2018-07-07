#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include <QTimer>
#include <QLabel>
#include "controller.h"
#include "cabin.h"

class Lift : public QObject
{
    Q_OBJECT

    public:
        explicit Lift();
        ~Lift() {}
        QWidget* getButtonPanel();
        Lift(QLabel *label);

    private:
        Controller controlPanel;
        Cabin liftCabin;        
        QTimer timerMove;
};
#endif // LIFT_H
