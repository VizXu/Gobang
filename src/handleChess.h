#ifndef _HANDLECHESS_
#define _HANDLECHESS_
#include"chessBoard.h"
#include"types.h"
#include<cstdlib>
#include<ctime>
#include<vector>
using std::vector;
class ChessBoard;

enum Direction
{
XPLUSDirection,
XNEGADirection,
YPLUSDirection,
YNEGADirection,
XPLUSYPLUSDirection,
XPLUSYNEGADirection,
XNEGAYPLUSDirection,
XNEGAYNEGADirection
};

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
  Direction direction;
private:
  vector<PositionHandle> blankPosition;
  vector<PositionHandle> playerPosition;
  vector<PositionHandle> computPosition;
  vector<PositionHandle>::iterator iPtr;
public:
  void setLevel(U8 levels);
  int getXChessman();
  int getYChessman();
  void setDirection(U8);
  bool haveTry(int,int);
  Direction getDirection();
private:
  U8  getLevel();
  U8  maxVal(U8 x,U8 y){
        return x>=y?x:y;
      }
public:
  HandleChessBoard(){
    srand(time(NULL));
  }
  ~HandleChessBoard(){}
public:
  void handleChessBoard(ChessBoard&);
private:
  //to test anbient chessman numbers of each position
  U8 testNumbersChessman(int,int,vector<PositionHandle> &);
};
#endif//handleChess.h
