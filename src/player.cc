#include"player.h"
#include<iostream>
void Player::setPosition(int _x,int _y,char ch,Chessboard& chessboard)
{
  this->posX=_x;
  this->posY=_y;
  if(chessboard.isLegal(_x,_y))
      chessBoard[_x][_y]=ch;
  else
    std::cout<<"the position is not legal,please set other position!"<<std::endl;
}
