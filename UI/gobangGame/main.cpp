#include "mainwindow.h"
#include <QApplication>
#include <QProcess>
#include <QDebug>
#include <QByteArray>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//    QProcess* p = new QProcess;
//    p->start("ls");
//    p->waitForFinished();
//    QByteArray b = p->readAll();
//    qDebug()<<b.data();

    MainWindow gobangWindow;
    gobangWindow.show();

    return app.exec();
}
