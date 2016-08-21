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
using std::find;
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

U8 HandleChessBoard::testNumbersChessman(int posX,int posY,vector<PositionHandle> & positionVal)
{
  //x-y direction
  //-xy direction
  //-x-y direction
  U8 flagx=0;
  U8 flag_x=0;
  U8 flagy=0;
  U8 flag_y=0;
  U8 flagxy=0;
  U8 flagx_y=0;
  U8 flag_xy=0;
  U8 flag_x_y=0;
  
  vector<PositionHandle>::iterator positionPtr;
  for(int i=posX;i<BOARDSIZE;i++){
  //x direction
	U8 cnt=flagx;
    for(positionPtr=positionVal.begin();positionPtr!=positionVal.end();positionPtr++){
	    if((positionPtr->getxPos()==i)&&(positionPtr->getyPos()==posY)){
	      flagx++;
     	}
    	else{
	      continue;
    	}
	}

	if(cnt==flagx+1){
	   continue; //found it, then to next position and check it
	}
	else{
	   break;
	}
  }

  for(int i=posX;i>=0;i--){
  //-x direction
    U8 cnt=flag_x;
    for(positionPtr=positionVal.begin();positionPtr!=positionVal.end();positionPtr++){
	  if((positionPtr->getxPos()==i)&&(positionPtr->getyPos()==posY)){
	    flag_x++;
	  }
	  else{
	    continue;
	  }
	}
    
    if(cnt==flag_x+1){
      continue;
    }
    else{
      break;
    }
  }


  for(int j=posY;j>=0;j--){
  //y direction
    U8 cnt=flagy;
     for(positionPtr=positionVal.begin();positionPtr!=positionVal.end();positionPtr++){
	   if((positionPtr->getxPos()==posX)&&(positionPtr->getyPos()==j)){
	    flagy++; 
	   }
	   else{
	    continue;
	   }
	 }

	 if(cnt==flagy+1){
	   continue;
	 }
	 else{
	  break;
	 }
  }


  for(int j=posY;j<BOARDSIZE;j++){
  //-y direction
   U8 cnt=flag_y;
   for(positionPtr=positionVal.begin();positionPtr!=positionVal.end();positionPtr++){
    if((positionPtr->getxPos()==posX)&&(positionPtr->getyPos()==j)){
	 flag_y++;
	}
	else{
	 continue;
	}
   }

   if(cnt==flag_y+1){
    continue;
   }
   else{
    break;
   }
  }

  for(int i=posX,j=posY;i<BOARDSIZE&&j>=0;i++,j--){
  //xy direction

  U8 cnt=flagxy;
   for(positionPtr=positionVal.begin();positionPtr!=positionVal.end();positionPtr++){
    if((positionPtr->getxPos()==i)&&(positionPtr->getyPos()==j)){
	 flagxy++;
	}
	else{
	 continue;
	}
   }

   if(cnt==flagxy+1){
    continue;
   }
   else{
    break;
   }
  }
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
