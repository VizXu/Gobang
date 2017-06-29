#ifndef _AI_CORE_H
#define _AI_CORE_H

#include "chessboard.h"
#include "types.h"
#include <ctime>
#include <cstdlib>
#include <list>
#include <vector>

#include"boardposition.h"

typedef struct{
      board_position position;
      u32 direction;
      u32 max_length;
}analysis_result;

class AI_core
{
private:
   analysis_result alys_rlt;
   s8 core_board[BOARD_SIZE][BOARD_SIZE];
   board_position position_suggest;
   std::list<board_position> type1;
   std::list<board_position> type2;
   std::list<board_position> empty_type;
   std::list<board_position>::iterator l_ptr;
   std::vector<std::vector<int>> suggest_position_info;/* 0-horizontal 1-vertical 2-hori_vert 3-anti_hori_vert*/
public:
   AI_core(){
     srand(time(NULL));
     position_suggest.x_pos = BOARD_SIZE/2;
     position_suggest.y_pos = BOARD_SIZE/2;

     this->alys_rlt.direction = 0;
     this->alys_rlt.max_length = 0;
     for(int i = 0; i < BOARD_SIZE; i++){
       for(int j = 0; j < BOARD_SIZE; j++){
         core_board[i][j] = '+';
       }
     }
   }      
   ~AI_core(){}
public:
   AI_core(const AI_core&)= delete;
   AI_core& operator=(const AI_core&) = delete;
   AI_core& operator()(const AI_core&) = delete;
public:
   void copy_board(const Chessboard&);
   board_position get_suggest_position();
   bool is_winner(const board_position&,s8);
// for test mode
public:
   u32 test_mode(int);
// mode end
private:
   bool is_safe(const board_position&);
   bool is_empty_site(const board_position&);
   void store_chess_info();    
   void destroy_present_chess_info();
   analysis_result  analysize_guess_position(const board_position&,s8);
   typedef s8 COPY_BOARD[BOARD_SIZE][BOARD_SIZE];
   void copy_position(COPY_BOARD&);
   void store_analysis_result(const analysis_result&);
   analysis_result get_present_result();
public:
   void analyze_level1(s8);
   void analyze_level2(s8);
   void analyze_level3(s8);
private:
   u32 the_position_score_fun1(COPY_BOARD&,board_position);
   u32 the_position_score_fun2(COPY_BOARD&,board_position);
   u32 the_position_score_fun3(COPY_BOARD&,board_position);
   u32 the_position_score_fun4(COPY_BOARD&,board_position);
   u32 the_position_score_fun5(COPY_BOARD&,board_position);
   u32 the_position_score_fun6(COPY_BOARD&,board_position);
   u32 the_position_score_fun7(COPY_BOARD&,board_position);
   u32 the_position_score_fun8(COPY_BOARD&,board_position);
};
#endif//ai_core.h

