#ifndef UTIL_H
#define UTIL_H

#include <QObject>

class Util : public QObject
{
public:
    static int colCount, rowCount; // colCount x rowCount的棋盘
};

#endif // UTIL_H
