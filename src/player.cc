#include"player.h"
#include"test.h"
#include"chessBoard.h"
#include<unistd.h>
#include<iostream>
#include<cstdlib>
//#include"judge.h"
using std::string;
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
			 string tmpName=this->name;
			// std::cout<<this->name<<" you win:"<<ch<<std::endl;
			judgeWinner(_x,_y,tmpName,chessboard);
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

void Player::judgeWinner(int _x,int _y,string tmpName,ChessBoard& chessboard)
{
   string name=tmpName;
   system("clear");
   cout<<"----------GAME OVER-----------"<<endl;
   chessboard.displayChessBoard();
   cout<<"Congratulations,"<<name<<" you won this game!!!"<<endl;
   cout<<"you finally set the position is:"<<"x="<<_x<<",y="<<_y<<endl;
   cout<<"----------GAME OVER-----------"<<endl;
   exit(0);
}
