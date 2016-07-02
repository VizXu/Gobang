#include"chessBoard.h"
#include"handleChess.h"

void HandleChessBoard::setLevels(U8 levels)
{
  this->levels=levels;
}

U8 HandleChessBoard::getLevel()
{
  return this->levels;
}

int HandleChessBoard::getXChessman()
{
  return this->xChessman;
}

int HandleChessBoard::getYChessman()
{
  return this->yChessman;
}
