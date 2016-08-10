#include"person.h"
#include"chessBoard.h"
//#include"player.h"
#include"test.h"
#include"log.h"
#include<iostream>
string Person::getName()
{
  return this->name;
}

int Person::play(int _x,int _y,char ch,ChessBoard& chessboard)
{
   int flag=0;
   flag=setPosition(_x,_y,ch,chessboard);
 /*    LOG_BUG("x=%d,y=%d,ch=%c\n",_x,_y,ch);	 
   if(testWinner(_x,_y,ch,chessboard)){
     LOG_BUG("x=%d,y=%d,ch=%c\n",_x,_y,ch);	 
     std::cout<<"you win!"<<std::endl;
	 //chessboard.display();
   }
 */
   return flag;
}
