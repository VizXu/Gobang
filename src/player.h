#ifndef _PLAYER_
#define _PLAYER_
#include<string>
class ChessBoard;
using std::string;
class Player
{
private:
   int gold;
   string name;
private:
   int posX;
   int posY;
private:
   int getX(){
      return posX;
   }   
   int getY(){
      return posY;
   }
public:
   string getName() const
   {
      return this->name;
   }
   int getGold() const
   {
      return this->gold;
   }
   void setPosition(int _x,int _y,char ch,ChessBoard& chessboard);
};
#endif//player.h
