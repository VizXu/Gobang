#include "mainwindow.h"
#include <QPoint>
#include <QApplication>


void MainWindow::paintEvent(QPaintEvent *)
{

}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    QPainter tmpP(this);
    if (Qt ::LeftButton == e->button())
    {
        point1->setX(e->x());

        point1->setY(e->y());

        qDebug()<<"xujiwei--->x = "<<e->x()<<",y = "<<e->y();
        tmpP.drawEllipse(point1->x(),point1->y(),15,15);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->initUI();
}

MainWindow::~MainWindow()
{
    delete this->desktopWindow;
    delete this->game;
    delete this->client;
}

void MainWindow::initUI()
{
    this->setAttribute(Qt::WA_PaintOutsidePaintEvent);
    this->desktopWindow = QApplication::desktop();
    this->client = new gobangClient;
    this->game = new gobang(client);
    this->windowSize = QSize(600,420);
    this->setMaximumSize(this->windowSize);
    this->setMinimumSize(this->windowSize);
    this->position = QPoint((this->desktopWindow->width() - this->width())/2, (this->desktopWindow->height() - this->height())/3);
    this->move(this->position);
    this->paint=new QPainter;
    this->point1 = new QPoint;
    //game->initGame(10,1);

}
