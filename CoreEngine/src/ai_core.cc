#include<algorithm>
#include "ai_core.h"
#include "debug.h"
#include "find.h"

class find_out;

#define DEBUG_MODE 
//#undef DEBUG_MODE 

void AI_core::copy_board(const Chessboard& board)
{
   for(int i = 0;i < BOARD_SIZE; i++){
     for(int j = 0; j < BOARD_SIZE; j++){
        this->core_board[i][j]= board.get_chess(i,j);
 	 }
  }
}

void AI_core::store_chess_info()
{
//    DEBUG_LOG("store chess info\n");
    for(int i = 0;i < BOARD_SIZE; i++){
      for(int j = 0; j < BOARD_SIZE; j++){
        board_position tmp_pos;
        switch(this->core_board[i][j]){
           case '+': {
		       tmp_pos.x_pos = i;
		       tmp_pos.y_pos = j;
		       //if(0 == i && 0 == j) this->empty_chess_type = '+';
                       this->empty_type.push_back(std::move(tmp_pos)); 
                     } break;
           case '&': {
		       tmp_pos.x_pos = i;
		       tmp_pos.y_pos = j;
		       //if(0 == i && 0 == j) this->human_chess_type = '&';
		       this->type1.push_back(std::move(tmp_pos));
                     } break;
           case '@': {
		       tmp_pos.x_pos = i;
		       tmp_pos.y_pos = j;
		      //if(0 == i && 0 == j) this->computer_chess_type = '@';
 		       this->type2.push_back(std::move(tmp_pos));
		     } break;
           default: throw "error in store_chess_info";
        }
	 //  DEBUG_LOG("this->core_board[%d][%d] = %c\n",i,j,this->core_board[i][j]);
      }
    }
}

analysis_result AI_core::get_present_result()
{
  return this->alys_rlt;
}

s8 AI_core::get_human_chess_type()
{
  return this->human_chess_type;
}

s8 AI_core::get_computer_chess_type()
{
//  DEBUG_LOG("get_computer_chess_type = %c\n",this->computer_chess_type);
  return this->computer_chess_type;
}

s8 AI_core::get_empty_chess_type()
{
  return this->empty_chess_type;
}

void AI_core::destroy_present_chess_info()
{
   std::list<board_position> tmp;
   this->empty_type.swap(tmp);
   this->type1.swap(tmp);
   this->type2.swap(tmp);
}
board_position AI_core::get_suggest_position()
{
  std::list<board_position>::iterator empty_ptr = empty_type.begin();

  for(int i = 0; i< empty_type.size(); i++){
	empty_ptr++;
  }  

  if(is_empty_site(this->position_suggest))
  	return this->position_suggest;
  else return *empty_ptr;
}

analysis_result AI_core::get_suggest_analysis_result()
{
  return this->analysis_result_position;
}

void AI_core::analyze_level1(s8 chesstype)
{
  destroy_present_chess_info();
  store_chess_info();
  u32 size = this->empty_type.size();
  this->l_ptr = empty_type.begin();

//  DEBUG_LOG("empty size = %d\n",size);

  /*
  int tmp = rand()%size;
  while(tmp--) l_ptr++;
   this->position_suggest = *l_ptr;  */


 //start analysis
  
  analysis_result rslt;

  [&](analysis_result& r)->void{
     r.position.x_pos = 0;
     r.position.y_pos = 0;
     r.direction = 0;
     r.max_length = 0;
  }(rslt);

  board_position guess_pos;
 
  for(int i = 0; i < size && l_ptr != empty_type.end(); i++, l_ptr++){
     guess_pos = *l_ptr;     
     analysis_result r = analysize_guess_position(guess_pos,chesstype);     
     if( r.max_length > rslt.max_length) rslt = r;
     else continue;
  }
 
  #if defined(DEBUG_MODE)
//  DEBUG_LOG("xujiwei---suggest_info1 = %d\n",this->suggest_position_info[0][0]);
//  DEBUG_LOG("xujiwei---suggest_info2 = %d\n",this->suggest_position_info[1][0]);
//  DEBUG_LOG("xujiwei---suggest_info3 = %d\n",this->suggest_position_info[2][0]);
//  DEBUG_LOG("xujiwei---suggest_info4 = %d\n",this->suggest_position_info[3][0]);
//  DEBUG_LOG("analysis result = %d and %d,x_pos=%d,y_pos=%d\n",rslt.direction,rslt.max_length,rslt.position.x_pos,rslt.position.y_pos);
  #endif 

    this->store_analysis_result(rslt); // store the suggest position_info 
  
  #if defined(DEBUG_MODE) 
  // this->position_suggest.x_pos = 1 ; this->position_suggest.y_pos = 6;
  //DEBUG_LOG("x_pos = %d,y_pos = %d\n",this->position_suggest.x_pos,this->position_suggest.y_pos);
  #endif // debug_mode
}

