#include"chessBoard.h"
#include"handleChess.h"
#include<vector>
#include<memory>
#include<algorithm>
using std::move;
using std::vector;
using std::sort;

bool srtVectorPosX(const Position& p1,const Position& p2)
{
  return p1.xPos>=p2.xPos;
}

bool srtVectorPosY(const Position& p1,const Position& p2)
{
  return p1.yPos>=p2.yPos;
}
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
  //vector<vector<int> > blankPosition;
  //vector<vector<int> > playerPosition;
  //vector<vector<int> > computPosition;
  //vector<vector<int> >::iterator iPtr;
  U8 levels=getLevel();
  for(int i=0;i<BOARDSIZE;++i){
    for(int j=0;j<BOARDSIZE;++j){
      switch(chessboard.getChessman(i,j)){
        case('+'):
          Position position(i,j);
          vector<Position> blankPosition.push_back(std::move(position));
        break;
        case('&'):
          Position position(i,j);
          vector<Position> playerPosition.push_back(std::move(position));
          break;
        case('#'):
          Position position(i,j);
          vector<Position> computPosition.push_back(std::move(position));
          break;
        default:
          throw "error chessman";break;
      }
    }
  }
  switch(levels){
    case 1:break;
    case 2:break;
    case 3:break;
    case 4:break;
    default: throw "out of levels";break;
  }
}
