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

Position Computer::level1(const ChessBoard& chessboard)
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

Position Computer::level2(const ChessBoard& chessboard)
{
  
}

Position Computer::level3(const ChessBoard& chessboard)
{
  
}

Position Computer::level4(const ChessBoard& chessboard)
{
  
}

int Computer::setPos(ChessBoard& chessboard)
{
  switch(levels){
    case 1:level1(chessboard);break;
    case 2:level2(chessboard);break;
    case 3:level3(chessboard);break;
    case 4:level4(chessboard);break;
    default:break;
  }
  return setPosition(position.getX(),position.getY(),'&',chessboard);
}
