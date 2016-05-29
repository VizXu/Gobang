#include"player.h"
#include"chessBoard.h"
#include<iostream>
void Player::setPosition(int _x,int _y,char ch,ChessBoard& chessboard)
{
  this->posX=_x;
  this->posY=_y;
  if(chessboard.isLegal(_x,_y)){
       chessmanNumber++;
       chessboard.setPos(_x,_y,ch);
       recordChessmanInfo();
  }
  else
    std::cout<<"the position is not legal,please set other position!"<<std::endl;
}
