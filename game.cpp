#include "game.h"

#include <QTime>
#include "mainwindow.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::startGame(GameType type)
{
    gameType = type;

    gameMapVec.clear();


}

