#ifndef _CHESSBOARD_H
#define _CHESSBOARD_H
#define BAORDSIZE 10
#include"player.h"
class ChessBoard
{
private:
  char chessboard[BAORDSIZE][BAORDSIZE];
private:
  friend void Player::setPosition(int _x,int _y,ChessBoard& chessboard);//this is the issue!!!
private:
  void init();//initial the chess baord
public:
  void displayChessBoard();//show the chess baord
};
#endif//chessBoard.h
