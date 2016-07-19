#ifndef _HANDLECHESS_
#define _HANDLECHESS_
#include"chessBoard.h"
#include"types.h"
#include<cstdlib>
#include<ctime>
#include<vector>
using std::vector;
class ChessBoard;

class PositionHandle
{
private:
  int xPos;
  int yPos;
public:
  PositionHandle(int i=0,int j=0):xPos(i),yPos(j){}
  ~PositionHandle(){}
public:
  //void set(int i=0,int j=0){this->xPos=i;this->yPos=j;}
  int getxPos()const {return this->xPos;}
  int getyPos()const {return this->yPos;}
};
class HandleChessBoard
{
private:
  int xChessman;
  int yChessman;
  U8 levels;
private:
  vector<PositionHandle> blankPosition;
  vector<PositionHandle> playerPosition;
  vector<PositionHandle> computPosition;
  vector<PositionHandle>::iterator iPtr;
public:
  void setLevel(U8 levels);
  int getXChessman();
  int getYChessman();
private:
  U8  getLevel();
public:
  HandleChessBoard(){
    srand(time(NULL));
  }
  ~HandleChessBoard(){}
public:
  void handleChessBoard(const ChessBoard&);
};
#endif//handleChess.h