void AI_core::analyze_level2(const Chessboard& chessboard, s8 chesstype)
{
   int score = 0;
   s8 human_chess_type = this->get_human_chess_type();
   s8 computer_chess_type = this->get_computer_chess_type();
   this->analyze_level1(human_chess_type);
   analysis_result human_result = this->get_present_result();

   this->analysize_empty_position_score();

   score = this->current_chessboard_score(chessboard, chesstype);

   std::vector<board_position>::iterator s_ptr = this->empty_position_score_results.begin();
   for(; s_ptr != this->empty_position_score_results.end(); s_ptr++){
     if(s_ptr->x_pos == human_result.position.x_pos && s_ptr->y_pos == human_result.position.y_pos){
		DEBUG_LOG("match the position x= %d, y= %d\n",s_ptr->x_pos,s_ptr->y_pos);
     }
     continue;
   }

}

void AI_core::analyze_level3(s8 chesstype)
{

}


void AI_core::copy_chess_for_analysis(COPY_BOARD board)
{
    for(int i = 0;i < BOARD_SIZE; i++){
     for(int j = 0; j < BOARD_SIZE; j++){
	  this->board_for_analysis[i][j] = board[i][j];
    }
   }
}

void AI_core::destory_chessboard_for_analysis()
{
   std::list<board_position> tmp;
   this->empty_type_of_greedy_analysis.swap(tmp);
   this->human_type_of_greedy_analysis.swap(tmp);
   this->computer_type_of_greedy_analysis.swap(tmp);
}

void AI_core::store_chessboard_for_analysis()
{
    for(int i = 0;i < BOARD_SIZE; i++){
      for(int j = 0; j < BOARD_SIZE; j++){
        board_position tmp_pos;
        switch(this->board_for_analysis[i][j]){
           case '+': {
		       tmp_pos.x_pos = i;
		       tmp_pos.y_pos = j;
		       this->empty_type_of_greedy_analysis.push_back(std::move(tmp_pos));
                     } break;
           case '&': {
		       tmp_pos.x_pos = i;
		       tmp_pos.y_pos = j;
		       this->human_type_of_greedy_analysis.push_back(std::move(tmp_pos));
                     } break;
           case '@': {
		       tmp_pos.x_pos = i;
		       tmp_pos.y_pos = j;
		       this->computer_type_of_greedy_analysis.push_back(std::move(tmp_pos));
		     } break;
           default: throw "error in store_chess_info";
        }
      }
    } 
}

void AI_core::flush_chessboard_for_analysis()
{
   this->destory_chessboard_for_analysis();
   this->store_chessboard_for_analysis();
}

