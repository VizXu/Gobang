#include"chessBoard.h"
#include"handleChess.h"
#include<vector>
#include<memory>
using std::move;
using std::vector;
void HandleChessBoard::setLevels(U8 levels)
{
  this->levels=levels;
}

U8 HandleChessBoard::getLevel()
{
  return this->levels;
}

int HandleChessBoard::getXChessman()
{
  return this->xChessman;
}

int HandleChessBoard::getYChessman()
{
  return this->yChessman;
}

void HandleChessBoard::handleChessBoard(const ChessBoard& chessboard)
{
  //to make decision of the position to set chessman
  vector<vector<int> > blankPosition;
  vector<vector<int> > playerPosition;
  vector<vector<int> > computPosition;
  vector<vector<int> >::iterator iPtr;
  U8 levels=getLevel();
  for(int i=0;i<BOARDSIZE;++i){
    for(int j=0;j<BOARDSIZE;++j){
      switch(chessboard.getChessman(i,j)){
        case('+'):;
      }
    }
  }
}
