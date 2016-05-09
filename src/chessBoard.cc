#include"chessBaord.h"
void ChessBaord::init()
{
  for(int i=0;i<BOARDSIZE;i++)
  {
    for(int j=0;j<BOARDSIZE;j++)
    chessBaord[i][j]='+';
  }
}