int AI_core::chessboard_greedy_analysis(COPY_BOARD board,board_position pos,int flag)
{
    COPY_BOARD tmp_board;// = board;
    [=](COPY_BOARD chessboard)->void{
        for(int i = 0; i< BOARD_SIZE; i++){
	   for(int j = 0; j< BOARD_SIZE; j++){
		chessboard[i][j] = board[i][j];
	   }
        }
    }(tmp_board);
	
    board_position tmp_position = pos;

    if(flag > 10){
	return 0;
    }
    else{
	//analysis the board
	this->copy_chess_for_analysis(tmp_board);
    	this->flush_chessboard_for_analysis(); // chessboard is stored at stl greedy_analysis list<board_position> empty, human, computer
	this->greedy_analysis_empty_position_score(tmp_board);
	
	tmp_position.x_pos =  this->empty_position_score_results[0].x_pos;
	tmp_position.y_pos =  this->empty_position_score_results[0].y_pos;

	tmp_board[tmp_position.x_pos][tmp_position.y_pos] = '&';

	this->chessboard_greedy_analysis(tmp_board,tmp_position,++flag);
    }

}

analysis_result AI_core::greedy_analysis()
{
 // this->store_chess_info();
  COPY_BOARD chess_board_for_analysis;
  this->copy_position(chess_board_for_analysis); // this->core_board  ---> chess_board_for_analysis
	
  board_position suggest_pos;

  this->chessboard_greedy_analysis(chess_board_for_analysis,suggest_pos,0);

/*   s8 human_chess_type = this->get_human_chess_type();
   s8 computer_chess_type = this->get_computer_chess_type();
   this->analyze_level1(human_chess_type);
   analysis_result human_result = this->get_present_result();
   //COPY_BOARD tmp_board;
   this->analyze_level1(computer_chess_type);
   analysis_result computer_result = this->get_present_result();

   DEBUG_LOG("human_result position x= %d, y= %d\n",human_result.position.x_pos,human_result.position.y_pos);
   DEBUG_LOG("computer_result position x= %d, y= %d\n",computer_result.position.x_pos,computer_result.position.y_pos);
*/
}

bool AI_core::is_winner(const board_position& position,s8 chess_type)
{
    analysis_result tmp_result = analysize_guess_position(position,chess_type);
    if(tmp_result.max_length >= 5) return true;
    else return false;   
}

