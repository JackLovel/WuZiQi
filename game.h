#ifndef GAME_H
#define GAME_H

#include <QVector>

enum GameType {
    PERSON, // 人
    BOT  // 机器
};

// 游戏状态
enum GameStatus {
    PLAYING,
    WIN,
    DEAD
};


class Game
{
public:
    Game();
    ~Game();

    QVector<QVector<int>> gameMapVec;
    QVector<QVector<int>> scoreMapVec;
    bool playerFlag; // 标示下棋方
    GameType gameType; // 游戏模式
    GameStatus gameStatus; // 游戏状态

   void startGame(GameType type); //开始游戏
   void caculateScore(); // 计算评分
   void actionByPerson(int row, int col);
   void actionByAI(int row, int col);
   void updateGameMap(int row, int col);

   bool isWin(int row, int col);
   bool isDeadGame(); // 判断和棋
};

#endif // GAME_H
