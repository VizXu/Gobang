#include "mainwindow.h"
#include <QDebug>
#include <QPoint>
#include <QApplication>

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
                this->size(),
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

void MainWindow::paintEvent(QPaintEvent *)
{

}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
//    QPainter tmpP(this);
    if (Qt ::LeftButton == e->button())
    {
        point1->setX(e->x());
        point1->setY(e->y());
        qDebug()<<"xujiwei--->x = "<<e->x()<<",y = "<<e->y();
        //tmpP.drawEllipse(point1->x(),point1->y(),15,15);
    }
}

void MainWindow::flashChessboard(QStringList boardInfo)
{
    qDebug()<<"flash chessboard";
    qDebug()<<"info size = "<<boardInfo.size();
    for(int i = 0; i < boardInfo.size(); i++){
        qDebug()<<"flash line "<<i<<" = "<<boardInfo.at(i);
    }
    //if()
}

void MainWindow::startGame()
{
    this->game->initGame(10,1);
    this->flashChessboard(this->game->getChessboardInfo());
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->initUI();
    this->initGame = new QPushButton("Start game");

    connect(this->initGame,SIGNAL(clicked()),this,SLOT(startGame()));

    this->label = new QLabel("Select level:");
    this->label->setAlignment(Qt::AlignRight);
    this->level = new QComboBox;
    this->chessboard = new QPixmap;
    if(!this->chessboard->load("./timg.jpg")){
        qDebug()<<"load image error!";
    }
    this->level->addItem(QString("1"));
    this->level->addItem(QString("2"));
    this->level->addItem(QString("3"));
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
    this->windowSize = QSize(700,520);
    this->setMaximumSize(this->windowSize);
    this->setMinimumSize(this->windowSize);
    this->position = QPoint((this->desktopWindow->width() - this->width())/2, (this->desktopWindow->height() - this->height())/3);
    this->move(this->position);
    this->paint = new QPainter;
    this->point1 = new QPoint;
}
