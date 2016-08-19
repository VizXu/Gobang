#include"chessBoard.h"
#include"handleChess.h"
#include"log.h"
#include<vector>
#include<memory>
#include<algorithm>
#include<iostream>
using std::cout;
using std::endl;
using std::move;
using std::vector;
using std::sort;

bool srtVectorPosX(const PositionHandle& p1,const PositionHandle& p2)
{
  return p1.getxPos()>=p2.getxPos();
}

bool srtVectorPosY(const PositionHandle& p1,const PositionHandle& p2)
{
  return p1.getyPos()>=p2.getyPos();
}
void HandleChessBoard::setLevel(U8 levels)
{
  this->levels=levels;
}

//test anbient chessman number of each position function

int HandleChessBoard::testNumbersChessman(int posX,int posY,vector<PositionHandle> & positionVal)
{
  //x direction
  //-x direction
  //y direction
  //-y direction
  //xy direction
  //x-y direction
  //-xy direction
  //-x-y direction
return 0;
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

void HandleChessBoard::handleChessBoard(ChessBoard& chessboard)
{
  U8 levels=getLevel();
  for(int i=0;i<BOARDSIZE;++i){
    for(int j=0;j<BOARDSIZE;++j){
      switch(chessboard.getChessman(i,j)){
        case('+'):{
          PositionHandle tmpPosition(i,j);
		 // tmpPosition.set(i,j);
          blankPosition.push_back(std::move(tmpPosition));
        break;}
        case('&'):{
          PositionHandle tmpPosition(i,j);
		  //tmpPosition.set(i,j);
          playerPosition.push_back(std::move(tmpPosition));
          break;}
        case('#'):{
          PositionHandle tmpPosition(i,j);
		  //tmpPosition.set(i,j);
          computPosition.push_back(std::move(tmpPosition));
          break;}
        default:
          throw "error chessman";
      }
    }
  }
  switch(levels){
    case 1:{
			int bp=blankPosition.size();
		    int position=bp/2;
			sort(blankPosition.begin(),blankPosition.end(),srtVectorPosX);
			xChessman=blankPosition[position].getxPos();
			yChessman=blankPosition[position].getyPos();
            break;
		   }
    case 2:{
			int pp=playerPosition.size();
			for(int i=0;i<pp;i++){
				//analyse player position ----add by xujiwei 2016-8-16
			}
			   break;
		   }
    case 3:{break;}
    case 4:{break;}
    default: throw "out of levels";
  }
}
