#include"computer.h"
#include"chessBoard.h"
U8 Computer::getLevel()
{
  return this->levels;
}

string Computer::getName()
{
  return this->name;
}

void Computer::setLevel(U8 level)
{
  this->levels=level;
}

Position Computer::level1()
{
  int xP;
  int yP;
  xP=rand()%BOARDSIZE;
  yP=rand()%BOARDSIZE;
  return Position(xP,yP);
}

Position Computer::level2()
{
  
}

Position Computer::level3()
{
  
}

Position Computer::level4()
{
  
}
