#ifndef _CHESSBOARD_H
#define _CHESSBOARD_H
#define BOARDSIZE 10
#include"player.h"
class ChessBoard
{
private:
  char chessBoard[BOARDSIZE][BOARDSIZE];
  int  xPosition,yPosition;
private:
  //friend void Player::setPosition(int _x,int _y,char ch,ChessBoard& chessboard);//this is the friend function
private:
  void init();//initial the chess baord
public:
  void setPos(int _x,int _y,char ch);
  bool isLegal(int _x,int _y);
public:
  ChessBoard(){
    init();
  }
  ~ChessBoard(){}
  ChessBoard(const ChessBoard&)=delete;
  ChessBoard& operator=(const ChessBoard&)=delete;
public:
  void displayChessBoard();//show the chess baord
  char chessInfo(int _x,int _y);
  char getChessman(int,int);
};
#endif//chessBoard.h
