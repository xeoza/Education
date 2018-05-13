/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHELP;
    QAction *actionFILE;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *Canvas;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *sb_angle;
    QLabel *label_2;
    QDoubleSpinBox *sb_scale;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_addCam;
    QLabel *label_3;
    QDoubleSpinBox *sb_cam_dist;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(535, 512);
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200/Desktop/icons/cube.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionHELP = new QAction(MainWindow);
        actionHELP->setObjectName(QStringLiteral("actionHELP"));
        actionHELP->setCheckable(false);
        actionHELP->setChecked(false);
        actionFILE = new QAction(MainWindow);
        actionFILE->setObjectName(QStringLiteral("actionFILE"));
        actionFILE->setCheckable(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Canvas = new QGraphicsView(centralWidget);
        Canvas->setObjectName(QStringLiteral("Canvas"));

        verticalLayout->addWidget(Canvas);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        sb_angle = new QDoubleSpinBox(centralWidget);
        sb_angle->setObjectName(QStringLiteral("sb_angle"));
        sb_angle->setMinimum(-360);
        sb_angle->setMaximum(360);
        sb_angle->setSingleStep(2);
        sb_angle->setValue(5);

        horizontalLayout->addWidget(sb_angle);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        sb_scale = new QDoubleSpinBox(centralWidget);
        sb_scale->setObjectName(QStringLiteral("sb_scale"));
        sb_scale->setMinimum(0.1);
        sb_scale->setMaximum(5);
        sb_scale->setValue(1.1);

        horizontalLayout->addWidget(sb_scale);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btn_addCam = new QPushButton(centralWidget);
        btn_addCam->setObjectName(QStringLiteral("btn_addCam"));

        horizontalLayout_2->addWidget(btn_addCam);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        sb_cam_dist = new QDoubleSpinBox(centralWidget);
        sb_cam_dist->setObjectName(QStringLiteral("sb_cam_dist"));
        sb_cam_dist->setMinimum(1);
        sb_cam_dist->setMaximum(100);
        sb_cam_dist->setValue(20);

        horizontalLayout_2->addWidget(sb_cam_dist);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionFILE);
        toolBar->addAction(actionHELP);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Carcas Viewer", 0));
        actionHELP->setText(QApplication::translate("MainWindow", "\320\241\320\237\320\240\320\220\320\222\320\232\320\220", 0));
        actionHELP->setShortcut(QApplication::translate("MainWindow", "H", 0));
        actionFILE->setText(QApplication::translate("MainWindow", "\320\244\320\220\320\231\320\233", 0));
        actionFILE->setShortcut(QApplication::translate("MainWindow", "F", 0));
        label->setText(QApplication::translate("MainWindow", " \320\243\320\263\320\276\320\273 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260", 0));
        label_2->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \320\274\320\260\321\201\321\210\321\202\320\270\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", 0));
        btn_addCam->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\260\320\274\320\265\321\200\321\203", 0));
        label_3->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\272\320\260\320\274\320\265\321\200\321\213", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
