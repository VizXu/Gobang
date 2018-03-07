#ifndef _JUDGESITUATION_
#define _JUDGESITUATION_
#include "chessboard.h"

class Info
{
private:
   int x_pos;
   int y_pos;
   int direction;
public:
   Info(int _x = 0, int _y = 0, int _d = 0):x_pos(_x),y_pos(_y),direction(_d){}
   ~Info(){}
public:
   int get_xpos() const;
   int get_ypos() const;
   int get_direction() const;
   void set_xpos(int);
   void set_ypos(int);
   void set_direction(int);
   const Info& operator()(int, int, int);
   void set(int,int,int);
   bool operator==(const Info&);
};
class Chessmen_info
{
private:
public:
   int chessmen_of_each_direction[BOARD_SIZE][BOARD_SIZE][8];
   Info*   ihas_won[BOARD_SIZE*BOARD_SIZE];
   Info*   ilive4[BOARD_SIZE*BOARD_SIZE];
   Info*   ilive4heap[BOARD_SIZE*BOARD_SIZE];
   Info*   ilive3[BOARD_SIZE*BOARD_SIZE];
   Info*   isleep3[BOARD_SIZE*BOARD_SIZE];
   Info*   ilive2[BOARD_SIZE*BOARD_SIZE];
   Info*   isleep2[BOARD_SIZE*BOARD_SIZE];
public:
   Chessmen_info();
   ~Chessmen_info();
};

class JudgeWin
{
private:
   bool be_won;
   char winner;// should be '&' or '@'
   s8 board_for_judge[BOARD_SIZE][BOARD_SIZE];
   int judge_panel[BOARD_SIZE][BOARD_SIZE][8];
public:
   JudgeWin();
   ~JudgeWin();
public:
   void copy_chessboard(const Chessboard&);
   char whois_winner() const;
private:
   bool won_the_game(char) const;
   Chessmen_info* scan_analysis_chessmen(char) const;
};

class JudgeSituation
{
private:
   JudgeWin isWin;
public:
};

#endif//judgesituation.h
