#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMap>
#include <QtDebug>
#include <QMouseEvent>

#include "util.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *e);
    void mouseMoveEvent(QMouseEvent *e);

private:
    void createQipan(int colCount, int widthCount);
    void createQiZi(int posX, int posY, QColor color);
    void chessPosHelper(QColor color);
    double getDelta(QPoint point1, QPoint point2);
    double getMinValue(QList<double> list);

    int sideLength = 40; // 每个网格的边长
    int posX = 0, posY = 0; // 每个网格最左上方的坐标
    int startX = 20, startY = 20; // 整个网格的左上方的坐标
    int putPosX, putPosY; // 存储可放位置
    int helperBlockSize = 8; // 辅助标记的尺寸
    int allowDelta = 10; // 在允许的范围内，获取坐标大小
    int colCount = 6, rowCount = 6; // colCount x rowCount 的棋盘

    int radius = 20; // 棋的半径
};
#endif // MAINWINDOW_H
