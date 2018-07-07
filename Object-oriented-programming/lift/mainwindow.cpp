#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(myLift.getButtonPanel());
    ui->centralWidget->setLayout(layout);
    cout << "На 1 этаже" << endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}