analysis_result AI_core::analysize_guess_position(const board_position& position,s8 chess_type)
{
    COPY_BOARD analysis_board;
    copy_position(analysis_board);
    analysis_board[position.x_pos][position.y_pos] = chess_type;
    u32 x_dir = 0, y_dir = 0, xy_dir = 0, _x_dir = 0, _xy_dir = 0, _y_dir = 0, _x_y_dir = 0, _yx_dir = 0;
    
    //display

    /*count the max size of different directions*/
 
    std::vector<std::vector<int>> tmp;
    this->suggest_position_info.swap(tmp); /* release the suggest_position_info*/
      
    int x, y;
    /* the x+ direction*/
    for(x = position.x_pos, y = position.y_pos + 1; y < BOARD_SIZE; y++ ){
	if(analysis_board[x][y] == chess_type) x_dir++;
	else break;
    }
    /* the x- direction*/
    for(x = position.x_pos, y = position.y_pos -1; y > 0; y--){
	if(analysis_board[x][y] == chess_type) _x_dir++;
	else break;
    }
        
    std::vector<int> horizontal_info;
    horizontal_info.push_back(x_dir + _x_dir + 1); 
    this->suggest_position_info.push_back(std::move(horizontal_info));
    /* horizontal direction analysis end */

    /* the y- direction */
    for(x = position.x_pos + 1, y = position.y_pos; x < BOARD_SIZE; x++){
       if(analysis_board[x][y] == chess_type) y_dir++;
       else break;
    }
    /* the y+ direction*/
    for(x = position.x_pos -1, y = position.y_pos; x > 0; x--){
       if(analysis_board[x][y] == chess_type) _y_dir++;
       else break;
    }
    std::vector<int> vertical_info;
    vertical_info.push_back(y_dir + _y_dir +1);
    this->suggest_position_info.push_back(std::move(vertical_info));
    /* vertical direction analysis end*/

    /* the xy direction*/
    for(x = position.x_pos - 1, y = position.y_pos + 1; x > 0 && y < BOARD_SIZE; x--, y++){
       if(analysis_board[x][y] == chess_type) xy_dir++;
       else break;
    }
    /* the _x_y direction*/
    for(x = position.x_pos + 1, y = position.y_pos - 1; x < BOARD_SIZE && y > 0; x++, y--){
       if(analysis_board[x][y] == chess_type) _x_y_dir++;
       else break;
    }
    std::vector<int> hori_vert_info;
    hori_vert_info.push_back(xy_dir + _x_y_dir + 1);
    this->suggest_position_info.push_back(std::move(hori_vert_info));
    /* hori_vert direction analysis end*/

    /* the _xy direction*/
    for(x = position.x_pos - 1, y = position.y_pos - 1; x > 0 && y > 0; x--, y--){
      if(analysis_board[x][y] == chess_type) _xy_dir++;
      else break;
    }
    /* the x_y direction*/
    for(x = position.x_pos + 1, y = position.y_pos + 1; x <BOARD_SIZE && y < BOARD_SIZE; x++, y++){
      if(analysis_board[x][y] == chess_type) _x_y_dir++;
      else break;
    }
    std::vector<int> anti_hori_vert_info;
    anti_hori_vert_info.push_back(_xy_dir + _x_y_dir + 1);
    this->suggest_position_info.push_back(std::move(anti_hori_vert_info));
    /* anti_hori_vert direction analysis end*/

    analysis_result result;
    result.direction = 0;
    result.max_length = 0;
    int size = this->suggest_position_info.size();
   
    for(int i = 0; i < size; i++){
       if(result.max_length <= this->suggest_position_info[i][0]){
           result.position = position;
           result.direction = i;
           result.max_length = this->suggest_position_info[i][0];
       }
       else continue;
    } 
return result;
}

void AI_core::copy_position(COPY_BOARD& c_board)
{
   for(int i = 0; i< BOARD_SIZE; i++){
     for(int j = 0; j< BOARD_SIZE; j++){
        c_board[i][j] = this->core_board[i][j];
     }
   }
}

void AI_core::store_analysis_result(const analysis_result& r)
{
    this->alys_rlt.position = r.position;
    this->alys_rlt.direction = r.direction;
    this->alys_rlt.max_length = r.max_length;
    this->position_suggest = r.position;
    this->analysis_result_position = r;
}

u32 AI_core::test_mode(int mode,board_position pos,s8 chess_type)
{
  DEBUG_LOG("xujiwei-----test_mode\n");
  u32 score =0;
  s8 type_is = chess_type; 
  human_computer_score hcs;
  
  this->store_chess_info();

  //hcs = this->empty_position_score(pos);

  this->analysize_empty_position_score();

  switch(9){
    case 1: copy_position(score_board); score = this->the_position_score_fun1(score_board,pos,type_is); break;
    case 2: copy_position(score_board); score = this->the_position_score_fun2(score_board,pos,type_is); break;
    case 3: copy_position(score_board); score = this->the_position_score_fun3(score_board,pos,type_is); break;
    case 4: copy_position(score_board); score = this->the_position_score_fun4(score_board,pos,type_is); break;
    case 5: copy_position(score_board); score = this->the_position_score_fun5(score_board,pos,type_is); break;
    case 6: copy_position(score_board); score = this->the_position_score_fun6(score_board,pos,type_is); break;
    case 7: copy_position(score_board); score = this->the_position_score_fun7(score_board,pos,type_is); break;
    case 8: copy_position(score_board); score = this->the_position_score_fun8(score_board,pos,type_is); break;
  }
return score;
}

