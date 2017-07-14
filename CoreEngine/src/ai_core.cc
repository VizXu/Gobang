#include "ai_core.h"
#include "debug.h"

#include<algorithm>

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
    for(int i = 0;i < BOARD_SIZE; i++){
      for(int j = 0; j < BOARD_SIZE; j++){
        board_position tmp_pos;
        switch(this->core_board[i][j]){
           case '+': {
		       tmp_pos.x_pos = i;
		       tmp_pos.y_pos = j;
                       this->empty_type.push_back(tmp_pos); 
                     } break;
           case '&': {
		       tmp_pos.x_pos = i;
		       tmp_pos.y_pos = j;
		       this->type1.push_back(tmp_pos);
                     } break;
           case '@': {
		       tmp_pos.x_pos = i;
		       tmp_pos.y_pos = j;
 		       this->type2.push_back(tmp_pos);
		     } break;
           default: throw "error in store_chess_info";
        }
      }
    }  
}

analysis_result AI_core::get_present_result()
{
  return this->alys_rlt;
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
  return this->position_suggest;
}

void AI_core::analyze_level1(s8 chesstype)
{
  destroy_present_chess_info();
  store_chess_info();
  u32 size = this->empty_type.size();
  this->l_ptr = empty_type.begin();

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

void AI_core::analyze_level2(s8 chesstype)
{
   this->analyze_level1(chesstype);
   analysis_result present_result = this->get_present_result();
   COPY_BOARD tmp_board;
}

void AI_core::analyze_level3(s8 chesstype)
{

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
}

u32 AI_core::test_mode(int mode,board_position pos)
{
  DEBUG_LOG("xujiwei-----test_mode\n");
  u32 score =0;
  s8 type_is = '+'; 
  switch(mode){
    case 1: copy_position(score_board); score = this->the_position_score_fun1(score_board,pos,type_is); break;
  }
return score;
}

u32 AI_core::the_position_score_fun1(COPY_BOARD& chessboard,board_position pos,s8 chess_type)
{
    if( !this->is_safe(pos) && !this->is_empty_site(pos)) throw "pos site error!";
    COPY_BOARD tmp_board;
    copy_position(tmp_board);
    
    //debug chessboard;
/*    for(int i =0;i<BOARD_SIZE;i++){
      for(int j=0;j<BOARD_SIZE;j++){
        DEBUG_LOG("%c ",chessboard[i][j]);
      }
      DEBUG_LOG("\n");
    }
*********/
   //end
    int _x = pos.x_pos;
    int _y = pos.y_pos;

    s8 type = chess_type;

    DEBUG_LOG("type = %c \n",tmp_board[0][0]);

    u32 score = 0;
    for(; _x >= 0 ; _x--){
       //
       DEBUG_LOG("for ---- _x = %d\n",_x);

       if(tmp_board[_x][_y] == type) {
         DEBUG_LOG("_x = %d\n",_x);
         ++score;
         continue;
       }
      break;
    }
return score; 
}

u32 AI_core::the_position_score_fun2(COPY_BOARD& chessboard,board_position pos,s8 chess_type)
{
 if( !this->is_safe(pos) && !this->is_empty_site(pos)) throw "pos site error!";
    COPY_BOARD tmp_board;
    copy_position(tmp_board);
    
    int _x = pos.x_pos;
    int _y = pos.y_pos;

    s8 type = chess_type;

    DEBUG_LOG("type = %c \n",tmp_board[0][0]);

    u32 score = 0;
    for(; _x >= 0 ; _x--){
       //
       DEBUG_LOG("for ---- _x = %d\n",_x);

       if(tmp_board[_x][_y] == type) {
         DEBUG_LOG("_x = %d\n",_x);
         ++score;
         continue;
       }
      break;
    }
return score; 
}

u32 AI_core::the_position_score_fun3(COPY_BOARD& chessboard,board_position pos,s8 chess_type)
{
 if( !this->is_safe(pos) && !this->is_empty_site(pos)) throw "pos site error!";
    COPY_BOARD tmp_board;
    copy_position(tmp_board);
    
    int _x = pos.x_pos;
    int _y = pos.y_pos;

    s8 type = chess_type;

    DEBUG_LOG("type = %c \n",tmp_board[0][0]);

    u32 score = 0;
    for(; _x >= 0 ; _x--){
       //
       DEBUG_LOG("for ---- _x = %d\n",_x);

       if(tmp_board[_x][_y] == type) {
         DEBUG_LOG("_x = %d\n",_x);
         ++score;
         continue;
       }
      break;
    }
return score; 
}

u32 AI_core::the_position_score_fun4(COPY_BOARD& chessboard,board_position pos,s8 chess_type)
{
 if( !this->is_safe(pos) && !this->is_empty_site(pos)) throw "pos site error!";
    COPY_BOARD tmp_board;
    copy_position(tmp_board);
    
    int _x = pos.x_pos;
    int _y = pos.y_pos;

    s8 type = chess_type;

    DEBUG_LOG("type = %c \n",tmp_board[0][0]);

    u32 score = 0;
    for(; _x >= 0 ; _x--){
       //
       DEBUG_LOG("for ---- _x = %d\n",_x);

       if(tmp_board[_x][_y] == type) {
         DEBUG_LOG("_x = %d\n",_x);
         ++score;
         continue;
       }
      break;
    }
return score; 
}

u32 AI_core::the_position_score_fun5(COPY_BOARD& chessboard,board_position pos,s8 chess_type)
{

}

u32 AI_core::the_position_score_fun6(COPY_BOARD& chessboard,board_position pos,s8 chess_type)
{

}

u32 AI_core::the_position_score_fun7(COPY_BOARD& chessboard,board_position pos,s8 chess_type)
{

}

u32 AI_core::the_position_score_fun8(COPY_BOARD& chessboard,board_position pos,s8 chess_type)
{

}

bool AI_core::is_safe(const board_position& pos)
{
   DEBUG_LOG("xujiwei----is_safe_site,pos.x_pos = %d, pos.y_pos = %d \n",pos.x_pos,pos.y_pos);
    if(pos.x_pos < 0 || pos.x_pos >= BOARD_SIZE || pos.y_pos < 0 || pos.y_pos >= BOARD_SIZE) return false;
return true;
}

class find_out
{
public:
 find_out(int x = 0, int y = 0):x_p(x),y_p(y){}
 bool operator()(board_position& pos){
    return pos.x_pos == x_p && pos.y_pos == y_p;
 }
private:
 int x_p;
 int y_p;
};

bool AI_core::is_empty_site(const board_position& pos)
{
   DEBUG_LOG("xujiwei----is_empty_site,pos.x_pos = %d, pos.y_pos = %d \n",pos.x_pos,pos.y_pos);

   this->l_ptr = std::find_if(empty_type.begin(),empty_type.end(),find_out(pos.x_pos,pos.y_pos));
   if(l_ptr != empty_type.end()){
     DEBUG_LOG("xujiwei true!\n");
     return true; 
   }
   else { 
     return false; 
   }
}
