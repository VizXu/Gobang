#include"chessBoard.h"

void copyChessBoard(char chessBoard[BOARDSIZE][BOARDSIZE],ChessBoard& chessboard)
{
  for(int i=0;i<BOARDSIZE;i++){
    for(int j=0;j<BOARDSIZE;j++){
     chessBoard[i][j]='+';
    }
  }
  for(int i=0;i<BOARDSIZE;i++){
    for(int j=0;j<BOARDSIZE;j++){
     chessBoard[i][j]=chessboard.getChessman(i,j);
    }
  }
}

void judgeValueDegree(char chessBoard[BOARDSIZE][BOARDSIZE],int value[BOARDSIZE][BOARDSIZE])
{
  for(int i=0;i<BOARDSIZE;i++){
    for(int j=0;j<BOARDSIZE;j++){
      switch(chessBoard[i][j]){
        case '+': value[i][j]+=1;break;
        case '&': value=0;  break;
        case '#': value=0;  break;
        default: value=0;break;
      }
    }
  }
}
