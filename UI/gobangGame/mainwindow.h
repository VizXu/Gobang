#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSize>
#include <QDesktopWidget>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QMouseEvent>
#include <QPushButton>
#include <QDebug>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include <QImage>
#include <QLabel>
#include <QPixmap>
#include "gobang.h"
#include "gobangclient.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    gobangClient* client;
    gobang* game;
    QSize windowSize;
    QDesktopWidget* desktopWindow;
    QPoint position;
    int chessboardSize;
private:
    //four positions
    QPoint p1;//(34,62);
    QPoint p2;//(684,62);
    QPoint p3;//(34,508);
    QPoint p4;//(684,508);
    int lengthEachStepX;
    int lengthEachStepY;
    bool hasStarted;
private:
    QPainter* paint;
    QPoint* point1;
    QWidget* centerWidget;
    QLabel* label;
    QWidget* image;
    QComboBox* level;
    QPushButton* initGame;
    QPixmap* chessboard;
    QPoint lastPos;
private:
    void initLayout(QWidget* widget);
    QPoint filterSetPos(const QPoint& point);
    void paintChessman(int x, int y, char chessman);
private:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent * e);
public:
    int getChessboardSize() const;
    void setChessboardSize(int _size);
    void changeEvent(QEvent * e);
signals:
    void setChessman(QPoint point);
public slots:
    void flashChessboard(QStringList boardInfo);
    void startGame();
    void makeStep(QPoint point);
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void initUI();
};

#endif // MAINWINDOW_H
