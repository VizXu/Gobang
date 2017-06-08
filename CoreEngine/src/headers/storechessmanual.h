#ifndef _STORE_CHESS_MENUAL_
#define _STORE_CHESS_MENUAL_

#include "debug.h"
#include <fstream>
#include "chessboard.h"

class StoreChessManual
{
private:
   StoreChessManual();
public:
   ~StoreChessManual(); 
private:
   static StoreChessManual* s;
public:
   StoreChessManual* get_chess_manual();
};

#endif // storechessmanual.h
