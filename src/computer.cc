#include"computer.h"
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
  if(0==getChessmanNumber()){
    xP=rand()%BOARDSIZE;
    yP=rand()%BOARDSIZE;
    this->position.setXY(xP,yP);
    return Position(xP,yP);
  }else{
    //handle chessmanInfo
  }
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

int Computer::setPos(ChessBoard& chessboard)
{
  switch(levels){
    case 1:level1();break;
    case 2:level2();break;
    case 3:level3();break;
    case 4:level4();break;
    default:break;
  }
  return setPosition(position.getX(),position.getY(),'&',chessboard);
}
