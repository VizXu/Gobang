#ifndef _CHESSBOARD_H
#define _CHESSBOARD_H
#define BAORDSIZE 10
#include"player.h"
class ChessBoard
{
private:
  char chessboard[BAORDSIZE][BAORDSIZE];
  int  xPosition,yPosition;
private:
  friend void Player::setPosition(int _x,int _y,char ch,ChessBoard& chessboard);//this is the friend function
private:
  bool isLegal(int _x,int _y);
  void init();//initial the chess baord
public:
  ChessBoard(){
    init();
  }
  ~ChessBoard(){}
  ChessBoard(const ChessBoard&)=delete;
  ChessBoard& operator=(const ChessBoard&)=delete;
public:
  void displayChessBoard();//show the chess baord
};
#endif//chessBoard.h
