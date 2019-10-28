#include "mainwindow.h"
#include <qmath.h>
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMouseTracking(true);
    //qDebug() << getDelta(QPoint(0, 0), QPoint(1, 1));

}

MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)

    // 3 x 3 的棋盘
    createQipan(colCount, rowCount);

    // 在 (60, 60) 处放置棋子
    createQiZi(60, 60, Qt::black);
//    createQiZi(100, 60, Qt::white);
}

void MainWindow::createQipan(int colCount, int rowCount)
{
    // 自动生成网格
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::black));
    painter.setBrush(Qt::white);

    for (int i = 0; i < colCount; i++) {
        for (int j = 0; j < rowCount; j++) {
            posX = startX + i * sideLength;
            posY = startY + j * sideLength;

            painter.drawRect(posX, posY, sideLength, sideLength);
        }
    }
}


void MainWindow::createQiZi(int x, int y, QColor color)
{
    // (x, y): 棋子的中心坐标
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::black);
    painter.setBrush(color);

    painter.drawEllipse(x - radius, y - radius, radius * 2, radius * 2);
}


double MainWindow::getDelta(QPoint point1, QPoint point2)
{
    return qSqrt(qPow(qAbs(point1.x() - point2.x()), 2) +
                 qPow(qAbs(point1.y() - point2.y()), 2));
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    int x = e->x();
    int y = e->y();

    //qDebug() << x << y;

    int allowDelta = 4;
    int delta;
    QList<int> deltaList;

    // 距离在一定范围内，就可以点击放置
    for (int i = 0; i < colCount; i++) {
        for (int j = 0; j < rowCount; j++) {
            posX = startX + i * sideLength;
            posY = startY + j * sideLength;

            if (posX != startX && posY != startY &&
                posX != startX + colCount * sideLength &&
                posY != startY + rowCount * sideLength)
            {
               QPoint p1(posX, posY);
               QPoint p2(x, y);
               delta = getDelta(p1, p2);

               deltaList.append(delta);
               qDebug() << deltaList;
            }
        }
    }

    // 重绘
    //update();
}