void AI_core::release_pos_score_info()
{
   std::vector<position_score_info> tmp;
   this->pos_score_info.swap(tmp);
}

void AI_core::store_empty_position_score(const board_position pos,const human_computer_score score)
{
   position_score_info tmp;
   tmp.position = pos;
   tmp.score = score;
   this->pos_score_info.push_back(std::move(tmp));
}

board_position AI_core::get_pos_of_maxhs()
{
   board_position tmp;
   std::vector<position_score_info>::iterator p_ptr;
   u32 score = 0;

   for(p_ptr = this->pos_score_info.begin(),score = p_ptr->score.human_score;p_ptr != this->pos_score_info.end();p_ptr++){
	if(p_ptr->score.human_score >= score){
	    score = p_ptr->score.human_score;
	    tmp = p_ptr->position;
        }
   }
return tmp;
}

board_position AI_core::get_pos_of_minhs()
{
   board_position tmp;
   std::vector<position_score_info>::iterator p_ptr;
   u32 score = 0;

   for(p_ptr = this->pos_score_info.begin(),score = p_ptr->score.human_score;p_ptr != this->pos_score_info.end();p_ptr++){
	if(p_ptr->score.human_score <= score){
	    score = p_ptr->score.human_score;
	    tmp = p_ptr->position;
        }
   }
return tmp;
}

board_position AI_core::get_pos_of_maxcs()
{
   board_position tmp;
   std::vector<position_score_info>::iterator p_ptr;
   u32 score = 0;

   for(p_ptr = this->pos_score_info.begin(),score = p_ptr->score.computer_score;p_ptr != this->pos_score_info.end();p_ptr++){
	if(p_ptr->score.computer_score >= score){
	    score = p_ptr->score.computer_score;
	    tmp = p_ptr->position;
        }
   }
return tmp;
}

board_position AI_core::get_pos_of_mincs()
{
   board_position tmp;
   std::vector<position_score_info>::iterator p_ptr;
   u32 score = 0;

   for(p_ptr = this->pos_score_info.begin(),score = p_ptr->score.computer_score;p_ptr != this->pos_score_info.end();p_ptr++){
	if(p_ptr->score.computer_score <= score){
	    score = p_ptr->score.computer_score;
	    tmp = p_ptr->position;
        }
   }
return tmp;
}

void AI_core::release_empty_position_score_results()
{
   std::vector<board_position> tmp;
   this->empty_position_score_results.swap(tmp);
}
void AI_core::analysize_empty_position_score()
{
  this->destroy_present_chess_info();
  this->store_chess_info();
  this->release_pos_score_info();
  board_position pos[4];
  this->copy_position(score_board);  

  std::list<board_position>::iterator empty_ptr = this->empty_type.begin();
  for(;empty_ptr != this->empty_type.end(); empty_ptr++){
    human_computer_score tmp_score = empty_position_score(*empty_ptr,this->score_board);
    this->store_empty_position_score(*empty_ptr,tmp_score);
  }
   
  pos[0] = this->get_pos_of_maxhs();
  pos[1] = this->get_pos_of_minhs();
  pos[2] = this->get_pos_of_maxcs();
  pos[3] = this->get_pos_of_mincs();

  this->release_empty_position_score_results();
  for(int i=0;i<sizeof(pos)/sizeof(pos[0]);i++){
     this->empty_position_score_results.push_back(pos[i]);
  }

  DEBUG_LOG("maxhs=(%d,%d),minhs=(%d,%d),maxcs=(%d,%d),mincs=(%d,%d)\n",pos[0].x_pos,pos[0].y_pos,pos[1].x_pos,pos[1].y_pos,pos[2].x_pos,pos[2].y_pos,pos[3].x_pos,pos[3].y_pos);

}

