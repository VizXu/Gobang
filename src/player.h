#ifndef _PLAYER_
#define _PLAYER_
#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include"chessmaninfo.h"
using std::unique_ptr;
using std::vector;
#define PIECES 50
class ChessBoard;
using std::string;
using std::cout;
using std::endl;
class Player
{
private:
   int gold;
   string name;
   vector<ChessmanInfo*> chessmInfo;//[PIECES];
private:
   int posX;// record the current position x and y
   int posY;
   unsigned int chessmanNumber;// record the number of chessman
public:
   void judgeWinner(int,int,string,ChessBoard&);
protected:
   int getX(){
      return posX;
   }   
   int getY(){
      return posY;
   }
   void recordChessmanInfo(int _x,int _y,int rcdPieces);
public:
   Player():gold(0),name("ZhangSan"),posX(0),posY(0),chessmanNumber(0){
      for(int i=0;i<PIECES;i++){
        chessmInfo.push_back(new ChessmanInfo);
      }
   }
   Player(string str):gold(0),name(str),posX(0),posY(0),chessmanNumber(0){
      for(int i=0;i<PIECES;i++){
        chessmInfo.push_back(new ChessmanInfo);
      }
   }
   ~Player(){}
   Player(const Player&)=delete;
   Player& operator=(const Player&)=delete;
protected:
   string getName() const
   {
      return this->name;
   }
   int getGold() const
   {
      return this->gold;
   }
   int setPosition(int _x,int _y,char ch,ChessBoard& chessboard);
   unsigned int getChessmanNumber(){return chessmanNumber;}
};

#endif//player.h

