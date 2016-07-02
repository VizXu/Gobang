#ifndef _HANDLECHESS_
#define _HANDLECHESS_
#include"chessBoard.h"
#include"types.h"
class HandleChessBoard
{
private:
  int xChessman;
  int yChessman;
  U8 levels;
public:
  void setLevel(U8 levels);
  int getXChessman();
  int getYChessman();
  U8  getLevel();
public:
  void handleChessBoard(const ChessBoard&);
};
#endif//handleChess.h
