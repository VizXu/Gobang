#include "mainwindow.h"
#include <QDebug>
#include <QPoint>
#include <QApplication>
#include <cstdio>
#include <cmath>

void MainWindow::initLayout(QWidget *widget)
{
    QVBoxLayout* vLayout = new QVBoxLayout;
    QHBoxLayout* hLayout = new QHBoxLayout;
    QHBoxLayout* levelLayout = new QHBoxLayout;
    QHBoxLayout* startLayout = new QHBoxLayout;
    QHBoxLayout* cLayout = new QHBoxLayout;
    this->image = new QWidget;

    QPalette pal(this->image->palette());
    pal.setColor(QPalette::Background, Qt::black);
    this->image->setAutoFillBackground(true);

    pal.setBrush(QPalette::Window,
            QBrush(this->chessboard->scaled(
                this->chessboard->size(),
                Qt::IgnoreAspectRatio,
                Qt::SmoothTransformation)));

    this->image->setPalette(pal);

    startLayout->addWidget(this->initGame);
    levelLayout->addWidget(this->label);
    levelLayout->addWidget(this->level);

    hLayout->addLayout(startLayout);
    hLayout->addLayout(levelLayout);
    cLayout->addWidget(this->image);
    vLayout->addLayout(hLayout);
    vLayout->addLayout(cLayout);

    widget->setLayout(vLayout);
}

QPoint MainWindow::filterSetPos(const QPoint &point)
{
    int size = this->getChessboardSize() - 1;

    int xPos = point.x() - this->p1.x();
    int yPos = point.y() - this->p1.y();
    double xStep = (double)xPos/(double)this->lengthEachStepX;
    double yStep = (double)yPos/(double)this->lengthEachStepY;

    QPoint retPoint((int)round(xStep),(int)round(yStep));

    if(retPoint.x() > size || retPoint.x() < 0 || retPoint.y() < 0 || retPoint.y() > size){
            return QPoint(-1,-1);
    }
    return retPoint;
}

void MainWindow::paintChessman(int x, int y, char chessman)
{
    QPainter* chessmanPaint = new QPainter(this);
    QColor chessmanColor1 = QColor(255,0,0,255);
    QColor chessmanColor2 = QColor(0,0,255,255);
    if('&' == chessman){
        chessmanPaint->setPen(QPen(chessmanColor1, 2));
        chessmanPaint->setBrush(chessmanColor1);
    }
    else if('@' == chessman){
        chessmanPaint->setPen(QPen(chessmanColor2, 2));
        chessmanPaint->setBrush(chessmanColor2);
    }
    else{

    }

    int xPos = this->p1.x() + (x)*this->lengthEachStepX;
    int yPos = this->p1.y() + (y)*this->lengthEachStepY;

    chessmanPaint->drawEllipse(QPoint(xPos,yPos),12,12);
    delete chessmanPaint;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    //qDebug()<<"xujiwei--->paintEvent";
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if (Qt ::LeftButton == e->button())
    {
        point1->setX(e->x());
        point1->setY(e->y());
        QPoint pos = this->filterSetPos(*this->point1);
        if(pos == QPoint(-1,-1)){
            QMessageBox::information(NULL,"invalid position","the position is out of Chessboard",
                                     QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            return;
        }
        emit this->setChessman(pos);
    }
}

void MainWindow::showEvent(QShowEvent *)
{
    qDebug()<<"showEvent";
}

void MainWindow::hideEvent(QHideEvent *)
{
    qDebug()<<"hideEvent";
}

void MainWindow::actionEvent(QActionEvent *)
{
    qDebug()<<"actionEvent";
}

void MainWindow::enterEvent(QEvent *)
{
    qDebug()<<"enterEvent";
}

void MainWindow::leaveEvent(QEvent *)
{
    qDebug()<<"leaveEvent";
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    qDebug()<<"resizeEvent";
}

int MainWindow::getChessboardSize() const
{
    return this->chessboardSize;
}

void MainWindow::setChessboardSize(int _size)
{
    this->chessboardSize = _size;
}

void MainWindow::changeEvent(QEvent *e)
{
    //QFlags flag = QFlags();
    if(this->windowState() == Qt::WindowNoState)
    {

    }
}

void MainWindow::flashChessboard(QStringList boardInfo)
{
    int k = 0;
    for(int i = 0; i < boardInfo.size(); i++){
        k = 0;
        for(int j = 0; j < boardInfo.at(i).size(); j += 2){
            const char chessman = boardInfo.at(i).at(j).toAscii();
            printf("%c ",chessman);
            if(chessman != '+'){
                this->paintChessman(k,i,chessman);
            }
            k++;
        }
        printf("\n");
    }
}

void MainWindow::startGame()
{
    int l = this->level->currentText().toInt();
	this->setChessboardSize(15);
    this->game->initGame(this->getChessboardSize(),l);
    this->hasStarted = true;
    this->flashChessboard(this->game->getChessboardInfo(true));
}

void MainWindow::makeStep(QPoint point)
{
    if(!this->hasStarted){
        return;
    }
    this->game->setPosition(point.y(),point.x());
    this->lastPos = point;
    this->flashChessboard(this->game->getChessboardInfo(false));
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->initUI();
    this->initGame = new QPushButton("Start game");

    connect(this->initGame,SIGNAL(clicked()),this,SLOT(startGame()));
    connect(this,SIGNAL(setChessman(QPoint)),this,SLOT(makeStep(QPoint)));

    this->label = new QLabel("Select level:");
    this->label->setAlignment(Qt::AlignRight);
    this->level = new QComboBox;

    this->level->addItem(QString("1"));
    this->level->addItem(QString("2"));
    this->level->addItem(QString("3"));
    this->p1 = QPoint(26,58);
    this->p2 = QPoint(446,58);
    this->p3 = QPoint(26,478);
    this->p4 = QPoint(446,478);
    this->lengthEachStepX = (this->p2.x() - this->p1.x())/14;
    this->lengthEachStepY = (this->p3.y() - this->p1.y())/14;
    this->centerWidget = new QWidget;
    this->setCentralWidget(this->centerWidget);
    this->initLayout(this->centerWidget);
}

MainWindow::~MainWindow()
{
    delete this->desktopWindow;
    delete this->game;
    delete this->client;
    delete this->level;
    delete this->chessboard;
    delete this->centerWidget;
    delete this->image;
}

void MainWindow::initUI()
{
    this->setAttribute(Qt::WA_PaintOutsidePaintEvent);
    this->desktopWindow = QApplication::desktop();
    this->client = new gobangClient;
    this->game = new gobang(client);

    this->chessboard = new QPixmap;
    if(!this->chessboard->load("./timg.jpg")){
        QMessageBox::information(NULL,"error!","load image failed!",
                                 QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return;
    }

    this->windowSize.setHeight(this->chessboard->size().height() + 50);
    this->windowSize.setWidth(this->chessboard->size().width() + 14);
    this->setMaximumSize(this->windowSize);
    this->setMinimumSize(this->windowSize);
    this->position = QPoint((this->desktopWindow->width() - this->width())/2, (this->desktopWindow->height() - this->height())/3);
    this->move(this->position);
    this->paint = new QPainter;
    this->point1 = new QPoint;
    this->hasStarted = false;
}
