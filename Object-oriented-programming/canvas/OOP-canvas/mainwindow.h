#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QDoubleSpinBox>
#include <QKeyEvent>
#include <QMessageBox>
#include "message.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
private:
    Ui::MainWindow *ui;
    Message* msg;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionHELP_triggered();
    void on_actionFILE_triggered();

    double readScale();
    double readAngle();
    double readCamDistance();

    void QbuttClicked();
    void EbuttClicked();
    void WbuttClicked();
    void SbuttClicked();
    void AbuttClicked();
    void DbuttClicked();
    void PlusbuttClicked();
    void MinusbuttClicked();

    void keyPressEvent(QKeyEvent*);

    void on_btn_addCam_clicked();


};



#endif // MAINWINDOW_H
