#ifndef _PLAYER_
#define _PLAYER_
#include"chessmaninfo.h"
#define PIECES 5
#include<string>
class ChessBoard;
using std::string;
class Player
{
private:
   int gold;
   string name;
   ChessmanInfo* chessmInfo[PIECES];
private:
   int posX;// record the current position x and y
   int posY;
   unsigned int chessmanNumber// record the number of chessman
private:
   int getX(){
      return posX;
   }   
   int getY(){
      return posY;
   }
   void recordChessmanInfo(int _x,int _y,int rcdPieces);
public:
   Player():gold(0),name("ZhangSan"),posX(0),posY(0),chessmanNumber(0),chessmInfo(new ChessmanInfo[PIECES]){}
   Player(string str):gold(0),name(str),posX(0),posY(0),chessmanNumber(0),chessmInfo(new ChessmanInfo[PIECES]){}
   ~Player(){delete chessmInfo;}
   Player(const Playerr&)=delete;
   Player& operator=(const Player&)=delete;
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
