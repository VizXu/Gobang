#include "human.h"
#include<iostream>

Human::Human(string s):Player("null"),human_name(s)
{
  
}

Human::~Human()
{

}

board_position Human::get_present_position()
{
  return this->present_position;
}

bool Human::make_a_step(Chessboard& chessboard)
{
  input_position();
  if(this->move_state == start){
     if(chessboard.set_chess(suggest_position.x_pos,suggest_position.y_pos,'&')){
       last_position = present_position;
       present_position = suggest_position;
       return true;
     }
  }
  else return false;
}

void Human::input_position()
{
    int x = 0;
    int y = 0;
    
    enter_again:
    std::cout<<"Please input the position you chose,for example(3 3):\n";
    char ch_x = std::cin.get();
    while(std::cin.get() != '\n')continue; // make the cin stream empty;
    char ch_y = std::cin.get();
    while(std::cin.get() != '\n')continue; // make the cin stream empty;
    x = int(ch_x - '0');
    y = int(ch_y - '0');
    if( (x < 0 || x > BOARD_SIZE) || (y < 0 || y > BOARD_SIZE)){
       std::cout<<" enter is illegal, please enter agian!"<<std::endl;
       goto enter_again;
    }
    else{
       this->suggest_position.x_pos = x;
       this->suggest_position.y_pos = y;
       present_position = suggest_position;
    }
}

State Human::change_state()
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
