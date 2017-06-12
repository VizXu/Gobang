#ifndef CHESSBOARD_INFO_
#define CHESSBOARD_INFO_

#include "chessboard.h"

class chessboard_info
{
public:
   s8 info[BOARD_SIZE][BOARD_SIZE];
public:
   s8 get_chess_info(int,int);
   void set_chess_info(int,int,s8);   
};
#endif //chessboardinfo.h
