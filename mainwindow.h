#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMap>
#include <QtDebug>
#include <QMouseEvent>

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
    double getDelta(QPoint point1, QPoint point2);

    int sideLength = 40; // 每个网格的边长
    int posX = 0, posY = 0; // 每个网格最左上方的坐标
    int startX = 20, startY = 20; // 整个网格的左上方的坐标

    int radius = 20; // 棋的半径
    int colCount = 2, rowCount = 2;
};
#endif // MAINWINDOW_H
