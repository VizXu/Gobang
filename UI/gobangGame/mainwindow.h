#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSize>
#include <QDesktopWidget>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QMouseEvent>
#include <QDebug>
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
private:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent * e);
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void initUI();
};

#endif // MAINWINDOW_H
