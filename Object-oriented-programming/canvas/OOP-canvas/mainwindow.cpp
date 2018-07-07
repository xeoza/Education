#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvas.h"
#include "planercommands.h"
#include "singleton.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), msg(new Message)
{

    this->ui->setupUi(this);

    this->ui->Canvas->setScene(new QGraphicsScene);
    CanvasStruct cstr;
    cstr.scene = this->ui->Canvas->scene();
    cstr.pen = QPen(Qt::black,2.0);


    Camera cam(10);
    CanvasCommand comSetCanv(Singleton<Planner>::instance(), &Planner::setCanvas, cstr);
    CameraCommand comAddCam(Singleton<Planner>::instance(), &Planner::addCamera, cam);

    try
    {
        comSetCanv.execute();
        comAddCam.execute();
    }
    catch(B_Error& err)
    {
        msg->showErrorMessage(err.info());
    }

}

MainWindow::~MainWindow()
{
    delete this->msg;
    delete ui;
}


double MainWindow::readCamDistance()
{
    return this->ui->sb_cam_dist->value();
}

double MainWindow::readAngle()
{
    return this->ui->sb_angle->value();
}

double MainWindow::readScale()
{
    return this->ui->sb_scale->value();
}

void MainWindow::on_actionHELP_triggered()
{

    QMessageBox::information(this,"Справка","'+' - увеличить\n"
                             "'-' - уменьшить\n\n"
                             "'Q','E' - вращение вокруг оси Z\n"
                             "'A','D' - вращение вокруг оси Y\n"
                             "'W','S' - вращение вокруг оси X\n\n");
}

void MainWindow::on_actionFILE_triggered()
{

    const char *fileName = msg->getFileName();

    if(!fileName)
    {
        return;
    }

    LoadCommand comLoadFile(Singleton<Planner>::instance(),&Planner::addModel, fileName);
    SimpleCommand comDraw(Singleton<Planner>::instance(), &Planner::drawModel);

    try
    {

        comLoadFile.execute();
        comDraw.execute();
    }
    catch(B_Error& err)
    {
        msg->showErrorMessage(err.info());
    }

}

/* Обработка нажатия клавиш */
void MainWindow::keyPressEvent(QKeyEvent *k)
{
    switch(k->key())
    {
        case Qt::Key_Q:
        {
            this->QbuttClicked();
            break;
        }

        case Qt::Key_E:
        {
            this->EbuttClicked();
           break;
        }

        case Qt::Key_S:
        {
            this->SbuttClicked();
            break;
        }

        case Qt::Key_W:
        {
            this->WbuttClicked();
            break;
        }

        case Qt::Key_A:
        {
            this->AbuttClicked();
            break;
        }

        case Qt::Key_D:
        {
            this->DbuttClicked();
            break;
        }

        case Qt::Key_Plus:
        {
            this->PlusbuttClicked();
            break;
        }

        case Qt::Key_Minus:
        {
            this->MinusbuttClicked();
            break;
        }
    }
}


void MainWindow::QbuttClicked()
{

    ModifiyCommand com1(Singleton<Planner>::instance(),&Planner::convertModel, ROTATEZ, this->readAngle());
    SimpleCommand com2(Singleton<Planner>::instance(), &Planner::drawModel);

    try
    {
        com1.execute();
        com2.execute();
    }
    catch(B_Error& err)
    {
        msg->showErrorMessage(err.info());
    }
}

void MainWindow::EbuttClicked()
{
    ModifiyCommand com1(Singleton<Planner>::instance(),&Planner::convertModel, ROTATEZ, -this->readAngle());
    SimpleCommand com2(Singleton<Planner>::instance(), &Planner::drawModel);

    try
    {
        com1.execute();
        com2.execute();
    }
    catch(B_Error& err)
    {
        msg->showErrorMessage(err.info());
    };


}

void MainWindow::WbuttClicked()
{
    ModifiyCommand com1(Singleton<Planner>::instance(),&Planner::convertModel, ROTATEX, this->readAngle());
    SimpleCommand com2(Singleton<Planner>::instance(), &Planner::drawModel);

    try
    {
        com1.execute();
        com2.execute();
    }
    catch(B_Error& err)
    {
        msg->showErrorMessage(err.info());
    }
}

void MainWindow::SbuttClicked()
{
    ModifiyCommand com1(Singleton<Planner>::instance(),&Planner::convertModel, ROTATEX, -this->readAngle());
    SimpleCommand com2(Singleton<Planner>::instance(), &Planner::drawModel);


    try
    {
        com1.execute();
        com2.execute();
    }
    catch(B_Error& err)
    {
        msg->showErrorMessage(err.info());
    }
}

void MainWindow::AbuttClicked()
{
    ModifiyCommand com1(Singleton<Planner>::instance(),&Planner::convertModel, ROTATEY, this->readAngle());
    SimpleCommand com2(Singleton<Planner>::instance(), &Planner::drawModel);

    try
    {
        com1.execute();
        com2.execute();
    }
    catch(B_Error& err)
    {
        msg->showErrorMessage(err.info());
    }
}

void MainWindow::DbuttClicked()
{
    ModifiyCommand com1(Singleton<Planner>::instance(),&Planner::convertModel, ROTATEY, -this->readAngle());
    SimpleCommand com2(Singleton<Planner>::instance(), &Planner::drawModel);

    try
    {
        com1.execute();
        com2.execute();
    }
    catch(B_Error& err)
    {
        msg->showErrorMessage(err.info());
    }
}

void MainWindow::PlusbuttClicked()
{
    ModifiyCommand com1(Singleton<Planner>::instance(),&Planner::convertModel, SCALE, this->readScale());
    SimpleCommand com2(Singleton<Planner>::instance(), &Planner::drawModel);

    try
    {
        com1.execute();
        com2.execute();
    }
    catch(B_Error& err)
    {
        msg->showErrorMessage(err.info());
    }
}

void MainWindow::MinusbuttClicked()
{
    ModifiyCommand com1(Singleton<Planner>::instance(),&Planner::convertModel, SCALE, 1/this->readScale());
    SimpleCommand com2(Singleton<Planner>::instance(), &Planner::drawModel);

    try
    {
        com1.execute();
        com2.execute();
    }
    catch(B_Error& err)
    {
        msg->showErrorMessage(err.info());
    }
}


void MainWindow::on_btn_addCam_clicked()
{
    double distance = this->readCamDistance();
    Camera cam(distance);

    CameraCommand com1(Singleton<Planner>::instance(),&Planner::addCamera,cam);
    SimpleCommand com2(Singleton<Planner>::instance(),&Planner::drawModel);

    try
    {
        com1.execute();
        com2.execute();
    }
    catch(B_Error& err)
    {
        msg->showErrorMessage(err.info());
    }
}
