#include "mainwindow.h"

#include <QPainter>
#include <QMap>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createQipan(3, 2);
}

MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)

    createQipan(4, 4);
}


void MainWindow::createQipan(int colCount, int rowCount)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::black));
    painter.setBrush(Qt::white);

    // 3 x 3
    int sideLength = 40; // 每个网格的边长
    int posX = 0, posY = 0;
    int startX = 20, startY = 20;
    for (int i = 0; i < colCount; i++) {
        for (int j = 0; j < rowCount; j++) {
            posX = startX + i * sideLength;
            posY = startY + j * sideLength;

            painter.drawRect(posX, posY, sideLength, sideLength);
        }
    }
}