/**********************************************************************************
 when calling this function you must ensure flush_chessboard_for_analysis is called
***********************************************************************************/
void AI_core::greedy_analysis_empty_position_score(const COPY_BOARD& board)
{
   this->flush_chessboard_for_analysis();
  board_position pos[4];
  std::list<board_position>::iterator empty_ptr = this->empty_type_of_greedy_analysis.begin();
  for(;empty_ptr != this->empty_type_of_greedy_analysis.end(); empty_ptr++){
    human_computer_score tmp_score = empty_position_score(*empty_ptr,board);
    this->store_empty_position_score(*empty_ptr,tmp_score);
  }
   
  pos[0] = this->get_pos_of_maxhs();
  pos[1] = this->get_pos_of_minhs();
  pos[2] = this->get_pos_of_maxcs();
  pos[3] = this->get_pos_of_mincs();

  this->release_empty_position_score_results();
  for(int i=0;i<sizeof(pos)/sizeof(pos[0]);i++){
     this->empty_position_score_results.push_back(pos[i]);
  }

  DEBUG_LOG("maxhs=(%d,%d),minhs=(%d,%d),maxcs=(%d,%d),mincs=(%d,%d)\n",pos[0].x_pos,pos[0].y_pos,pos[1].x_pos,pos[1].y_pos,pos[2].x_pos,pos[2].y_pos,pos[3].x_pos,pos[3].y_pos);
}

human_computer_score AI_core::empty_position_score(board_position pos,const COPY_BOARD& score_board_greedy)
{
    u32 h_s = 0;
    u32 c_s = 0;
    human_computer_score h_c_s;
    s8 h_type = this->get_human_chess_type();
    s8 c_type = this->get_computer_chess_type();
   // s8 h_type = '&';
   // s8 c_type = '@';

    DEBUG_LOG("h_type = %c, c_type = %c \n",h_type,c_type);

   
    h_s += this->the_position_score_fun1(score_board_greedy,pos,h_type);
    h_s += this->the_position_score_fun2(score_board_greedy,pos,h_type);
    h_s += this->the_position_score_fun3(score_board_greedy,pos,h_type);
    h_s += this->the_position_score_fun4(score_board_greedy,pos,h_type);
    h_s += this->the_position_score_fun5(score_board_greedy,pos,h_type);
    h_s += this->the_position_score_fun6(score_board_greedy,pos,h_type);
    h_s += this->the_position_score_fun7(score_board_greedy,pos,h_type);
    h_s += this->the_position_score_fun8(score_board_greedy,pos,h_type);

    DEBUG_LOG("xujiwei----h_s = %d\n",h_s);

    c_s += this->the_position_score_fun1(score_board_greedy,pos,c_type);
    c_s += this->the_position_score_fun2(score_board_greedy,pos,c_type);
    c_s += this->the_position_score_fun3(score_board_greedy,pos,c_type);
    c_s += this->the_position_score_fun4(score_board_greedy,pos,c_type);
    c_s += this->the_position_score_fun5(score_board_greedy,pos,c_type);
    c_s += this->the_position_score_fun6(score_board_greedy,pos,c_type);
    c_s += this->the_position_score_fun7(score_board_greedy,pos,c_type);
    c_s += this->the_position_score_fun8(score_board_greedy,pos,c_type);

    DEBUG_LOG("xujiwei----c_s = %d\n",c_s);
   
    h_c_s.human_score = h_s;
    h_c_s.computer_score = c_s;

return h_c_s;
}

u32 AI_core::the_position_score_fun1(const COPY_BOARD& chessboard,board_position pos,s8 chess_type)
{
    if( !this->is_safe(pos) || !this->is_empty_site(pos)) throw "pos site error!";
   // COPY_BOARD tmp_board;
   // copy_position(tmp_board);
    
    //debug chessboard;
/*    for(int i =0;i<BOARD_SIZE;i++){
      for(int j=0;j<BOARD_SIZE;j++){
        DEBUG_LOG("%c ",chessboard[i][j]);
      }
      DEBUG_LOG("\n");
    }
*********/
   //end
    int _x = pos.x_pos - 1;
    int _y = pos.y_pos;

    s8 type = chess_type;

    DEBUG_LOG("type = %c \n",chessboard[0][0]);

    u32 score = 0;
    for(; _x >= 0 ; _x--){
       //
       DEBUG_LOG("for ---- _x = %d\n",_x);

       if(chessboard[_x][_y] == type) {
         DEBUG_LOG("_x = %d\n",_x);
         ++score;
         continue;
       }
      break;
    }
return score; 
}

