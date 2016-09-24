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
  char player;
public:
  PositionHandle(int i=0,int j=0,char c='+'):xPos(i),yPos(j),player(c){}
  ~PositionHandle(){}
public:
  //void set(int i=0,int j=0){this->xPos=i;this->yPos=j;}
  int getxPos()const {return this->xPos;}
  int getyPos()const {return this->yPos;}
  int getPlayer() const { return this->player;}
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
private:  //for tmporary store the board information 
  char tmpBoard[BOARDSIZE][BOARDSIZE];
  void storeBoard(vector<PositionHandle> &);
public:
  void setLevel(U8 levels);
  int getXChessman();
  int getYChessman();
  void setDirection(U8);
  bool haveTry(int,int);
  Direction getDirection();
  bool isBlank(int,int);
private:
  U8  getLevel();
  U8  maxVal(U8 x,U8 y){
        return x>=y?x:y;
      }
public:
  HandleChessBoard(){
    srand(time(NULL));
	for(int i=0;i<BOARDSIZE;i++){
	   for(int j=0;j<BOARDSIZE;j++){
	      tmpBoard[i][j]='+';
	   }
	}
  }
  ~HandleChessBoard(){}
public:
  void handleChessBoard(ChessBoard&);
private:
  //to test anbient chessman numbers of each position
  U8 testNumbersChessman(int,int,vector<PositionHandle> &);
};
#endif//handleChess.h
