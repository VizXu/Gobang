#ifndef _COMPUTER_H
#define _COMPUTER_H

#include "player.h"
#include "judgesituation.h"

class Computer:public Player
{
private:
   string computer_name;
   u32 level;
   AI_core* ai;
   s8 computer_chess_type;
public:
   Computer(string);
   ~Computer();
public:
   Computer(const Computer&) = delete;
   Computer& operator=(const Computer&) = delete;
   Computer& operator()(const Computer&) = delete;
public:
   s8 get_computer_chess_type();
   bool make_a_step(Chessboard&);
   string get_name();
   void select_level(u32);
   State change_state();
   board_position get_present_position();
private:
   void ai_analysis(const Chessboard&,u32);
};
#endif//computer.h
