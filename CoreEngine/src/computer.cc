#include"computer.h"
extern void display_chessboard(const Chessboard&);

Computer::Computer(string s):Player("computer"),computer_name(s),computer_chess_type('@')
{
   level = 1;
   this->ai = new AI_core();
}

Computer::~Computer()
{
   delete ai;
}

State Computer::change_state()
{
   if(this->move_state == stop){
      this->move_state = start;
      return start;
   }
   else{
      this->move_state = stop;
      return stop;
   }
}

board_position Computer::get_present_position()
{
   return this->present_position;
}


s8 Computer::get_computer_chess_type()
{
  return this->computer_chess_type;
}

bool Computer::make_a_step(Chessboard& chessboard)
{
   s8 the_type = get_computer_chess_type();
//   DEBUG_LOG("make_a_step,type = %c\n",the_type);
   if(this->move_state  == start){
      u32 lvr = this->level;

//      DEBUG_LOG("level = %d\n",lvr);
//      DEBUG_LOG("\n-------------------------\n");
//      display_chessboard(chessboard); 
//      DEBUG_LOG("\n-------------------------\n");

      ai_analysis(chessboard,lvr);
      if(chessboard.set_chess(suggest_position.x_pos,suggest_position.y_pos,the_type)){
         this->last_position = this->present_position;
	 this->present_position = this->suggest_position;
      }
    }
    else{
       return false;
    }
}

void Computer::ai_analysis(const Chessboard& chessboard,u32 level)
{
   ai->copy_board(chessboard);
   
   switch(level)
   {
     case 1:ai->analyze_level1('&');break;
     case 2:ai->analyze_level2('@');break;
     case 3:ai->analyze_level1('@');break;
     default:break;
   }
   this->suggest_position = ai->get_suggest_position();
   this->present_position = this->suggest_position;
}

string Computer::get_name()
{
  return get_player_name();
}

void Computer::select_level(u32 l)
{
  this->level = l;
}
