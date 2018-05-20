#include "mainwindow.h"
#include <QApplication>
#include <QProcess>
#include <QDebug>
#include <QByteArray>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow gobangWindow;

    gobangWindow.show();

    return app.exec();
}
