#include"player.h"
void Player::setPosition(int _x,int _y,char ch,Chessboard& chessboard)
{
  this->posX=_x;
  this->posY=_y;
  chessBoard[_x][_y]=ch;
}
