#include"person.h"
#include"chessboard"
#include"player.h"
string Person::getName()
{
  return this->name;
}

int Person::play(int _x,int _y,char ch,ChessBoard& chessboard)
{
  return setPosition(_x,_y,ch,chessboard);
}
