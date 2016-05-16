#ifndef _CHESSBOARD_H
#define _CHESSBOARD_H
#define BAORDSIZE 10
class ChessBoard
{
private:
  char chessboard[BAORDSIZE][BAORDSIZE];
private:
  void init();//initial the chess baord
public:
  void displayChessBoard();//show the chess baord
};
#endif//chessBoard.h
