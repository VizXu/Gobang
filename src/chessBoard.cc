#include"chessBaord.h"
#include<cstdio>
void ChessBaord::init()
{
  for(int i=0;i<BOARDSIZE;i++)
  {
    for(int j=0;j<BOARDSIZE;j++)
    chessBaord[i][j]='+';
  }
}

void ChessBoard::displayChessBoard()
{
  for(int i=0;i<BOARDSIZE;i++){
    for(int j=0;j<BOARDSIZE;j++){
      printf("%2c",chessBoard[i][j]);
    }
      puts("");
  }
}
