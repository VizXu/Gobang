#ifndef _JUDGESITUATION_
#define _JUDGESITUATION_
#include "chessboard.h"

class JudgeWin
{
private:
   bool be_won;
   char winner;// should be '&' or '@'
   s8 board_for_judge[BOARD_SIZE][BOARD_SIZE];
public:
   JudgeWin();
   ~JudgeWin();
public:
   void copy_chessboard(const Chessboard&);
   char whois_winner() const;
private:
   bool won_the_game() const;
};

class JudgeSituation
{
private:
   JudgeWin isWin;
public:
};

#endif//judgesituation.h
