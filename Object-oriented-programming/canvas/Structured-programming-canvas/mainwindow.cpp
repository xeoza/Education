#include "mainwindow.h"
#include "ui_mainwindow.h"
#define MAX_STRING 255


#include "planner.h"
#include "actions.h"
#include "drawing.h"
#include "calculation.h"
#include "add_calc.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    struct Data data;
    struct Graphics graph;
    graph.view = ui->graphicsView;
    graph.scene = new QGraphicsScene(graph.view);
    entry_p(Init,&data,&graph);//ui->graphicsView);
}

MainWindow::~MainWindow()
{
    entry_p(FreeAll);
    delete ui;
}

/*void MainWindow::on_pushButton_clicked()инициализация
{
    struct Data data;
    //entry_p(Init,data,ui->graphicsView);
    if (entry_p(Init,data,ui->graphicsView)!=Fine)
    {
        QMessageBox::critical(NULL,QObject::tr("Ошибка!"),tr("Ошибка инициализации."));
    }

}*/

void MainWindow::on_pushButton_2_clicked()//отрисовка
{
    struct Data data;
    Err e;
    char *nd=(char*)malloc(MAX_STRING*sizeof(char));
    if (!nd)
        return;
    strncpy(nd,ui->lineEdit->text().toStdString().c_str(),MAX_STRING);
    data.name=nd;

    struct Graphics graph;
    graph.view = ui->graphicsView;
    graph.scene = new QGraphicsScene(graph.view);
    e=entry_p(Load,&data,&graph);//ui->graphicsView);
    entry_p(Draw,&data,&graph);//ui->graphicsView);
    graph.view->setScene(graph.scene);
    switch (e)
    {
            case corrupted:
                QMessageBox::critical(NULL,QObject::tr("Ошибка!"),tr("Файл поврежден."));
                break;
            case noFile:
                QMessageBox::critical(NULL,QObject::tr("Ошибка!"),tr("Нет файла."));
                break;
            case Fine:
                break;
            case memorErr:
                QMessageBox::critical(NULL,QObject::tr("Ошибка!"),tr("Ошибка памяти."));
                break;
            default:
                QMessageBox::critical(NULL,QObject::tr("Ошибка!"),tr("Ошибка загрузки."));
            break;

    }
    free(nd);
}

void MainWindow::on_pushButton_3_clicked()//поворот
{
    struct Data data;
    Err e;
    data.turn.angle=ui->spinBox->text().toDouble();
    if (ui->radioButton->isChecked())
    {
        data.turn.turntype=OX;
    }
    else
        if (ui->radioButton_2->isChecked())
        {
            data.turn.turntype=OY;
        }
    else
    if (ui->radioButton_3->isChecked())
    {
        data.turn.turntype=OZ;

    }
    struct Graphics graph;
    graph.view = ui->graphicsView;
    graph.scene = new QGraphicsScene(graph.view);
    e=entry_p(Turn,&data,&graph);//ui->graphicsView);
    entry_p(Draw,&data,&graph);//ui->graphicsView);
    graph.view->setScene(graph.scene);
    switch (e)
    {
        case noFile:
            QMessageBox::critical(NULL,QObject::tr("Ошибка!"),tr("Не загружена модель."));
            break;
        case Fine:
            break;
        case errTurn:
            QMessageBox::critical(NULL,QObject::tr("Ошибка!"),tr("Ошибка поворота."));
            break;
        case memorErr:
            QMessageBox::critical(NULL,QObject::tr("Ошибка!"),tr("Ошибка памяти."));
            break;
        default:
            QMessageBox::critical(NULL,QObject::tr("Ошибка!"),tr("Неизвестная ошибка."));
            break;

    }
}

void MainWindow::on_pushButton_4_clicked()//перенос
{
    struct Data data;
    Err e;
    data.move.dx=ui->spinBox_2->text().toInt();
    data.move.dy=ui->spinBox_3->text().toInt();
    data.move.dz=ui->spinBox_4->text().toInt();
    struct Graphics graph;
    graph.view = ui->graphicsView;
    graph.scene = new QGraphicsScene(graph.view);
    e=entry_p(Move,&data,&graph);//ui->graphicsView);
    entry_p(Draw,&data,&graph);//ui->graphicsView);
    graph.view->setScene(graph.scene);
    switch (e)
    {
        case noFile:
            QMessageBox::critical(NULL,QObject::tr("Ошибка!"),tr("Не загружена модель."));
            break;
        case Fine:
            break;
        case errMove:
            QMessageBox::critical(NULL,QObject::tr("Ошибка!"),tr("Ошибка переноса."));
            break;
        case memorErr:
            QMessageBox::critical(NULL,QObject::tr("Ошибка!"),tr("Ошибка памяти."));
            break;
        default:
            QMessageBox::critical(NULL,QObject::tr("Ошибка!"),tr("Неизвестная ошибка."));
            break;

    }
}

void MainWindow::on_pushButton_5_clicked()//масштаб
{
    struct Data data;
    Err e;
    data.scale.sx=ui->doubleSpinBox->text().toDouble();
    data.scale.sy=ui->doubleSpinBox_2->text().toDouble();
    data.scale.sz=ui->doubleSpinBox_3->text().toDouble();
    struct Graphics graph;
    graph.view = ui->graphicsView;
    graph.scene = new QGraphicsScene(graph.view);
    e=entry_p(Scale,&data,&graph);//ui->graphicsView);
    entry_p(Draw,&data,&graph);//ui->graphicsView);
    graph.view->setScene(graph.scene);
    switch (e)
    {
        case noFile:
            QMessageBox::critical(NULL,QObject::tr("Ошибка!"),tr("Не загружена модель."));
            break;
        case Fine:
            break;
        case errScale:
            QMessageBox::critical(NULL,QObject::tr("Ошибка!"),tr("Ошибка масштабирования."));
            break;
        case memorErr:
            QMessageBox::critical(NULL,QObject::tr("Ошибка!"),tr("Ошибка памяти."));
            break;
        default:
            QMessageBox::critical(NULL,QObject::tr("Ошибка!"),tr("Неизвестная ошибка."));
            break;

    }
}
