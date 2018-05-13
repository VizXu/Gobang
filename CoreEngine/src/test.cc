#include<iostream>
#include<unistd.h>
#include<cstdio>
#include<cctype>
#include "chessboard.h"
#include "debug.h"
#include "ai_core.h"
#include "computer.h"
#include "human.h"
#include "testwinner.h"
#include "storechessmanual.h"
#include "judgesituation.h"

#define MODE_2
#if defined(MODE_2)
#include <ctime>
#include <cstdlib>
#endif 

using namespace std;

#define MODE_1
#ifdef DEBUG
extern void display_chessboard(const Chessboard&);
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

void specific_chessboard(Chessboard& board)
{
	int size = 5;
	int y = 2;
	int x = 0;
	int i = 0;
//	for(i = 2; i < 2 + size; i++){
//		board.set_chess(7 - i, 7 - i,'&');
//	}

	#if 1
	//board.set_chess(y,i,'@');
	//board.set_chess(y,i - 1, '@');
	//board.set_chess(y,i,'&');
	board.set_chess(y,i + 1,'@');
	board.set_chess(y + 1,i + 2,'&');
	board.set_chess(y + 2,i + 3,'&');
	board.set_chess(y + 3,i + 4,'&');
	//board.set_chess(y,i + 5,'@');
	#else
	//board.set_chess(i,y,'@');
	//board.set_chess(i - 1,y, '@');
	//board.set_chess(i,y,'&');
	//board.set_chess(i + 1,y,'&');
	//board.set_chess(i + 2,y,'@');
	//board.set_chess(i + 3,y,'&');
	//board.set_chess(i + 4,y,'@');
	//board.set_chess(i + 5,y,'&');

	//board.set_chess(i + 4,y - 1,'&');
	//board.set_chess(i + 4,y + 1,'&');
	//board.set_chess(i + 4,y + 2,'&');

	#endif
//	for(int i = 2; i < 2 + size; i++){
//		board.set_chess(y + 3,i,'&');
//	}
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
  
  JudgeWin* judge = new JudgeWin;

  Chessmen_info* info;

  Chessboard chessboard;

  Computer computer("computer");
  Human human("xujiwei");
  Testwinner test_winner;
  Balance_Territory test_balance;

  system("clear");
  display_chessboard(chessboard);

  board_position tmp_position;
  while(true){
     
  human.change_state();//start   
  while(!human.make_a_step(chessboard)){
    std::cout<<"not legal position,please enter again!"<<std::endl;
  }
    tmp_position = human.get_present_position(); 
    if(test_balance(chessboard)){
       system("clear");
       std::cout<<"chess balance..."<<std::endl;
       display_chessboard(chessboard);
       return;
    }
    if(test_winner(chessboard,tmp_position,'&')){
        system("clear");
        std::cout<<"human win!"<<std::endl;
        display_chessboard(chessboard);
     return; 
    }
  human.change_state(); //stop

  judge->copy_chessboard(chessboard);

  info = judge->scan_analysis_chessmen('&');

  info->dumpiLivesInfo();

  DEBUG_LOG("\n----------------------------\n"); 
  computer.change_state();//start
  computer.make_a_step(chessboard);
  
  tmp_position = computer.get_present_position();
  //DEBUG_LOG("computer---x= %d, y = %d\n",tmp_position.x_pos,tmp_position.y_pos);
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
  ai_core->analyze_level1('@');

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

void test_mode6()
{
  AI_core* ai_core = new AI_core;

  Chessboard chessboard;
  rand_chessboard(chessboard);

  try{
  		ai_core->copy_board(chessboard);
  		ai_core->analyze_level2(chessboard, '@');
  }
  catch(std::exception e){
	std::cout<<"something wrong..."<<e.what()<<std::endl;
  }
  display_chessboard(chessboard);
return;
}

void test_mode7()
{
	Chessboard chessboard;

	JudgeWin* judge = new JudgeWin;

	Chessmen_info* info;
	
	//rand_chessboard(chessboard);
	specific_chessboard(chessboard);

	judge->copy_chessboard(chessboard);

	info = judge->scan_analysis_chessmen('&');

	info->dumpiLivesInfo();

//	judge->dumpIndex(ROTATE270);
	
	display_chessboard(chessboard);

	delete info;
	delete judge;
return;
}

void test_mode_for_Qt()
{
  Chessboard chessboard;
  Computer computer("computer");
  Human human("xujiwei");
  Testwinner test_winner;
  Balance_Territory test_balance;

  system("clear");
return;
}

int test(int argc, char* args[])
{

   char result;
   void (*fun)() = test_mode6;
   int mode = 1;

   for(;;){
		result = getopt(argc,args,"m:h");
		if(-1 == result){
			 break;
		}
		
		switch(result){
		   case 'm': 
				if(!isdigit(atoi(optarg))){
				   mode = atoi(optarg);
				   printf("mode = %d\n",mode);
				   switch(mode){
						case 1: fun = test_mode1; break;
						case 2: fun = test_mode2; break;
						case 3: fun = test_mode3; break;
						case 4: fun = test_mode4; break;
						case 5: fun = test_mode5; break;
						case 6: fun = test_mode6; break;
						case 7: fun = test_mode_for_Qt; break;
						default: fun = test_mode6; break;
				   }
				}break; 
		   case 'h': printf("usage:gobang -m [number]\n"); break;
		   default:  printf("error...\n");break;
		}
   }

  	fun();

return 0;
}
