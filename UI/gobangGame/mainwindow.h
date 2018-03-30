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
private:
    QPainter* paint;
    QPoint* point1;
    QWidget* centerWidget;
    QWidget* image;
    QComboBox* level;
    QPushButton* initGame;
    QPixmap* chessboard;
private:
    void initLayout(QWidget* widget);
private:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent * e);
signals:
    void setChessman(QPoint point);
public slots:
    void flashChessboard(ChessboardInfo &info);
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void initUI();
};

#endif // MAINWINDOW_H
