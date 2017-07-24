#ifndef _HUMAN_H
#define _HUMAN_H

#include "player.h"

class Human:public Player
{
private:
   string human_name;
   s8 human_chess_type;
public:
   Human(string);
   ~Human();
public:
   Human(const Human&) = delete;
   Human& operator=(const Human&) = delete;
   Human& operator()(const Human&) = delete;
public:
   s8 get_human_chess_type();
   bool make_a_step(Chessboard&);
   string get_name();
   State change_state();
   board_position get_present_position();
private:
   void input_position();
};
#endif //human.h