u32 AI_core::the_position_score_fun2(const COPY_BOARD& chessboard,board_position pos,s8 chess_type)
{
 if( !this->is_safe(pos) || !this->is_empty_site(pos)) throw "pos site error!";
   // COPY_BOARD tmp_board;
   // copy_position(tmp_board);
    
    int _x = pos.x_pos + 1;
    int _y = pos.y_pos;

    s8 type = chess_type;

    DEBUG_LOG("type = %c \n",chessboard[0][0]);

    u32 score = 0;
    for(; _x < BOARD_SIZE ; _x++){
       //
       DEBUG_LOG("for ---- _x = %d\n",_x);

       if(chessboard[_x][_y] == type) {
         DEBUG_LOG("_x = %d, type[_x,_y] = %c\n",_x, chessboard[_x][_y]);
         ++score;
         continue;
       }
      break;
    }
return score; 
}

u32 AI_core::the_position_score_fun3(const COPY_BOARD& chessboard,board_position pos,s8 chess_type)
{
 if( !this->is_safe(pos) || !this->is_empty_site(pos)) throw "pos site error!";
  //  COPY_BOARD tmp_board;
  // copy_position(tmp_board);
    
    int _x = pos.x_pos;
    int _y = pos.y_pos - 1;

    s8 type = chess_type;

    DEBUG_LOG("type = %c \n",chessboard[0][0]);

    u32 score = 0;
    for(; _y >= 0 ; _y--){
       //
       DEBUG_LOG("for ---- _x = %d\n",_x);

       if(chessboard[_x][_y] == type) {
         DEBUG_LOG("_x = %d\n",_x);
         ++score;
         continue;
       }
      break;
    }
return score; 
}

u32 AI_core::the_position_score_fun4(const COPY_BOARD& chessboard,board_position pos,s8 chess_type)
{
 if( !this->is_safe(pos) || !this->is_empty_site(pos)) throw "pos site error!";
   // COPY_BOARD tmp_board;
   // copy_position(tmp_board);
    
    int _x = pos.x_pos;
    int _y = pos.y_pos + 1;

    s8 type = chess_type;

    DEBUG_LOG("type = %c \n",chessboard[0][0]);

    u32 score = 0;
    for(; _y < BOARD_SIZE ; _y++){
       //
       DEBUG_LOG("for ---- _x = %d\n",_x);

       if(chessboard[_x][_y] == type) {
         DEBUG_LOG("_x = %d\n",_x);
         ++score;
         continue;
       }
      break;
    }
return score; 
}

u32 AI_core::the_position_score_fun5(const COPY_BOARD& chessboard,board_position pos,s8 chess_type)
{
 if( !this->is_safe(pos) || !this->is_empty_site(pos)) throw "pos site error!";
   // COPY_BOARD tmp_board;
   // copy_position(tmp_board);
    
    int _x = pos.x_pos - 1;
    int _y = pos.y_pos - 1;

    s8 type = chess_type;

    DEBUG_LOG("type = %c \n",chessboard[0][0]);

    u32 score = 0;
    for(; _x >= 0, _y>=0 ; _x--, _y--){
       //
       DEBUG_LOG("for ---- _x = %d\n",_x);

       if(chessboard[_x][_y] == type) {
         DEBUG_LOG("_x = %d\n",_x);
         ++score;
         continue;
       }
      break;
    }
return score; 
}

