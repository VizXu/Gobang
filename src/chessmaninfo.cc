#include"chessmaninfo.h"
int ChessmanInfo::getXPosition()
{
  return this->xPosition;
}

int ChessmanInfo::getYPosition()
{
  return this->yPosition;
}

void ChessmanInfo::storeChessmanInfo(int _x,int _y)
{
  this->xPosition=_x;
  this->yPosition=_y;
}
