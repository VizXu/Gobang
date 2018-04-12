#include "chessboardinfo.h"

s8 chessboard_info::get_chess_info(int i, int j)
{
  return this->info[i][j];
}

void chessboard_info::set_chess_info(int i, int j, s8 c)
{
   this->info[i][j] = c;
}

int PosInfo::getxPos() const
{
	return this->xpos;
}
int PosInfo::getyPos() const
{
	return this->ypos;
}

int PosInfo::getDirection() const
{
	return this->direction;
}

int PosInfo::getFlag() const
{
	return this->flag;
}


