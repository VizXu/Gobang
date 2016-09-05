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

void HandleChessBoard::setDirection(U8 d)
{
  switch(d){
	  case 1: direction=XPLUSDirection;        break;
	  case 2: direction=XNEGADirection;        break;
	  case 3: direction=YPLUSDirection;        break;
	  case 4: direction=YNEGADirection;        break;
	  case 5: direction=XPLUSYPLUSDirection;   break;
	  case 6: direction=XPLUSYNEGADirection;   break;
	  case 7: direction=XNEGAYPLUSDirection;   break;
	  case 8: direction=XNEGAYNEGADirection;   break;
  }  
}

Direction HandleChessBoard::getDirection()
{
  return this->direction;
}
U8 HandleChessBoard::testNumbersChessman(int posX,int posY,vector<PositionHandle> & positionVal)
{

  U8 flagx=0;
  U8 flag_x=0;
  U8 flagy=0;
  U8 flag_y=0;
  U8 flagxy=0;
  U8 flagx_y=0;
  U8 flag_xy=0;
  U8 flag_x_y=0;

  U8 d;

  vector<PositionHandle>::iterator positionPtr;
  for(int i=posX;i<BOARDSIZE;i++){
  //x direction
	U8 cnt=flagx;
    for(positionPtr=positionVal.begin();positionPtr!=positionVal.end();positionPtr++){
	    if((positionPtr->getxPos()==posX)&&(positionPtr->getyPos()==i)){
		  //add by xujiwei----2016-9-1 for debuging
	      flagx++;
		 // LOG_BUG("i=%d,positionPtr->getxPos()=%d,positionPtr->getyPos()=%d\n",i,positionPtr->getxPos(),positionPtr->getyPos());
		 // LOG_BUG("flagx:i=%d,posX=%d,posY=%d,flagx=%d\n",i,posX,posY,flagx);
	      //	  flagx++;
     	}
    	else{
		//LOG_BUG("\n+++\n");
		//  LOG_BUG("i=%d,positionPtr->getxPos()=%d,positionPtr->getyPos()=%d\n",i,positionPtr->getxPos(),positionPtr->getyPos());
	        continue;
    	}
	}

	if(cnt==flagx+1){
	   	continue; //found it, then to next position and check it
	}
	else{
	  // break;
	}
  }

  for(int i=posX;i>=0;i--){
  //-x direction
    U8 cnt=flag_x;
    for(positionPtr=positionVal.begin();positionPtr!=positionVal.end();positionPtr++){
	  if((positionPtr->getxPos()==i)&&(positionPtr->getyPos()==posY)){
	    flag_x++;
		LOG_BUG("i=%d,positionPtr->getxPos()=%d,positionPtr->getyPos()=%d\n",i,positionPtr->getxPos(),positionPtr->getyPos());
		LOG_BUG("flagx:i=%d,posX=%d,posY=%d,flagx=%d\n",i,posX,posY,flagx);
	  }
	  else{
		LOG_BUG("i=%d,positionPtr->getxPos()=%d,positionPtr->getyPos()=%d\n",i,positionPtr->getxPos(),positionPtr->getyPos());
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

  for(int i=posX,j=posY;i<BOARDSIZE&&j<BOARDSIZE;i++,j++){
  //x-y direction
  //
  U8 cnt=flagx_y;
  for(positionPtr=positionVal.begin();positionPtr!=positionVal.end();positionPtr++){
   if((positionPtr->getxPos()==i)&&(positionPtr->getyPos()==j)){
     	flagx_y++;
    }
   else{
	 continue;
    }
   }

   if(cnt==flagx_y+1){
    continue;
   }
   else{
    break;
   }
  }

  for(int i=posX,j=posY;i>=0&&j>=0;i--,j--){
  //-xy direction
   U8 cnt=flag_xy;
   for(positionPtr=positionVal.begin();positionPtr!=positionVal.end();positionPtr++){
    if((positionPtr->getxPos()==i)&&(positionPtr->getyPos()==j)){
	 flag_xy++;
	}
	else{
	 continue;
	}
   }
   
   if(cnt==flag_xy+1){
    continue;
   }
   else{
    break;
   }
  }

  for(int i=posX,j=posY;i>=0&&j<BOARDSIZE;i--,j++){
  //-x-y direction
   U8 cnt=flag_x_y;
   for(positionPtr=positionVal.begin();positionPtr!=positionVal.end();positionPtr++){
    if((positionPtr->getxPos()==i)&&(positionPtr->getyPos()==j)){
	 flag_x_y++;
	}
	else{
	 continue;
	}
   }
   
   if(cnt==flag_x_y+1){
    continue;
   }
   else{
    break;
   }
  }
  LOG_BUG("start---flagx=%d,flag_x=%d,flagy=%d,flag_y=%d,flagxy=%d,flag_xy=%d,flagx_y=%d,flag_x_y=%d\n",flagx,flag_x,flagy,flag_y,flagxy,flag_xy,flagx_y,flag_x_y);
  d=maxVal(flagx,maxVal(flagy,maxVal(flagxy,maxVal(flag_xy,maxVal(flagx_y,maxVal(flag_x,maxVal(flag_y,flag_x_y)))))));
  LOG_BUG("end-----d=%d\n",d);
/*  switch(d){
    case d==flagx   : break;
	case d==flag_x  : break;
	case d==flagy   : break;
	case d==flag_y  : break;
	case d==flagxy  : break;
	case d==flag_xy : break;
	case d==flagx_y : break;
	case d==flag_x_y: break;
  }*/
  if(d==flagx){
    setDirection(1); 
  }
  else if(d==flag_x){
    setDirection(2); 
  }
  else if(d==flagy){
    setDirection(3); 
  }
  else if(d==flag_y){
    setDirection(4); 
  }
  else if(d==flagxy){
    setDirection(5); 
  }
  else if(d==flag_xy){
    setDirection(6); 
  }
  else if(d==flagx_y){
    setDirection(7); 
  }
  else if(d==flag_x_y){
    setDirection(8); 
  }
return d;
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
        case('#'):{ //changed &--->#
          PositionHandle tmpPosition(i,j);
		  //tmpPosition.set(i,j);
          playerPosition.push_back(std::move(tmpPosition));
          break;}
        case('&'):{ //changed #--->&
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
	//add by xujiwei----2016-8-27
	LOG_BUG("pp=%d\n",pp);
	//add by xujiwei
	U8  maxLength=0;
	U8  tmp=0;
	int positionSite=0;
	if(pp==0){
		 haveTry(-1,-1);
	 	 break;
	}
	for(int i=0;i<pp;i++){
	//analyse player position ----add by xujiwei 2016-8-16
		tmp=testNumbersChessman(playerPosition[i].getxPos(),playerPosition[i].getyPos(),playerPosition);
		LOG_BUG("\n-----\n");
		if(tmp>=maxLength){
		maxLength=tmp;
		positionSite=i;
		}
	}
	int x=playerPosition[positionSite].getxPos();
	int y=playerPosition[positionSite].getyPos();
	LOG_BUG("x=%d,y=%d,direction=%d\n",x,y,this->direction);
	switch(this->direction){
		case XPLUSDirection:      haveTry(x-1,y);  break;
		case XNEGADirection:      haveTry(x+1,y);  break;
		case YPLUSDirection:      haveTry(x,y-1);  break;
		case YNEGADirection:      haveTry(x,y+1);  break;
		case XPLUSYPLUSDirection: haveTry(x-1,y+1);break;
		case XNEGAYPLUSDirection: haveTry(x+1,y+1);break;      
		case XPLUSYNEGADirection: haveTry(x-1,y-1);break;
		case XNEGAYNEGADirection: haveTry(x+1,y-1);break;
		defualt:break;
		}
		break;
	}
    case 3:{break;}
    case 4:{break;}
    default: throw "out of levels";
  }
}

bool HandleChessBoard::haveTry(int x,int y)
{
   if(isBlank(x,y)){
     xChessman=x;
	 yChessman=y;
   }
   else{
	int bp=blankPosition.size();
    int position=bp/2;
	sort(blankPosition.begin(),blankPosition.end(),srtVectorPosX);
	xChessman=blankPosition[position].getxPos();
	yChessman=blankPosition[position].getyPos();
   }
}

bool HandleChessBoard::isBlank(int x,int y)
{
   for(int i=0;i<blankPosition.size();i++){
     if((blankPosition[i].getxPos()==x)&&(blankPosition[i].getyPos()==y)) return true;
	 else continue;
   }
return false;
}
