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
  return p1.getxPos()>=p2.getxPos();
}

bool srtVectorPosY(const Position& p1,const Position& p2)
{
  return p1.getyPos()>=p2.getyPos();
}
void HandleChessBoard::setLevel(U8 levels)
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
        case('+'):{
          Position position(i,j);
          blankPosition.push_back(std::move(position));
        break;}
        case('&'):{
          Position position(i,j);
          playerPosition.push_back(std::move(position));
          break;}
        case('#'):{
          Position position(i,j);
          computPosition.push_back(std::move(position));
          break;}
        default:
          throw "error chessman";
      }
    }
  }
  switch(levels){
    case 1:{
      int i=0;
      for(;i<blankPosition.size();i++)
        sort(blankPosition.begin();blankPosition.end();srtVectorPosX);
          xChessman=blankPosition[i/2].getxPos();
      for(i=0;i<blankPosition.size();i++)
        sort(blankPosition.begin();blankPosition.end();srtVectorPosY);
          yChessman=blankPosition[i/2].getyPos();
    break;}
    case 2:{break;}
    case 3:{break;}
    case 4:{break;}
    default: throw "out of levels";
  }
}
