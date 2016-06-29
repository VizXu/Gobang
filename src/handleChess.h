#ifndef _HANDLECHESS_
#define _HANDLECHESS_
#include"chessBoard.h"
#include"types.h"
class HandleChessBoard
{
private:
  char xChessman;
  char yChessman;
  U8 levels;
public:
  void setLevel();
  char getXChessman();
  char getYChessman();
public:
  void handleChessBoard(const ChessBoard&);
};
#endif//handleChess.h
