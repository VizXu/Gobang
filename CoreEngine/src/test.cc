#include<iostream>
#include "chessboard.h"
#include "debug.h"
#include "ai_core.h"
#include "computer.h"
#include "human.h"
#include "testwinner.h"
#include "storechessmanual.h"

#define MODE_2
#if defined(MODE_2)
#include <ctime>
#include <cstdlib>
#endif 

using namespace std;

#define MODE_1
#ifdef DEBUG
void display_chessboard(const Chessboard& board)
{
  for(int i = 0;i<BOARD_SIZE; i++){
    for(int j = 0;j<BOARD_SIZE; j++){
      if(i == 0 && j == 0) std::cout<<"   0   1   2   3   4   5   6   7"<<std::endl;
      if(j == 0) std::cout<<i<<'|';
      if(j == 0) std::cout<<' ';
      std::cout<<board.get_chess(i,j)<<"   ";
    }
    std::endl(std::cout);
    std::endl(std::cout);
  }
}
#endif //display_chessboard

//xujiwei 

s8 rand_type()
{
  switch(rand()%3){
    case 0: return '+';
    case 1: return '&';
    case 2: return '@';
  }
return '+';
}
void rand_chessboard(Chessboard& board)
{
   srand(time(NULL));
   for(u32 i = 0; i< BOARD_SIZE; i++){
     for(u32 j = 0; j < BOARD_SIZE; j++){
	board.set_chess(i,j,rand_type());
     }
   }
return;
}
//end

void test_mode1()
{
   Chessboard chessboard;
   AI_core ai_core;

   display_chessboard(chessboard);

   ai_core.copy_board(chessboard);
   ai_core.analyze_level1('@');

   chessboard.set_chess(3,3,'@');
   ai_core.copy_board(chessboard);
   ai_core.analyze_level1('@');
   display_chessboard(chessboard);
   chessboard.set_chess(3,4,'@');
   ai_core.copy_board(chessboard);
   ai_core.analyze_level1('@');
   display_chessboard(chessboard);

   chessboard.set_chess(3,5,'@');
   ai_core.copy_board(chessboard);
   ai_core.analyze_level1('@');
   display_chessboard(chessboard);
}

void test_mode2()
{
  Chessboard chessboard;
  AI_core ai_core;
  display_chessboard(chessboard); 
  
  srand(time(NULL));
  for(int i = 0; i < 20; i++){
     int x = rand()%BOARD_SIZE;
     int y = rand()%BOARD_SIZE;
     if(chessboard.set_chess(x,y,'@'));
  }
  DEBUG_LOG("\n----------------------------\n"); 
  display_chessboard(chessboard); 
  DEBUG_LOG("-----start analysize--------\n"); 
  ai_core.copy_board(chessboard);
  ai_core.analyze_level1('@');
  DEBUG_LOG("\n----------------------------\n"); 
  display_chessboard(chessboard); 
}

void test_mode3()
{
  Chessboard chessboard;
  Computer computer("computer1");
  Human  human("xujiwei");
  
  srand(time(NULL));
  for(int i = 0; i < 20; i++){
     int x = rand()%BOARD_SIZE;
     int y = rand()%BOARD_SIZE;
     if(chessboard.set_chess(x,y,'@'));
  }

  DEBUG_LOG("\n----------------------------\n"); 
  display_chessboard(chessboard); 
  DEBUG_LOG("-----start analysize--------\n"); 
  computer.change_state();//start
  computer.make_a_step(chessboard);
  computer.change_state(); //stop
  DEBUG_LOG("\n----------------------------\n"); 
  display_chessboard(chessboard); 

  human.change_state();//start   
  while(!human.make_a_step(chessboard)){
    std::cout<<"not legal position,please enter again!"<<std::endl;
  }
  human.change_state(); //stop
  DEBUG_LOG("\n----------------------------\n"); 
  display_chessboard(chessboard);
 
  computer.change_state();//start
  computer.make_a_step(chessboard);
  computer.change_state(); //stop
  DEBUG_LOG("\n----------------------------\n"); 
  display_chessboard(chessboard); 

}


void test_mode4()
{
  StoreChessManual* s = StoreChessManual::get_chess_manual();
  
  Chessboard chessboard;
  Computer computer("computer");
  Human human("xujiwei");
  Testwinner test_winner;

  system("clear");
  display_chessboard(chessboard);

  board_position tmp_position;
  while(true){
     
  human.change_state();//start   
  while(!human.make_a_step(chessboard)){
    std::cout<<"not legal position,please enter again!"<<std::endl;
  }
  tmp_position = human.get_present_position();
  if(test_winner(chessboard,tmp_position,'&')){
     system("clear");
     std::cout<<"human win!"<<std::endl;
     display_chessboard(chessboard);
    return;
  } 
  human.change_state(); //stop

  DEBUG_LOG("\n----------------------------\n"); 
  computer.change_state();//start
  computer.make_a_step(chessboard);
  
  tmp_position = computer.get_present_position();
//  DEBUG_LOG("computer---x= %d, y = %d\n",tmp_position.x_pos,tmp_position.y_pos);
  if(test_winner(chessboard,tmp_position,'@')){
     system("clear");
     std::cout<<"computer win!"<<std::endl;
     display_chessboard(chessboard);
    return;
  }   
  computer.change_state(); //stop
  display_chessboard(chessboard); 
  }
}

void test_mode5() //test the ai_core.cc
{

  AI_core* ai_core = new AI_core;

  Chessboard chessboard;
  rand_chessboard(chessboard);
  
  ai_core->copy_board(chessboard);
  ai_core->analyze_level1('+');

  board_position tmp_position;
  tmp_position.x_pos = 4;
  tmp_position.y_pos = 5;
  try{
    std::cout<<ai_core->test_mode(1,tmp_position,'+')<<std::endl;
  }
  catch(const char* s){
    std::cout<<s<<std::endl;
  }
  display_chessboard(chessboard);
return;
}

int main()
{
   //Chessboard chessboard;
   //AI_core ai_core;
  //test_mode1();
  #if defined(MODE_2)
   test_mode5();
  #endif//mode2
return 0;
}
