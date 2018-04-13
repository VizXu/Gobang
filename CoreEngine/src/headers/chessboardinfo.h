#ifndef CHESSBOARD_INFO_
#define CHESSBOARD_INFO_

#include "chessboard.h"

class PosInfo
{
private:
	int xpos;
	int ypos;
	int direction;
	int flag;
public:
	PosInfo(int x = -1, int y = -1,int dir = -1,int f = 0):xpos(x),ypos(y),direction(dir),flag(f){}
	/*
	PosInfo operator=(const PosInfo& info){
		PosInfo tmp;
		tmp.xpos = info.xpos;
		tmp.ypos = info.ypos;
		tmp.direction = info.direction;
		tmp.flag = info.flag;
		return tmp;
	}
	*/
	~PosInfo(){}
public:
	int getxPos() const;
	int getyPos() const;
	int getDirection() const;
	int getFlag() const;
};

class chessboard_info
{
public:
   s8 info[BOARD_SIZE][BOARD_SIZE];
public:
   s8 get_chess_info(int,int);
   void set_chess_info(int,int,s8);   
};
#endif //chessboardinfo.h