u32 AI_core::the_position_score_fun6(const COPY_BOARD& chessboard,board_position pos,s8 chess_type)
{
 if( !this->is_safe(pos) || !this->is_empty_site(pos)) throw "pos site error!";
   // COPY_BOARD tmp_board;
   // copy_position(tmp_board);
    
    int _x = pos.x_pos - 1;
    int _y = pos.y_pos + 1;

    s8 type = chess_type;

    DEBUG_LOG("type = %c \n",chessboard[0][0]);

    u32 score = 0;
    for(; _x >= 0, _y<BOARD_SIZE ; _x--, _y++){
       //
       DEBUG_LOG("for ---- _x = %d\n",_x);

       if(chessboard[_x][_y] == type) {
         DEBUG_LOG("_x = %d\n",_x);
         ++score;
         continue;
       }
      break;
    }
return score; 
}

u32 AI_core::the_position_score_fun7(const COPY_BOARD& chessboard,board_position pos,s8 chess_type)
{
 if( !this->is_safe(pos) || !this->is_empty_site(pos)) throw "pos site error!";
   // COPY_BOARD tmp_board;
   // copy_position(tmp_board);
    
    int _x = pos.x_pos + 1;
    int _y = pos.y_pos - 1;

    s8 type = chess_type;

    DEBUG_LOG("type = %c \n",chessboard[0][0]);

    u32 score = 0;
    for(; _x < BOARD_SIZE, _y > 0 ; _x++,_y--){
       //
       DEBUG_LOG("for ---- _x = %d\n",_x);

       if(chessboard[_x][_y] == type) {
         DEBUG_LOG("_x = %d\n",_x);
         ++score;
         continue;
       }
      break;
    }
return score; 
}

u32 AI_core::the_position_score_fun8(const COPY_BOARD& chessboard,board_position pos,s8 chess_type)
{
 if( !this->is_safe(pos) || !this->is_empty_site(pos)) throw "pos site error!";
   // COPY_BOARD tmp_board;
   // copy_position(tmp_board);
    
    int _x = pos.x_pos + 1;
    int _y = pos.y_pos + 1;

    s8 type = chess_type;

  //  DEBUG_LOG("type = %c \n",chessboard[0][0]);

    u32 score = 0;
    for(; _x < BOARD_SIZE, _y<BOARD_SIZE ; _x++, _y++){
       //
       DEBUG_LOG("for ---- _x = %d\n",_x);

       if(chessboard[_x][_y] == type) {
         DEBUG_LOG("_x = %d\n",_x);
         ++score;
         continue;
       }
      break;
    }
return score; 
}

bool AI_core::is_safe(const board_position& pos)
{
   //DEBUG_LOG("xujiwei----is_safe_site,pos.x_pos = %d, pos.y_pos = %d \n",pos.x_pos,pos.y_pos);
    if(pos.x_pos < 0 || pos.x_pos >= BOARD_SIZE || pos.y_pos < 0 || pos.y_pos >= BOARD_SIZE) return false;
return true;
}

bool AI_core::is_empty_site(const board_position& pos)
{
   //DEBUG_LOG("xujiwei----is_empty_site,pos.x_pos = %d, pos.y_pos = %d \n",pos.x_pos,pos.y_pos);

   this->l_ptr = std::find_if(empty_type.begin(),empty_type.end(),find_out(pos.x_pos,pos.y_pos));
   if(l_ptr != empty_type.end()){
   //  DEBUG_LOG("xujiwei true!\n");
     return true; 
   }
   else { 
     return false; 
   }
}

s32 AI_core::current_chessboard_score(const Chessboard& chessboard,char chesstype)
{
   s32 score = 0;
   Chessmen_info* info = new Chessmen_info;
   this->judgewin_ai->copy_chessboard(chessboard);
   info = this->judgewin_ai->scan_analysis_chessmen(chesstype);
return score;
}
