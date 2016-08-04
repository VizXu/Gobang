#include"player.h"
#include"test.h"
#include"chessBoard.h"
#include<unistd.h>
#include<iostream>
int Player::setPosition(int _x,int _y,char ch,ChessBoard& chessboard)
{
  this->posX=_x;
  this->posY=_y;
  if(chessboard.isLegal(_x,_y)){
       chessmanNumber++;
       chessboard.setPos(_x,_y,ch);
	   if(testWinner(_x,_y,ch,chessboard)) 
	     {
		  //judge the ch='&' or '#'  
		     std::cout<<std::endl;
			// system("clear");
			 std::cout<<"you win:"<<ch<<std::endl;
		 }//add 2016-8-2
       recordChessmanInfo(_x,_y,3);
       return 0;
  }
  else{
       std::cout<<"the position is not legal,please set other position!"<<std::endl;
       //setPosition(_x,_y,ch,chessboard);
       return -1;
  }
}

void Player::recordChessmanInfo(int _x,int _y,int rcdPieces)
{
  //record the infomation of chessman to AI 
  chessmInfo[rcdPieces]->storeChessmanInfo(_x,_y);
}
