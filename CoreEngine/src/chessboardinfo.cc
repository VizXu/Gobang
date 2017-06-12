#include "chessboardinfo.h"

s8 chessboard_info::get_chess_info(int i, int j)
{
  return this->info[i][j];
}

void chessboard_info::set_chess_info(int i, int j, s8 c)
{
   this->info[i][j] = c;
}
