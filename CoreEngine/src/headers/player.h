#ifndef _PLAYER_H
#define _PLAYER_H

#include"chessboard.h"
#include"types.h"
#include"boardposition.h"
#include"ai_core.h"
#include<string>
#include<ctime>
using std::string;

typedef enum state{
   stop,   //---0
   start   //---1
} State;

class Player
{
protected:
   std::string player_name;
   time_t start_time;
   time_t end_time;
   time_t use_time;
   u32 total_steps;
   State move_state;
   board_position last_position;
   board_position present_position;
protected:
   board_position suggest_position;
public:
   void initMoveState();
public:
   virtual bool make_a_step(Chessboard&);
   virtual void analysis(Chessboard&,AI_core&,u32);
public:
   Player(const string&);
   ~Player();
public:
   Player(const Player&) = delete;
   Player& operator=(const Player&) = delete;
   Player& operator()(const Player&) = delete;   
public:
   virtual string get_player_name();
   virtual board_position get_present_position();
};
#endif //player.h
