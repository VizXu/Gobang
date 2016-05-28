#include<iostream>
#include"chessBoard.h"
#include"player.h"
using std::cout;
using std::endl;
int main()
{
  ChessBoard chessBoard;
  Player player;
  chessBoard.displayChessBoard();
  player.setPosition(2,3,'#',chessBoard);
  cout<<"-----------------"<<endl;
  chessBoard.displayChessBoard();
return 0;
}
