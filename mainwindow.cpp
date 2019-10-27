#include "mainwindow.h"

#include <QPainter>
#include <QMap>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //setFixedSize(600, 500);
}

MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)

    // 15 x 15 的棋盘
    createQipan(15, 15);

    // 在 (60, 60) 处放置棋子
    createQiZi(60, 60);
}


void MainWindow::createQipan(int colCount, int rowCount)
{
    // 自动生成网格

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::black));
    painter.setBrush(Qt::white);

    // 3 x 3
    int sideLength = 40; // 每个网格的边长
    int posX = 0, posY = 0; // 每个网格最左上方的坐标
    int startX = 20, startY = 20; // 整个网格的左上方的坐标
    for (int i = 0; i < colCount; i++) {
        for (int j = 0; j < rowCount; j++) {
            posX = startX + i * sideLength;
            posY = startY + j * sideLength;

            painter.drawRect(posX, posY, sideLength, sideLength);
        }
    }
}

void MainWindow::createQiZi(int posX, int posY)
{
    // 棋子
    int radius = 20; // 圆的半径
//    int posX = 60, posY = 60; // 圆中心坐标

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::NoPen));
    painter.setBrush(Qt::black);

    painter.drawEllipse(posX - radius, posY - radius, radius * 2, radius * 2);
}
