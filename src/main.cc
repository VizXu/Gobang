#include<iostream>
#include"chessBoard.h"
#include"person.h"
using std::cout;
using std::endl;
int main()
{
  ChessBoard chessBoard;
  Person person;
  chessBoard.displayChessBoard();
  person.play(2,3,'#',chessBoard);
  cout<<"-----------------"<<endl;
  chessBoard.displayChessBoard();
return 0;
}
