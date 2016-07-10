#ifndef _HANDLECHESS_
#define _HANDLECHESS_
#include"chessBoard.h"
#include"types.h"
#include<vector>
using std::vector;
class ChessBoard;

class Position
{
private:
  int xPos;
  int yPos;
public:
  Position(int i=0,int j=0):xPos(i),yPos(j){}
  ~Position(){}
public:
  int getxPos(){return this->xPos;}
  int getyPos(){return this->yPos;}
};
class HandleChessBoard
{
private:
  int xChessman;
  int yChessman;
  U8 levels;
private:
  vector<Position> blankPosition;
  vector<Position> playerPosition;
  vector<Position> computPosition;
  vector<Position>::iterator iPtr;
public:
  void setLevel(U8 levels);
  int getXChessman();
  int getYChessman();
private:
  U8  getLevel();
public:
  void handleChessBoard(const ChessBoard&);
};
#endif//handleChess.h
