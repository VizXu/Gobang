#include"test.h"
#include"types.h"
int testWinner(int x,int y,char ch,ChessBoard& chessboard)
{
  char elem=ch;
  int xPos=x;
  int yPos=y;
  //horizontal verification
  U8 chessCountHrzt=0;
  while(chessboard.getChessman(xPos,y)==elem&&xPos<BOARDSIZE){
     ++chessCountHrzt;
	 if(5==chessCountHrzt) return 1;
	 xPos++;
  }
  xPos=x-1;
  while(xPos>=0&&chessboard.getChessman(x,y)==elem){
     ++chessCountHrzt;
	 if(5==chessCountHrzt) return 1;
	 xPos--;
  }
  
  //vertical verification
  U8 chessCountVtcl=0;
  while(chessboard.getChessman(x,yPos)==elem&&yPos<BOARDSIZE){
    ++chessCountVtcl;
	if(5==chessCountVtcl) return 1;
	yPos++;
  }
  yPos=y-1;
  while(yPos>=0&&chessboard.getChessman(x,yPos)==elem){
    ++chessCountVtcl;
	if(5==chessCountVtcl) return 1;
	yPos--;
  }

  //south and east || north and west verification
  U8 chessNews1=0;
  xPos=x;
  yPos=y;
  while(chessboard.getChessman(xPos,yPos)==elem&&(xPos<BOARDSIZE&&yPos<BOARDSIZE)){
     ++chessNews1;
	 if(5==chessNews1) return 1;
	 xPos++;
	 yPos++;
  }
  xPos=x-1;
  yPos=y-1;
  while((xPos>=0&&yPos>=0)&&chessboard.getChessman(xPos,yPos)==elem){
    ++chessNews1;
	if(5==chessNews1) return 1;
	xPos--;
	yPos--;
  }

  //north and east || south and west verification
  U8 chessNews2=0;
  xPos=x;
  yPos=y;
  while(chessboard.getChessman(xPos,yPos)==elem&&(xPos>=0&&yPos<BOARDSIZE)){
     ++chessNews2;
	 if(5==chessNews2) return 1;
	 xPos--;
	 yPos++;
  }
  xPos=x+1;
  yPos=y-1;
  while((xPos<BOARDSIZE&&yPos>=0)&&chessboard.getChessman(xPos,yPos)==elem){
     ++chessNews2;
	 if(5==chessNews2) return 1;
	 xPos++;
	 yPos--;
  }
return 0;
}
