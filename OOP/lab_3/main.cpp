#include <QApplication>
#include "mainwindow.h"
#include "planner.h"
#include "singleton.h"

int main(int argc, char *argv[])
{

    Scene *scene = new Scene;
    Singleton<Planner>::instance()->setScene(scene);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    a.exec();
    delete scene;
    return 0;
}
