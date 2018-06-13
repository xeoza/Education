#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QObject>

class Button : public QPushButton
{
    Q_OBJECT

    enum buttonState
    {
        pressed,
        released
    };
    public:

        explicit Button(QWidget *parent = 0);
        virtual ~Button() {}
        void setFloorNumber(int number);

    public slots:
        void slotPressed();
        void slotReleased();

    signals:
        void resetButton();
        void newFloor(int number);

    private:
        int floorNumber;
        buttonState state;
};

#endif // BUTTON_H
