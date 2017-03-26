#ifndef _TESTWINNER_
#define _TESTWINNER_

#include "ai_core.h"
#include "chessboard.h"
#include "boardposition.h"

class Testwinner
{
private:
   AI_core* ai;
public:
   Testwinner(){
     ai = new AI_core;
   }
   ~Testwinner(){
     delete ai;
   }
public:
   Testwinner(const Testwinner&) = delete;
   Testwinner& operator=(const Testwinner&) = delete;
   Testwinner& operator()(const Testwinner&) = delete;
public:
   bool operator()(const Chessboard&,const board_position&,s8);
};
#endif //testwinner.h
