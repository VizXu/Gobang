#include "judgesituation.h"
#include <cstdlib>
#include <unistd.h>
#include <memory.h>

void Info::set_flag(int f)
{
   this->flag = f;
};

int Info::get_flag() const
{
   return this->flag;
};

int Info::get_xpos() const
{
   return this->x_pos;
};

int Info::get_ypos() const
{
   return this->y_pos;
};

int Info::get_direction() const
{
   return this->direction;
};

void Info::set_xpos(int xpos)
{
   this->x_pos = xpos;
};

void Info::set_index(int index)
{
   this->index = index;
};

void Info::set_ypos(int ypos) 
{
   this->y_pos = ypos;
};

void Info::set_direction(int direction)
{
   this->direction = direction;
};

const Info& Info::operator()(int _x = 0, int _y = 0, int _d = 0)
{
   return std::move(Info(_x,_y,_d));
}

void Info::set(int xpos, int ypos, int direction)
{
   this->set_xpos(xpos);
   this->set_ypos(ypos);
   this->set_direction(direction);
}

void Info::set(int index, int direction)
{
   this->set_index(index);
   
   this->set_xpos(index/BOARD_SIZE);
   this->set_ypos(index%BOARD_SIZE);
   
   this->set_flag(1);
   this->set_direction(direction);
}

bool Info::operator==(const Info& info)
{
   return this->x_pos == info.get_xpos() && this->y_pos == info.get_ypos() && this->direction == info.get_direction();
}

PosInfo Chessmen_info::getiHasWonInfo(int which) const
{
	int x    = this->ihas_won[which]->get_xpos();
	int y    = this->ihas_won[which]->get_ypos();
	int dir  = this->ihas_won[which]->get_direction();
	int flag = this->ihas_won[which]->get_flag();
	PosInfo posInfo(x,y,dir,flag);
return posInfo;
}

PosInfo Chessmen_info::getiLive4Info(int which) const
{
	int x    = this->ilive4[which]->get_xpos();
	int y    = this->ilive4[which]->get_ypos();
	int dir  = this->ilive4[which]->get_direction();
	int flag = this->ilive4[which]->get_flag();
	PosInfo posInfo(x,y,dir,flag);
return posInfo;
}

PosInfo Chessmen_info::getiLive4HeapInfo(int which) const
{
	int x    = this->ilive4heap[which]->get_xpos();
	int y    = this->ilive4heap[which]->get_ypos();
	int dir  = this->ilive4heap[which]->get_direction();
	int flag = this->ilive4heap[which]->get_flag();
	PosInfo posInfo(x,y,dir,flag);
return posInfo;
}

PosInfo Chessmen_info::getiLive3Info(int which) const
{
	int x    = this->ilive3[which]->get_xpos();
	int y    = this->ilive3[which]->get_ypos();
	int dir  = this->ilive3[which]->get_direction();
	int flag = this->ilive3[which]->get_flag();
	PosInfo posInfo(x,y,dir,flag);
return posInfo;
}

PosInfo Chessmen_info::getiSleep3Info(int which) const
{
	int x    = this->isleep3[which]->get_xpos();
	int y    = this->isleep3[which]->get_ypos();
	int dir  = this->isleep3[which]->get_direction();
	int flag = this->isleep3[which]->get_flag();
	PosInfo posInfo(x,y,dir,flag);
return posInfo;
}

PosInfo Chessmen_info::getiLive2Info(int which) const
{
	int x    = this->ilive2[which]->get_xpos();
	int y    = this->ilive2[which]->get_ypos();
	int dir  = this->ilive2[which]->get_direction();
	int flag = this->ilive2[which]->get_flag();
	PosInfo posInfo(x,y,dir,flag);
return posInfo;
}

PosInfo Chessmen_info::getiSleep2Info(int which) const
{
	int x    = this->isleep2[which]->get_xpos();
	int y    = this->isleep2[which]->get_ypos();
	int dir  = this->isleep2[which]->get_direction();
	int flag = this->isleep2[which]->get_flag();
	PosInfo posInfo(x,y,dir,flag);
return posInfo;
}

Chessmen_info::Chessmen_info()
{
   memset(chessmen_of_each_direction,0,sizeof(chessmen_of_each_direction));
   for(int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++){
	ihas_won[i] = new Info();
	ilive4[i] = new Info();
	ilive4heap[i] = new Info();
	ilive3[i] = new Info();
	isleep3[i] = new Info();
	ilive2[i] = new Info();
	isleep2[i] = new Info();
   }
}

Chessmen_info::~Chessmen_info()
{
   for(int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++){
	delete ihas_won[i];
	delete ilive4[i];
	delete ilive4heap[i];
	delete ilive3[i];
	delete isleep3[i];
	delete ilive2[i];
	delete isleep2[i];
   }
}
void Chessmen_info::dumpiLivesInfo() const
{
	PosInfo posInfo;

	for(int i = 0; i < TOTALPOSSIZE; i++){
		posInfo = this->getiHasWonInfo(i);
		if(1 == posInfo.getFlag()){
			printf("ihas_won: x = %d, y = %d, direction = %d\n",posInfo.getxPos(),posInfo.getyPos(),posInfo.getDirection());
		}
		posInfo = this->getiLive4Info(i);
		if(1 == posInfo.getFlag()){
			printf("ilive4: x = %d, y = %d, direction = %d\n",posInfo.getxPos(),posInfo.getyPos(),posInfo.getDirection());
		}
		posInfo = this->getiLive4HeapInfo(i);
		if(1 == posInfo.getFlag()){
			printf("ilive4heap: x = %d, y = %d, direction = %d\n",posInfo.getxPos(),posInfo.getyPos(),posInfo.getDirection());
		}
		posInfo = this->getiLive3Info(i);
		if(1 == posInfo.getFlag()){
			printf("ilive3: x = %d, y = %d, direction = %d\n",posInfo.getxPos(),posInfo.getyPos(),posInfo.getDirection());
		}
		posInfo = this->getiSleep3Info(i);
		if(1 == posInfo.getFlag()){
			printf("isleep3: x = %d, y = %d, direction = %d\n",posInfo.getxPos(),posInfo.getyPos(),posInfo.getDirection());
		}
		posInfo = this->getiLive2Info(i);
		if(1 == posInfo.getFlag()){
			printf("ilive2: x = %d, y = %d, direction = %d\n",posInfo.getxPos(),posInfo.getyPos(),posInfo.getDirection());
		}
		posInfo = this->getiSleep2Info(i);
		if(1 == posInfo.getFlag()){
			printf("isleep2: x = %d, y = %d, direction = %d\n",posInfo.getxPos(),posInfo.getyPos(),posInfo.getDirection());
		}
	}
};

JudgeWin::JudgeWin()
{
  this->be_won = false;
  this->winner = '+';
  for(int i = 0;i < BOARD_SIZE; i++){
      for(int j = 0; j < BOARD_SIZE; j++){
            this->board_for_judge[i][j]= '+';
	 for(int k = 0 ; k < 8; k++){
	    this->judge_panel[i][j][k] = 0;
	 }
      }
  }
}

JudgeWin::~JudgeWin(){

}

void JudgeWin::copy_chessboard(const Chessboard& chessboard)
{
    for(int i = 0;i < BOARD_SIZE; i++){
      for(int j = 0; j < BOARD_SIZE; j++){
            this->board_for_judge[i][j]= chessboard.get_chess(i,j);
      }
    }
}

void JudgeWin::analysis_ilives(Chessmen_info* info, int level, int index, int direction)
{
	if(-1 == index || index > TOTALPOSSIZE){
		printf("error, index = %d\n",index);
		return;
	}
	
	switch(level){
	   case IHAS_WON:info->ihas_won[index]->set(index,direction);break; 
	   case ILIVE4:info->ilive4[index]->set(index,direction);break; 
	   case ILIVE4HEAP:info->ilive4heap[index]->set(index,direction);break; 
	   case ILIVE3:info->ilive3[index]->set(index,direction);break; 
	   case ISLEEP3:info->isleep3[index]->set(index,direction);break; 
	   case ILIVE2:info->ilive2[index]->set(index,direction);break; 
	   case ISLEEP2:info->isleep2[index]->set(index,direction);break;
	   default:break; 
	}	
}

void JudgeWin::rotate(int r)
{
	if(ROTATE0 == r){
		rotate0(this->board_for_judge);
	}
	else if(ROTATE90 == r){
		rotate90(this->board_for_judge);
	}
	else if(ROTATE180 == r){
		rotate180(this->board_for_judge);
	}
	else if(ROTATE270 == r){
		rotate270(this->board_for_judge);
	}
}

void JudgeWin::rotate0(s8 originBoard[][BOARD_SIZE])
{
	for(int i = 0; i < BOARD_SIZE; i++){
		for(int j = 0; j < BOARD_SIZE; j++){
			this->each_direction_board_for_judge[i][j] = originBoard[i][j];
		}
	}	
}

void JudgeWin::rotate90(s8 originBoard[][BOARD_SIZE])
{
	for(int i = 0; i < BOARD_SIZE; i++){
		for(int j = 0; j < BOARD_SIZE; j++){
			this->each_direction_board_for_judge[i][j] = originBoard[BOARD_SIZE - 1 - j][i];
		}
	}	
}

void JudgeWin::rotate180(s8 originBoard[][BOARD_SIZE])
{
	for(int i = 0; i < BOARD_SIZE; i++){
		for(int j = 0; j < BOARD_SIZE; j++){
			this->each_direction_board_for_judge[i][j] = originBoard[BOARD_SIZE - 1 - i][BOARD_SIZE - 1 - j];
		}
	}	
}

void JudgeWin::rotate270(s8 originBoard[][BOARD_SIZE])
{
	for(int i = 0; i < BOARD_SIZE; i++){
		for(int j = 0; j < BOARD_SIZE; j++){
			this->each_direction_board_for_judge[i][j] = originBoard[j][BOARD_SIZE - 1 - i];
		}
	}	
}

char JudgeWin::getOpesiteChessType(char c) const
{
	if('&' == c) return '@';
	else if('@' == c) return '&';
	else return '+';
}

char JudgeWin::getEmptyChessType() const
{
	return '+';
}

int JudgeWin::transferIndex(int i, int j, int rotate)
{
	int index = -1;

	if(ROTATE0 == rotate){
		index = i*BOARD_SIZE + j;
	}
	else if(ROTATE90 == rotate){  //90
		index = (BOARD_SIZE - 1 - j)*BOARD_SIZE + i;
	}
	else if(ROTATE180 == rotate){  //180
		index = (BOARD_SIZE - 1 - i)*BOARD_SIZE + (BOARD_SIZE - 1 - j);
	}
	else if(ROTATE270 == rotate){  //270
		index = j*BOARD_SIZE + (BOARD_SIZE - 1 - i);
	}
	
return index;
}

void JudgeWin::dumpIndex(int rotate)
{
	for(int i = 0; i < BOARD_SIZE; i++){
		for(int j = 0; j < BOARD_SIZE; j++){
			printf("rotate: %d, index0 = %d, index = %d\n",rotate,i*BOARD_SIZE + j, this->transferIndex(i,j,rotate));
		}
	}
}

void JudgeWin::analysis_for_each_direction(char chessman, s8 temp[][BOARD_SIZE], Chessmen_info * info,int rotate)
{
	int x_tmp;
	int y_tmp;
	int index = -1;
	int k = 0;
	int l = 0;
	char oChessman = this->getOpesiteChessType(chessman);
	char emptyTypeChessman = this->getEmptyChessType();

	for(int i = 0; i < BOARD_SIZE; i++){
		 for(int j = 0; j < BOARD_SIZE; j++){
		 	 //printf("xujiwei--->info1\n");
			 index = this->transferIndex(i, j, rotate);
			 if(temp[i][j] == chessman){
				 // -x direction(up)
				 for(k = i; k >= 0; k--){
					if(temp[k][j] == chessman) info->chessmen_of_each_direction[i][j][rotate] += 1;
					else break;
				 }

				 switch(info->chessmen_of_each_direction[i][j][rotate]){
					case 5:{
					 	this->analysis_ilives(info,IHAS_WON,index,rotate);
						//if(rotate == 2) printf("xujiwei...1, x = %d, y = %d\n",i,j);
					}break;
					
					case 4:{
						 if((k >= 0 && temp[k][j] == oChessman) || (k < 0)){
							 if((k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman)){
								this->analysis_ilives(info,IHAS_WON,index,rotate);
								//if(rotate == 2) printf("xujiwei...2, x = %d, y = %d\n",i,j);
							 }
							 else if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || k + 5 >= BOARD_SIZE){
								//nothing important
							 }
							 else{
								 this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
							 }
						 }
						 else{
							 if((k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman)){
								this->analysis_ilives(info,IHAS_WON,index,rotate);
								//if(rotate == 2) printf("xujiwei...2, x = %d, y = %d\n",i,j);
							 }
							 else if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || k + 5 >= BOARD_SIZE){
								this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
							 }
							 else{
							 	
								//if(((k >= 0 && temp[k][j] == oChessman) || (k < 0))){
								//		if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || (k + 5 >= BOARD_SIZE)){
										//no use lives;
								//		}
								//		else{
								//			this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
								//		}
								// }
								// else{
								//		if(k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman){
								//			this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
								//		}
								//		else{
								//		
											this->analysis_ilives(info,ILIVE4,index,rotate);
								//		}
								//}
							 }
						 }
					}break;
					
					case 3:{
						 if((k >= 0 && temp[k][j] == oChessman) || (k < 0)){
							 if((k + 4 < BOARD_SIZE && temp[k + 4][j] == chessman)){
							 	 if((k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman)){
									 this->analysis_ilives(info,IHAS_WON,index,rotate);
									 //if(rotate == 2) printf("xujiwei...3, x = %d, y = %d\n",i,j);
								 }
								 else{
									 this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
								 }
							 }
							 else if((k + 4 < BOARD_SIZE && temp[k + 4][j] == oChessman) || (k + 4 >= BOARD_SIZE)){
								//nothing important
							 }
							 else{
								 this->analysis_ilives(info,ISLEEP3,index,rotate);
								 printf("xujiwei...isleep3, 1, x = %d, y = %d\n",i,j);
							 }

						 }
						 else{
							 if(k - 1 >= 0 && temp[k - 1][j] == chessman){
								 if((k + 4 < BOARD_SIZE && temp[k + 4][j] == chessman)){
									if((k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman)){
										this->analysis_ilives(info,IHAS_WON,index,rotate);
										//if(rotate == 2) printf("xujiwei...4, x = %d, y = %d\n",i,j);
									}
									else if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || (k + 5 >= BOARD_SIZE)){
										this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
									}
									else{
										this->analysis_ilives(info,ILIVE4,index,rotate);
										printf("xujiwei...live4,1, x = %d, y = %d\n",i,j);
									}
								 }
								 else if((k + 4 < BOARD_SIZE && temp[k + 4][j] == oChessman) || (k + 4 >= BOARD_SIZE)){
									 this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
								 }
								 else{
									 this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
								 }
							 }
							 else if(k - 1 >= 0 && temp[k - 1][j] == oChessman || k -1 < 0){
								 if((k + 4 < BOARD_SIZE && temp[k + 4][j] == chessman)){
									if((k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman)){
										this->analysis_ilives(info,IHAS_WON,index,rotate);
										//if(rotate == 2) printf("xujiwei...4, x = %d, y = %d\n",i,j);
									}
									else if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || (k + 5 >= BOARD_SIZE)){
										this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
									}
									else{
										this->analysis_ilives(info,ILIVE4,index,rotate);
										printf("xujiwei...live4,2, x = %d, y = %d\n",i,j);
									}
								 }
								 else if((k + 4 < BOARD_SIZE && temp[k + 4][j] == oChessman) || (k + 4 >= BOARD_SIZE)){
								 	
								 }
								 else{
								 	 if((k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman)){
										 this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
									 }
									 else if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || (k + 5 >= BOARD_SIZE)){
										 this->analysis_ilives(info,ILIVE3,index,rotate);
									 }
									 else{
										 printf("xujiwei--->ilive3,14\n");
										 this->analysis_ilives(info,ILIVE3,index,rotate);
										 //printf("xujiwei...live3,3, x = %d, y = %d\n",i,j);
									 }
								 }
							 }
							 else{
								 if((k + 4 < BOARD_SIZE && temp[k + 4][j] == chessman)){
									if((k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman)){
										this->analysis_ilives(info,IHAS_WON,index,rotate);
										//if(rotate == 2) printf("xujiwei...4, x = %d, y = %d\n",i,j);
									}
									else if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || (k + 5 >= BOARD_SIZE)){
										this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
									}
									else{
										this->analysis_ilives(info,ILIVE4,index,rotate);
										printf("xujiwei...live4,4, x = %d, y = %d\n",i,j);
									}
								 }
								 else if((k + 4 < BOARD_SIZE && temp[k + 4][j] == oChessman) || (k + 4 >= BOARD_SIZE)){
									 this->analysis_ilives(info,ISLEEP3,index,rotate);
									 printf("xujiwei...isleep3, 2, x = %d, y = %d\n",i,j);
								 }
								 else{
									 printf("xujiwei--->ilive3,13\n");
									 this->analysis_ilives(info,ILIVE3,index,rotate);
								 }
							 }
						 }
					}break;
					
					case 2:{ 
						if((k >= 0 && temp[k][j] == oChessman) || (k < 0)){
							if(k + 3 < BOARD_SIZE && temp[k + 3][j] == chessman){
								if(k + 4 < BOARD_SIZE && temp[k + 4][j] == chessman){
									if(k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman){
										this->analysis_ilives(info,IHAS_WON,index,rotate);
										//if(rotate == 2) printf("xujiwei...5, x = %d, y = %d\n",i,j);
									}
									else if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || (k + 5 >= BOARD_SIZE)){

									}
									else{
										this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
									}
								}
								else if((k + 4 < BOARD_SIZE && temp[k + 4][j] == oChessman) || (k + 4 >= BOARD_SIZE)){

								}
								else{
									if(k + 4 < BOARD_SIZE && temp[k + 4][j] == chessman){
										if(k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman){
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
										}
										else if(k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman || k + 5 >= BOARD_SIZE){

										}
										else{
											this->analysis_ilives(info,ISLEEP3,index,rotate);
											printf("xujiwei...isleep3, 3, x = %d, y = %d\n",i,j);
										}
									}
									else if(k + 4 < BOARD_SIZE && temp[k + 4][j] == oChessman || k + 4 >= BOARD_SIZE){

									}
									else{
										if(k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman){
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
										}
										else if(k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman || k + 5 >= BOARD_SIZE){

										}
										else{
											this->analysis_ilives(info,ISLEEP3,index,rotate);
											printf("xujiwei...isleep3, 4, x = %d, y = %d\n",i,j);
										}

									}
								}
							}
							else if((k + 3 < BOARD_SIZE && temp[k + 3][j] == oChessman) || (k + 3 >= BOARD_SIZE)){

							}
							else{
								if(k + 4 < BOARD_SIZE && temp[k + 4][j] == chessman){
									if(k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman){
										this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
									}
									else if(k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman || k + 5 >= BOARD_SIZE){

									}
									else{
										this->analysis_ilives(info,ISLEEP3,index,rotate);
										printf("xujiwei...isleep3, 5, x = %d, y = %d\n",i,j);
									}

								}
								else if(k + 4 < BOARD_SIZE && temp[k + 4][j] == oChessman || k + 4 >= BOARD_SIZE){

								}
								else{
									this->analysis_ilives(info,ILIVE2,index,rotate);
								}
							}
						 }
						 else{ 
						 	 if(k - 1 >= 0 && temp[k - 1][j] == chessman){
							 	if(k - 2 >= 0 && temp[k - 2][j] == chessman){
									this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
								}
								else if(k -2 >= 0 && temp[k - 2][j] == oChessman || k -2 < 0){
									if(k + 3 < BOARD_SIZE && temp[k + 3][j] == chessman){
										if(k + 4 < BOARD_SIZE && temp[k + 4][j] == chessman){
											if(k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman){
												this->analysis_ilives(info,IHAS_WON,index,rotate);
												//if(rotate == 2) printf("xujiwei...6, x = %d, y = %d\n",i,j);
											}
											else if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || (k + 5 >= BOARD_SIZE)){
												this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
											}
											else{
												this->analysis_ilives(info,ILIVE4,index,rotate);
												printf("xujiwei...live4,5, x = %d, y = %d\n",i,j);
											}
										}
										else if(k + 4 < BOARD_SIZE && temp[k + 4][j] == oChessman || k + 4 >= BOARD_SIZE){
											this->analysis_ilives(info,ISLEEP3,index,rotate);
											printf("xujiwei...isleep3, 6, x = %d, y = %d\n",i,j);
										}
										else{
											printf("xujiwei--->ilive3,12\n");
											this->analysis_ilives(info,ILIVE3,index,rotate);
										}
									}
									else if(k + 3 < BOARD_SIZE && temp[k + 3][j] == oChessman || k + 3 >= BOARD_SIZE){

									}
									else{
										if(k + 4 < BOARD_SIZE && temp[k + 4][j] == chessman){
											if(k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman){
												this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
											}
											else if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || (k + 5 >= BOARD_SIZE)){
												this->analysis_ilives(info,ISLEEP3,index,rotate);
												printf("xujiwei...isleep3, 7, x = %d, y = %d\n",i,j);
											}
											else{
												printf("xujiwei--->ilive3,11\n");
												this->analysis_ilives(info,ILIVE3,index,rotate);
											}

										}
										else if((k + 4 < BOARD_SIZE && temp[k + 4][j] == oChessman) || (k + 4 >= BOARD_SIZE)){
											
										}
										else{
											this->analysis_ilives(info,ILIVE2,index,rotate);
										}
									}
								}
								else{
									if(k + 3 < BOARD_SIZE && temp[k + 3][j] == chessman){
										if(k + 4 < BOARD_SIZE && temp[k + 4][j] == chessman){
											if(k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman){
												this->analysis_ilives(info,IHAS_WON,index,rotate);
												//if(rotate == 2) printf("xujiwei...6, x = %d, y = %d\n",i,j);
											}
											else if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || (k + 5 >= BOARD_SIZE)){
												this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
											}
											else{
												this->analysis_ilives(info,ILIVE4,index,rotate);
												printf("xujiwei...live4,6, x = %d, y = %d\n",i,j);
											}
										}
										else if(k + 4 < BOARD_SIZE && temp[k + 4][j] == oChessman || k + 4 >= BOARD_SIZE){
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
										}
										else{
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
										}
									}
									else if(k + 3 < BOARD_SIZE && temp[k + 3][j] == oChessman || k + 3 >= BOARD_SIZE){
										this->analysis_ilives(info,ISLEEP3,index,rotate);
										printf("xujiwei...isleep3, 8, x = %d, y = %d\n",i,j);
									}
									else{
										printf("xujiwei--->ilive3,10\n");
										this->analysis_ilives(info,ILIVE3,index,rotate);
									}
								}

							 }
							 else if(k - 1 >= 0 && temp[k - 1][j] == oChessman || k -1 < 0){
								 if(k + 3 < BOARD_SIZE && temp[k + 3][j] == chessman){
									 if(k + 4 < BOARD_SIZE && temp[k + 4][j] == chessman){
										 if(k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman){
											 this->analysis_ilives(info,IHAS_WON,index,rotate);
											 //if(rotate == 2) printf("xujiwei...6, x = %d, y = %d\n",i,j);
										 }
										 else if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || (k + 5 >= BOARD_SIZE)){
											 this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
										 }
										 else{
											 this->analysis_ilives(info,ILIVE4,index,rotate);
											 printf("xujiwei...live4,7, x = %d, y = %d\n",i,j);
										 }
									 }
									 else if((k + 4 < BOARD_SIZE && temp[k + 4][j] == oChessman) || (k + 4 >= BOARD_SIZE)){
									 }
									 else{
										 printf("xujiwei--->ilive3,9\n");
										 this->analysis_ilives(info,ILIVE3,index,rotate);
									 }
								 }
								 else if((k + 3 < BOARD_SIZE && temp[k + 3][j] == oChessman) || (k + 3 >= BOARD_SIZE)){
			 
								 }
								 else{
								 	 if(k + 4 < BOARD_SIZE && temp[k + 4][j] == chessman){
									 	if(k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman){
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
										}
										else if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || (k + 5 >= BOARD_SIZE)){
											this->analysis_ilives(info,ISLEEP3,index,rotate);
											printf("xujiwei...isleep3, 9, x = %d, y = %d\n",i,j);
										}
										else{

										}

									 }
									 else if((k + 4 < BOARD_SIZE && temp[k + 4][j] == oChessman) || (k + 4 >= BOARD_SIZE)){

									 }
									 else{
										 this->analysis_ilives(info,ILIVE2,index,rotate);
									 }
								 }
							 }
							 else{
								 if(k + 3 < BOARD_SIZE && temp[k + 3][j] == chessman){
									 if(k + 4 < BOARD_SIZE && temp[k + 4][j] == chessman){
										 if(k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman){
											 this->analysis_ilives(info,IHAS_WON,index,rotate);
											 //if(rotate == 2) printf("xujiwei...6, x = %d, y = %d\n",i,j);
										 }
										 else if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || (k + 5 >= BOARD_SIZE)){
											 this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
										 }
										 else{
											 this->analysis_ilives(info,ILIVE4,index,rotate);
											 printf("xujiwei...live4,8, x = %d, y = %d\n",i,j);
										 }
									 }
									 else if((k + 4 < BOARD_SIZE && temp[k + 4][j] == oChessman) || (k + 4 >= BOARD_SIZE)){
											 this->analysis_ilives(info,ISLEEP3,index,rotate);
											 printf("xujiwei...isleep3, 10, x = %d, y = %d\n",i,j);
									 }
									 else{
										printf("xujiwei--->ilive3,8\n");
										 this->analysis_ilives(info,ILIVE3,index,rotate);
									 }
								 }
								 else if((k + 3 < BOARD_SIZE && temp[k + 3][j] == oChessman) || (k + 3 >= BOARD_SIZE)){
								 		 printf("xujiwei...isleep2, 1, x = %d, y = %d\n",i,j);
										 this->analysis_ilives(info,ISLEEP2,index,rotate);				 
								 }
								 else{
								 	 if(k - 2 >= 0 && temp[k - 2][j] == chessman){
										 this->analysis_ilives(info,ISLEEP3,index,rotate);
										 printf("xujiwei...isleep3, 11, x = %d, y = %d\n",i,j);
									 }
									 else if(k -2 >= 0 && temp[k - 2][j] == oChessman || k -2 < 0){
										 this->analysis_ilives(info,ILIVE2,index,rotate);
									 }
									 else{
										 this->analysis_ilives(info,ILIVE2,index,rotate);
									 }
								 }
							 }
						 }
					}break;
					
					case 1:{
						if(k >= 0 && temp[k][j] == oChessman){
							if(k + 2 < BOARD_SIZE && temp[k + 2][j] == chessman){
								if(k + 3 < BOARD_SIZE && temp[k + 3][j] == chessman){
									if(k + 4 < BOARD_SIZE && temp[k + 4][j] == chessman){
										if(k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman){
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
										}
										else if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || (k + 5 >= BOARD_SIZE)){
											this->analysis_ilives(info,ISLEEP3,index,rotate);
											printf("xujiwei...isleep3, 13, x = %d, y = %d\n",i,j);
										}
										else{
											//this->analysis_ilives(info,ILIVE3,index,rotate);
											//printf("xujiwei ----> ilive 3, 3\n");
										}
									}
									else if((k + 4 < BOARD_SIZE && temp[k + 4][j] == oChessman) || (k + 4 >= BOARD_SIZE)){

									}
									else{
										this->analysis_ilives(info,ISLEEP3,index,rotate);
									}
								}
								else if((k + 3 < BOARD_SIZE && temp[k + 3][j] == oChessman) || (k + 3 >= BOARD_SIZE)){

								}
								else{
									this->analysis_ilives(info,ILIVE2,index,rotate);
								}
							}
							else if((k + 2 < BOARD_SIZE && temp[k + 2][j] == oChessman) || (k + 2 >= BOARD_SIZE)){

							}
							else{
							   if(k + 3 < BOARD_SIZE && temp[k + 3][j] == chessman){
							   		if(k + 4 < BOARD_SIZE && temp[k + 4][j] == chessman){
										if(k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman){
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
										}
										else if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || (k + 5 >= BOARD_SIZE)){

										}
										else{
											this->analysis_ilives(info,ISLEEP3,index,rotate);
										}
									}
									else if((k + 4 < BOARD_SIZE && temp[k + 4][j] == oChessman) || (k + 4 >= BOARD_SIZE)){

									}
									else{
										if(k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman){
											
										}
										else if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || (k + 5 >= BOARD_SIZE)){

										}
										else{
											this->analysis_ilives(info,ISLEEP3,index,rotate);
										}
									}
							   }
							   else if((k + 3 < BOARD_SIZE && temp[k + 3][j] == oChessman) || (k + 3 >= BOARD_SIZE)){

							   }
							   else{
								   	if(k + 3 < BOARD_SIZE && temp[k + 3][j] == chessman){
										if(k + 4 < BOARD_SIZE && temp[k + 4][j] == chessman){
											if(k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman){
												this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
											}
											else if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || (k + 5 >= BOARD_SIZE)){

											}
											else{
												this->analysis_ilives(info,ISLEEP3,index,rotate);
											}
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
										}
										else if((k + 4 < BOARD_SIZE && temp[k + 4][j] == oChessman) || (k + 4 >= BOARD_SIZE)){

										}
										else{
											if(k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman){
												this->analysis_ilives(info,ISLEEP3,index,rotate);
											}
											else if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || (k + 5 >= BOARD_SIZE)){

											}
											else{
												this->analysis_ilives(info,ISLEEP3,index,rotate);
											}
										}
									}
									else if((k + 3 < BOARD_SIZE && temp[k + 3][j] == oChessman) || (k + 3 >= BOARD_SIZE)){

									}
									else{
										if(k + 4 < BOARD_SIZE && temp[k + 4][j] == chessman){
											if(k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman){
												this->analysis_ilives(info,ISLEEP3,index,rotate);
											}
											else if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || (k + 5 >= BOARD_SIZE)){
												
											}
											else{
												printf("xujiwei...isleep2, 3, x = %d, y = %d\n",i,j);
												this->analysis_ilives(info,ISLEEP2,index,rotate);
											}
										}
										else if((k + 4 < BOARD_SIZE && temp[k + 4][j] == oChessman) || (k + 4 >= BOARD_SIZE)){

										}
										else{

										}
									}
							   }
							}
							
						}
						else{
							if(k - 1 >= 0 && temp[k - 1][j] == chessman){
								if(k - 2 >= 0 && temp[k - 2][j] == chessman){
									if(k - 3 >= 0 && temp[k - 3][j] == chessman){
										this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
									}
									else if(k - 3 >= 0 && temp[k - 3][j] == oChessman || k - 3 < 0){
										if(k + 2 < BOARD_SIZE && temp[k + 2][j] == chessman){
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
										}
										else if((k + 2 < BOARD_SIZE && temp[k + 2][j] == oChessman) || (k + 2 >= BOARD_SIZE)){

										}
										else{
											this->analysis_ilives(info,ISLEEP3,index,rotate);
										}
									}
									else{
										if(k + 2 < BOARD_SIZE && temp[k + 2][j] == chessman){
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
										}
										else if((k + 2 < BOARD_SIZE && temp[k + 2][j] == oChessman) || (k + 2 >= BOARD_SIZE)){
											this->analysis_ilives(info,ISLEEP3,index,rotate);
										}
										else{
											this->analysis_ilives(info,ISLEEP3,index,rotate);
										}
									}
								}
								else if(k - 2 >= 0 && temp[k - 2][j] == oChessman || k - 2 < 0){
									if(k + 2 < BOARD_SIZE && temp[k + 2][j] == chessman){
										if(k + 3 < BOARD_SIZE && temp[k + 3][j] == chessman){
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
										}
										else if((k + 3 < BOARD_SIZE && temp[k + 3][j] == oChessman) || (k + 3 >= BOARD_SIZE)){

										}
										else{
											this->analysis_ilives(info,ISLEEP3,index,rotate);
										}
										
									}
									else if((k + 2 < BOARD_SIZE && temp[k + 2][j] == oChessman) || (k + 2 >= BOARD_SIZE)){
									
									}
									else{
										if(k + 3 < BOARD_SIZE && temp[k + 3][j] == chessman){
											this->analysis_ilives(info,ISLEEP3,index,rotate);
										}
										else if((k + 3 < BOARD_SIZE && temp[k + 3][j] == oChessman) || (k + 3 >= BOARD_SIZE)){

										}
										else{
											printf("xujiwei...isleep2, 4, x = %d, y = %d\n",i,j);
											this->analysis_ilives(info,ISLEEP2,index,rotate);
										}
									}
								}
								else{
									if(k + 2 < BOARD_SIZE && temp[k + 2][j] == chessman){
										if(k + 3 < BOARD_SIZE && temp[k + 3][j] == chessman){
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
										}
										else if((k + 3 < BOARD_SIZE && temp[k + 3][j] == oChessman) || (k + 3 >= BOARD_SIZE)){
											this->analysis_ilives(info,ISLEEP3,index,rotate);
										}
										else{
											printf("xujiwei--->ilive3,6\n");
											this->analysis_ilives(info,ILIVE3,index,rotate);
										}

									}
									else if((k + 2 < BOARD_SIZE && temp[k + 2][j] == oChessman) || (k + 2 >= BOARD_SIZE)){
										this->analysis_ilives(info,ISLEEP3,index,rotate);
									}
									else{
										this->analysis_ilives(info,ILIVE2,index,rotate);
									}
								}
							}
							else if(k - 1 >= 0 && temp[k - 1][j] == oChessman || k - 1 < 0){
								if(k + 2 < BOARD_SIZE && temp[k + 2][j] == chessman){
									if(k + 3 < BOARD_SIZE && temp[k + 3][j] == chessman){
										if(k + 4 < BOARD_SIZE && temp[k + 4][j] == chessman){
											if(k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman){
												this->analysis_ilives(info,IHAS_WON,index,rotate);
											}
											else if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || (k + 5 >= BOARD_SIZE)){
												this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
											}
											else{
												this->analysis_ilives(info,ILIVE4,index,rotate);
											}
										}
										else if((k + 4 < BOARD_SIZE && temp[k + 4][j] == oChessman) || (k + 4 >= BOARD_SIZE)){

										}
										else{
											printf("xujiwei--->ilive3,5\n");
											this->analysis_ilives(info,ILIVE3,index,rotate);
										}
									}
									else if((k + 3 < BOARD_SIZE && temp[k + 3][j] == oChessman) || (k + 3 >= BOARD_SIZE)){
										if(k + 4 < BOARD_SIZE && temp[k + 4][j] == chessman){
											if(k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman){
												this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
											}
											else if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || (k + 5 >= BOARD_SIZE)){
												this->analysis_ilives(info,ISLEEP3,index,rotate);
											}
											else{
												printf("xujiwei--->ilive3,4\n");
												this->analysis_ilives(info,ILIVE3,index,rotate);
											}
										}
										else if((k + 4 < BOARD_SIZE && temp[k + 4][j] == oChessman) || (k + 4 >= BOARD_SIZE)){

										}
										else{
											printf("xujiwei--->ilive3,3\n");
											this->analysis_ilives(info,ILIVE3,index,rotate);
										}
									}
									else{
										if(k + 4 < BOARD_SIZE && temp[k + 4][j] == chessman){
											if(k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman){
												this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
											}
											else if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || (k + 5 >= BOARD_SIZE)){
												this->analysis_ilives(info,ISLEEP3,index,rotate);
											}
											else{
												printf("xujiwei--->ilive3,2\n");
												this->analysis_ilives(info,ILIVE3,index,rotate);
											}
										}
										else if((k + 4 < BOARD_SIZE && temp[k + 4][j] == oChessman) || (k + 4 >= BOARD_SIZE)){

										}
										else{
											this->analysis_ilives(info,ILIVE2,index,rotate);
										}
									}
								}
								else if((k + 2 < BOARD_SIZE && temp[k + 2][j] == oChessman) || (k + 2 >= BOARD_SIZE)){

								}
								else{
									if(k + 3 < BOARD_SIZE && temp[k + 3][j] == chessman){
										if(k + 4 < BOARD_SIZE && temp[k + 4][j] == chessman){
											if(k + 5 < BOARD_SIZE && temp[k + 5][j] == chessman){
												this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
											}
											else if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || (k + 5 >= BOARD_SIZE)){
												this->analysis_ilives(info,ISLEEP3,index,rotate);
											}
											else{
												printf("xujiwei--->ilive3,1\n");
												this->analysis_ilives(info,ILIVE3,index,rotate);
											}
										}
										else if((k + 4 < BOARD_SIZE && temp[k + 4][j] == oChessman) || (k + 4 >= BOARD_SIZE)){
											
										}
										else{
											this->analysis_ilives(info,ILIVE2,index,rotate);
										}
									}
									else if((k + 3 < BOARD_SIZE && temp[k + 3][j] == oChessman) || (k + 3 >= BOARD_SIZE)){
									
									}
									else{//need more analysis down 2018.4.16
										if(k + 4 < BOARD_SIZE && temp[k + 4][j] == chessman){
											printf("xujiwei...isleep2, 6, x = %d, y = %d\n",i,j);
											this->analysis_ilives(info,ISLEEP2,index,rotate);
										}
										else if((k + 4 < BOARD_SIZE && temp[k + 4][j] == oChessman) || (k + 4 >= BOARD_SIZE)){

										}
										else{

										}
									}
								}
							}
							else{

							}
						}
					}break;
					default:break;
				 }
			 }
			 else{ continue;}
			 
			 if(temp[i][j] == chessman){
				 // -x +y direction(up|right)
				 /*
				 for(k = i, l = j; k >= 0, j < BOARD_SIZE; k--, l++){
					if(temp[k][l] == chessman) info->chessmen_of_each_direction[i][j][rotate + 1] += 1;
					else break;
				 }

				 switch(info->chessmen_of_each_direction[i][j][rotate + 1]){
					case 5:{
					 	this->analysis_ilives(info,IHAS_WON,index,rotate + 1);
					}break;
					
					case 4:{
						 if(((k + 5 < BOARD_SIZE && l - 5 >= 0)&& temp[k + 5][l - 5] == chessman)){
							this->analysis_ilives(info,IHAS_WON,index,rotate + 1);
						 }
						 else{
							 if(((k >= 0 && l < BOARD_SIZE && temp[k][l] == oChessman) || ((k < 0) || l >= BOARD_SIZE))){
									if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || ((k + 5 >= BOARD_SIZE) || l -5 < 0)){
						 	 		//no use lives;
									}
									else{
										this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
									}
							 }
							 else{
									if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman){
										this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
									}
									else{
										this->analysis_ilives(info,ILIVE4,index,rotate + 1);
									}
							}
						 }
					}break;
					
					case 3:{
						 if((k >= 0 && l < BOARD_SIZE && temp[k][l] == oChessman) || ((k < 0) || l >= BOARD_SIZE)){
							 if((k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == chessman)){
							 	 if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman)){
									 this->analysis_ilives(info,IHAS_WON,index,rotate + 1);
								 }
								 else{
									 this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
								 }
							 }
							 else if((k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == oChessman) || ((k + 4 >= BOARD_SIZE) || l - 4 < 0 )){
								//nothing important
							 }
							 else{
								 this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
							 }

						 }
						 else{
							 if((k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == chessman)){
								if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman)){
									this->analysis_ilives(info,IHAS_WON,index,rotate + 1);
								}
								else if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || ((k + 5 >= BOARD_SIZE) || l - 5 < 0)){
									this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
								}
								else{
									this->analysis_ilives(info,ILIVE4,index,rotate + 1);
								}
							 }
							 else if((k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == oChessman) || ((k + 4 >= BOARD_SIZE) || l - 4 < 0)){
								 this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
							 }
							 else{
								 this->analysis_ilives(info,ILIVE3,index,rotate + 1);
							 }
						 }
					}break;
					
					case 2:{
						if((k >= 0  && l < BOARD_SIZE && temp[k][l] == oChessman) || ((k < 0) || l >= BOARD_SIZE)){
							if(k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == chessman){
								if(k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == chessman){
									if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman){
										this->analysis_ilives(info,IHAS_WON,index,rotate + 1);
									}
									else if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || (k + 5 >= BOARD_SIZE || l - 5 < 0)){

									}
									else{
										this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
									}
								}
								else if((k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == oChessman) || (k + 4 >= BOARD_SIZE || l - 4 < 0)){

								}
								else{
									this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
								}
							}
							else if((k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == oChessman) || (k + 3 >= BOARD_SIZE || l - 3 < 0)){

							}
							else{
								this->analysis_ilives(info,ISLEEP2,index,rotate + 1);
							}
						 }
						 else{
							 if(k + 3 < BOARD_SIZE && l - 3 > 0 && temp[k + 3][l - 3] == chessman){
								 if(k + 4 < BOARD_SIZE && l - 4 > 0 && temp[k + 4][l - 4] == chessman){
									 if(k + 5 < BOARD_SIZE && l - 5 > 0 && temp[k + 5][l - 5] == chessman){
										 this->analysis_ilives(info,IHAS_WON,index,rotate + 1);
									 }
									 else if((k + 5 < BOARD_SIZE && l - 5 > 0 && temp[k + 5][l - 5] == oChessman) || ((k + 5 >= BOARD_SIZE) || l - 5 < 0)){
							 			 this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
									 }
									 else{
										 this->analysis_ilives(info,ILIVE4,index,rotate + 1);
									 }
								 }
								 else if((k + 4 < BOARD_SIZE && l - 4 > 0 && temp[k + 4][1 - 4] == oChessman) || ((k + 4 >= BOARD_SIZE) || l - 4 < 0)){
							 			 this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
								 }
								 else{
									 this->analysis_ilives(info,ILIVE3,index,rotate + 1);
								 }
							 }
							 else if((k + 3 < BOARD_SIZE  && l - 3 > 0 && temp[k + 3][l - 3] == oChessman) || ((k + 3 >= BOARD_SIZE) || l - 3 <  0)){
									 this->analysis_ilives(info,ISLEEP2,index,rotate + 1);				 
							 }
							 else{
								 this->analysis_ilives(info,ILIVE2,index,rotate + 1);
							 }
						 }
					}break;
					
					case 1:{
						if((k >= 0  && l < BOARD_SIZE && temp[k][l] == oChessman) || ((k < 0) || l >= BOARD_SIZE)){
							if(k + 2 < BOARD_SIZE && l - 2 >= 0 && temp[k + 2][l - 2] == chessman){
								if(k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == chessman){
									if(k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == chessman){
										if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman){
											this->analysis_ilives(info,IHAS_WON,index,rotate + 1);
										}
										else if((k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == oChessman) || ((k + 4 >= BOARD_SIZE) || l - 4 < 0)){

										}
										else{
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
										}

									}
									else if((k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == oChessman) || ((k + 3 >= BOARD_SIZE)|| l - 3 < 0)){

									}
									else{
										this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
									}
								}
								else if((k + 2 < BOARD_SIZE && l - 2 >= 0 && temp[k + 2][l - 2] == oChessman) || ((k + 2 >= BOARD_SIZE)|| l - 2 < 0)){

								}
								else{
									this->analysis_ilives(info,ISLEEP2,index,rotate + 1);
								}
							}
							else{

							}
						 }
						 else{
							 if(k + 2 < BOARD_SIZE && l - 2 >= 0 && temp[k + 2][l - 2] == chessman){
								 if(k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == chessman){
									 if(k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == chessman){
									 	 if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman){
											 this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
										 }
										 else if((k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == oChessman) || ((k + 4 >= BOARD_SIZE) || l - 4 < 0)){
											 this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
										 }
										 else{
											 this->analysis_ilives(info,ILIVE3,index,rotate + 1);
										 }
									 }
									 else if((k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == oChessman) || ((k + 3 >= BOARD_SIZE) || l - 3 < 0)){
							 			 this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
									 }
									 else{
										 this->analysis_ilives(info,ILIVE3,index,rotate + 1);
									 }
								 }
								 else if((k + 2 < BOARD_SIZE  && l - 2 >= 0 && temp[k + 2][l - 2] == oChessman) || ((k + 2 >= BOARD_SIZE)|| l - 2 < 0)){
							 			 this->analysis_ilives(info,ISLEEP2,index,rotate + 1);
								 }
								 else{
									 this->analysis_ilives(info,ILIVE2,index,rotate + 1);
								 }
							 }
							 else{
							 	
							 }
						 }
					}break;
					default:break;
				 } */

				 /* should analysis up|right direction*/
				 for(k = i, l = j; k >= 0, l < BOARD_SIZE; k--, l++){
					//printf("k = %d, l = %d\n", k, l);
					if(temp[k][l] == chessman) info->chessmen_of_each_direction[i][j][rotate + 1] += 1;
					else break;
				 }
				 //printf("xujiwei---> info->chessmen_of_each_direction[i][j][rotate + 1] = %d\n",info->chessmen_of_each_direction[i][j][rotate + 1]);

				 switch(info->chessmen_of_each_direction[i][j][rotate + 1]){
					case 5:{
					 	this->analysis_ilives(info,IHAS_WON,index,rotate + 1);
						//if(rotate == 2) printf("xujiwei...1, x = %d, y = %d\n",i,j);
					}break;
					
					case 4:{
						 if((k >= 0 && l < BOARD_SIZE && temp[k][l] == oChessman)){
							 if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman)){
								this->analysis_ilives(info,IHAS_WON,index,rotate + 1);
								//if(rotate == 2) printf("xujiwei...2, x = %d, y = %d\n",i,j);
							 }
							 else if(((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || k + 5 >= BOARD_SIZE) || l - 5 < 0){
								//nothing important
							 }
							 else{
								 this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
							 }
						 }
						 else{
							 if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman)){
								this->analysis_ilives(info,IHAS_WON,index,rotate + 1);
								//if(rotate == 2) printf("xujiwei...2, x = %d, y = %d\n",i,j);
							 }
							 else if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || k + 5 > BOARD_SIZE || l - 5 < 0){
								this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
							 }
							 else{
							 	
								//if(((k >= 0 && temp[k][j] == oChessman) || (k < 0))){
								//		if((k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman) || (k + 5 >= BOARD_SIZE)){
										//no use lives;
								//		}
								//		else{
								//			this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
								//		}
								// }
								// else{
								//		if(k + 5 < BOARD_SIZE && temp[k + 5][j] == oChessman){
								//			this->analysis_ilives(info,ILIVE4HEAP,index,rotate);
								//		}
								//		else{
								//		
											this->analysis_ilives(info,ILIVE4,index,rotate + 1);
								//		}
								//}
							 }
						 }
					}break;
					
					case 3:{
						 if((k >= 0 && l < BOARD_SIZE && temp[k][l] == oChessman) || (k < 0) || (l >= BOARD_SIZE)){
							 if((k + 4 < BOARD_SIZE && l - 4 >= 0  && temp[k + 4][l - 4] == chessman)){
							 	 if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman)){
									 this->analysis_ilives(info,IHAS_WON,index,rotate + 1);
									 //if(rotate == 2) printf("xujiwei...3, x = %d, y = %d\n",i,j);
								 }
								 else{
									 this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
								 }
							 }
							 else if((k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == oChessman) || (k + 4 >= BOARD_SIZE) || (l - 4 < 0)){
								//nothing important
							 }
							 else{
								 this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
								 printf("xujiwei...isleep3, 1, x = %d, y = %d\n",k,l);
							 }

						 }
						 else{
							 if(k - 1 >= 0 &&  l + 1 < BOARD_SIZE && temp[k - 1][l + 1] == chessman){
								 if((k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == chessman)){
									if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman)){
										this->analysis_ilives(info,IHAS_WON,index,rotate + 1);
										//if(rotate == 2) printf("xujiwei...4, x = %d, y = %d\n",i,j);
									}
									else if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || (k + 5 >= BOARD_SIZE)|| (l - 5 < 0)){
										this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
									}
									else{
										this->analysis_ilives(info,ILIVE4,index,rotate + 1);
										printf("xujiwei...live4,1, x = %d, y = %d\n",k,l);
									}
								 }
								 else if((k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == oChessman) || (k + 4 >= BOARD_SIZE)|| (l - 4 < 0)){
									 this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
								 }
								 else{
									 this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
								 }
							 }
							 else if(k - 1 >= 0 && l + 1 < BOARD_SIZE && temp[k - 1][l - 1] == oChessman || k - 1 < 0 || l + 1 >= BOARD_SIZE){
								 if((k + 4 < BOARD_SIZE && l - 4 >= 0  && temp[k + 4][l - 4] == chessman)){
									if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman)){
										this->analysis_ilives(info,IHAS_WON,index,rotate + 1);
										//if(rotate == 2) printf("xujiwei...4, x = %d, y = %d\n",i,j);
									}
									else if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || (k + 5 >= BOARD_SIZE) || l - 5 < 0){
										this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
									}
									else{
										this->analysis_ilives(info,ILIVE4,index,rotate + 1);
										printf("xujiwei...live4,2, x = %d, y = %d\n",k,l);
									}
								 }
								 else if((k + 4 < BOARD_SIZE && l - 4 >= 0  && temp[k + 4][l - 4] == oChessman) || (k + 4 >= BOARD_SIZE) || l - 4 < 0){
								 	
								 }
								 else{
								 	 if((k + 5 < BOARD_SIZE && l - 5 >= 0  && temp[k + 5][l - 5] == chessman)){
										 this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
									 }
									 else if((k + 5 < BOARD_SIZE && l - 5 >= 0  && temp[k + 5][l - 5] == oChessman) || (k + 5 >= BOARD_SIZE) || l - 5 < 0){
										 this->analysis_ilives(info,ILIVE3,index,rotate + 1);
									 }
									 else{
										 this->analysis_ilives(info,ILIVE3,index,rotate + 1);
										 printf("xujiwei...live3,3, x = %d, y = %d\n",k,l);
									 }
								 }
							 }
							 else{
								 if((k + 4 < BOARD_SIZE && l - 4 >= 0  && temp[k + 4][l - 4] == chessman)){
									if((k + 5 < BOARD_SIZE && l - 5 >= 0  && temp[k + 5][l - 5] == chessman)){
										this->analysis_ilives(info,IHAS_WON,index,rotate + 1);
										//if(rotate == 2) printf("xujiwei...4, x = %d, y = %d\n",i,j);
									}
									else if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || (k + 5 >= BOARD_SIZE) || l - 5 < 0){
										this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
									}
									else{
										this->analysis_ilives(info,ILIVE4,index,rotate + 1);
										printf("xujiwei...live4,4, x = %d, y = %d\n",k,l);
									}
								 }
								 else if((k + 4 < BOARD_SIZE && l - 4 >= 0 &&temp[k + 4][l - 4] == oChessman) || (k + 4 >= BOARD_SIZE) || l - 4 < 0){
									 this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
									 printf("xujiwei...isleep3, 2, x = %d, y = %d\n",i,j);
								 }
								 else{
									 this->analysis_ilives(info,ILIVE3,index,rotate + 1);
								 }
							 }
						 }
					}break;
					
					case 2:{ 
						if((k >= 0 && l < BOARD_SIZE && temp[k][l] == oChessman) || (k < 0) || l >= BOARD_SIZE){
							if(k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == chessman){
								if(k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == chessman){
									if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman){
										this->analysis_ilives(info,IHAS_WON,index,rotate + 1);
										//if(rotate == 2) printf("xujiwei...5, x = %d, y = %d\n",i,j);
									}
									else if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || (k + 5 >= BOARD_SIZE) || l - 5 < 0){

									}
									else{
										this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
									}
								}
								else if((k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == oChessman) || (k + 4 >= BOARD_SIZE)|| l - 4 < 0){

								}
								else{
									if(k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == chessman){
										if(k + 5 < BOARD_SIZE && temp[k + 5][l - 5] == chessman){
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
										}
										else if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman || k + 5 >= BOARD_SIZE || l - 5 < 0){

										}
										else{
											this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
											printf("xujiwei...isleep3, 3, x = %d, y = %d\n",k,l);
										}
									}
									else if(k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == oChessman || k + 4 >= BOARD_SIZE || l - 4 < 0){

									}
									else{
										if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman){
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
										}
										else if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman || k + 5 >= BOARD_SIZE || l - 5 < 0){

										}
										else{
											this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
											printf("xujiwei...isleep3, 4, x = %d, y = %d\n",k,l);
										}

									}
								}
							}
							else if((k + 3 < BOARD_SIZE && l -3 >= 0 && temp[k + 3][l - 3] == oChessman) || (k + 3 >= BOARD_SIZE) || l - 3 < 0){

							}
							else{
								if(k + 4 < BOARD_SIZE && l - 3 >= 0 && temp[k + 4][l - 3] == chessman){
									if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman){
										this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
									}
									else if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman || k + 5 >= BOARD_SIZE || l - 5 < 0 ){

									}
									else{
										this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
										printf("xujiwei...isleep3, 5, x = %d, y = %d\n",k,l);
									}

								}
								else if(k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == oChessman || k + 4 >= BOARD_SIZE || l - 4 < 0){

								}
								else{
									this->analysis_ilives(info,ILIVE2,index,rotate + 1);
								}
							}
						 }
						 else{
						 	 if(k - 1 >= 0 && l + 1 < BOARD_SIZE && temp[k - 1][l + 1] == chessman){
							 	if(k - 2 >= 0 && l + 2 < BOARD_SIZE && temp[k - 2][l + 2] == chessman){
									this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
								}
								else if(k - 2 >= 0 &&  l + 2 < BOARD_SIZE && temp[k - 2][l + 2] == oChessman || k - 2 < 0 || l + 2 >= BOARD_SIZE){
									if(k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == chessman){
										if(k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == chessman){
											if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman){
												this->analysis_ilives(info,IHAS_WON,index,rotate + 1);
												//if(rotate == 2) printf("xujiwei...6, x = %d, y = %d\n",i,j);
											}
											else if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || (k + 5 >= BOARD_SIZE) || l - 5 < 0){
												this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
											}
											else{
												this->analysis_ilives(info,ILIVE4,index,rotate + 1);
												printf("xujiwei...live4,5, x = %d, y = %d\n",k,l);
											}
										}
										else if(k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == oChessman || k + 4 >= BOARD_SIZE || l - 4 < 0){
											this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
											printf("xujiwei...isleep3, 6, x = %d, y = %d\n",k,l);
										}
										else{
											this->analysis_ilives(info,ILIVE3,index,rotate + 1);
										}
									}
									else if(k + 3 < BOARD_SIZE  && l - 3 >= 0 && temp[k + 3][l - 3] == oChessman || k + 3 >= BOARD_SIZE || l - 3 < 0){

									}
									else{
										if(k + 4 < BOARD_SIZE  && l - 4 >= 0 && temp[k + 4][l - 4] == chessman){
											if(k + 5 < BOARD_SIZE  && l - 5 >= 0 && temp[k + 5][l - 5] == chessman){
												this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
											}
											else if((k + 5 < BOARD_SIZE  && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || (k + 5 >= BOARD_SIZE) || l - 5 < 0){
												this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
												printf("xujiwei...isleep3, 7, x = %d, y = %d\n",k,l);
											}
											else{
												this->analysis_ilives(info,ILIVE3,index,rotate + 1);
											}

										}
										else if((k + 4 < BOARD_SIZE  && l - 4 >= 0 && temp[k + 4][l - 4] == oChessman) || (k + 4 >= BOARD_SIZE) || l - 4 < 0){
											
										}
										else{
											this->analysis_ilives(info,ILIVE2,index,rotate + 1);
										}
									}
								}
								else{
									if(k + 3 < BOARD_SIZE  && l - 3 >= 0 && temp[k + 3][l - 3] == chessman){
										if(k + 4 < BOARD_SIZE  && l - 4 >= 0 && temp[k + 4][l - 4] == chessman){
											if(k + 5 < BOARD_SIZE  && l - 5 >= 0 && temp[k + 5][l - 5] == chessman){
												this->analysis_ilives(info,IHAS_WON,index,rotate + 1);
												//if(rotate == 2) printf("xujiwei...6, x = %d, y = %d\n",i,j);
											}
											else if((k + 5 < BOARD_SIZE  && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || (k + 5 >= BOARD_SIZE) || l - 5 < 0){
												this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
											}
											else{
												this->analysis_ilives(info,ILIVE4,index,rotate + 1);
												printf("xujiwei...live4,6, x = %d, y = %d\n",k,l);
											}
										}
										else if(k + 4 < BOARD_SIZE  && l - 4 >= 0 && temp[k + 4][l - 4] == oChessman || k + 4 >= BOARD_SIZE || l - 4 < 0){
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
										}
										else{
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
										}
									}
									else if(k + 3 < BOARD_SIZE  && l - 3 >= 0 && temp[k + 3][l - 3] == oChessman || k + 3 >= BOARD_SIZE || l - 3 < 0){
										this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
										printf("xujiwei...isleep3, 8, x = %d, y = %d\n",k,l);
									}
									else{
										this->analysis_ilives(info,ILIVE3,index,rotate + 1);
									}
								}

							 }
							 else if(k - 1 >= 0 && l + 1 < BOARD_SIZE && temp[k - 1][l + 1] == oChessman || k - 1 < 0 || l + 1 >= BOARD_SIZE){
								 if(k + 3 < BOARD_SIZE && l - 3 >= 0 &&temp[k + 3][l - 3] == chessman){
									 if(k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == chessman){
										 if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman){
											 this->analysis_ilives(info,IHAS_WON,index,rotate + 1);
											 //if(rotate == 2) printf("xujiwei...6, x = %d, y = %d\n",i,j);
										 }
										 else if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || (k + 5 >= BOARD_SIZE) || l - 5 < 0){
											 this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
										 }
										 else{
											 this->analysis_ilives(info,ILIVE4,index,rotate + 1);
											 printf("xujiwei...live4,7, x = %d, y = %d\n",k,l);
										 }
									 }
									 else if((k + 4 < BOARD_SIZE  && l - 4 >= 0  && temp[k + 4][l - 4] == oChessman) || (k + 4 >= BOARD_SIZE) || l - 4 < 0){
									 }
									 else{
										 this->analysis_ilives(info,ILIVE3,index,rotate + 1);
									 }
								 }
								 else if((k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == oChessman) || (k + 3 >= BOARD_SIZE) || l - 3 < 0){
			 
								 }
								 else{
								 	 if(k + 4 < BOARD_SIZE  && l - 4 >= 0 && temp[k + 4][l - 4] == chessman){
									 	if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman){
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
										}
										else if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || (k + 5 >= BOARD_SIZE) || l - 5 < 0){
											this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
											printf("xujiwei...isleep3, 9, x = %d, y = %d\n",k,l);
										}
										else{

										}

									 }
									 else if((k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == oChessman) || (k + 4 >= BOARD_SIZE) || l - 4 < 0){

									 }
									 else{
										 this->analysis_ilives(info,ILIVE2,index,rotate + 1);
									 }
								 }
							 }
							 else{
								 if(k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == chessman){
									 if(k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == chessman){
										 if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman){
											 this->analysis_ilives(info,IHAS_WON,index,rotate + 1);
											 //if(rotate == 2) printf("xujiwei...6, x = %d, y = %d\n",i,j);
										 }
										 else if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || (k + 5 >= BOARD_SIZE) || l - 5 < 0){
											 this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
										 }
										 else{
											 this->analysis_ilives(info,ILIVE4,index,rotate + 1);
											 printf("xujiwei...live4,8, x = %d, y = %d\n",k,l);
										 }
									 }
									 else if((k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == oChessman) || (k + 4 >= BOARD_SIZE) || l - 4 < 0){
											 this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
											 printf("xujiwei...isleep3, 10, x = %d, y = %d\n",k,l);
									 }
									 else{
										 this->analysis_ilives(info,ILIVE3,index,rotate + 1);
									 }
								 }
								 else if((k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == oChessman) || (k + 3 >= BOARD_SIZE) || l - 3 < 0){
								 		 //printf("xujiwei...isleep2, 1, x = %d, y = %d\n",k,l);
										 this->analysis_ilives(info,ISLEEP2,index,rotate + 1);				 
								 }
								 else{
								 	 if(k - 2 >= 0 && l + 2 < BOARD_SIZE && temp[k - 2][l + 2] == chessman){
										 this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
										 printf("xujiwei...isleep3, 11, x = %d, y = %d\n",k,l);
									 }
									 else if(k - 2 >= 0 && l + 2 < BOARD_SIZE && temp[k - 2][j] == oChessman || k - 2 < 0 || l + 2 >= BOARD_SIZE){
										 this->analysis_ilives(info,ILIVE2,index,rotate + 1);
									 }
									 else{
										 this->analysis_ilives(info,ILIVE2,index,rotate + 1);
									 }
								 }
							 }
						 }
					}break;
					
					case 1:{
						if(k >= 0 && l < BOARD_SIZE && temp[k][l] == oChessman){
							if(k + 2 < BOARD_SIZE && l - 2 >= 0 && temp[k + 2][l - 2] == chessman){
								if(k + 3 < BOARD_SIZE  && l - 3 >= 0 && temp[k + 3][l - 3] == chessman){
									if(k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == chessman){
										if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman){
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
										}
										else if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || (k + 5 >= BOARD_SIZE) || l - 5  < 0){
											this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
											printf("xujiwei...isleep3, 13, x = %d, y = %d\n",k,l);
										}
										else{
											//this->analysis_ilives(info,ILIVE3,index,rotate);
											//printf("xujiwei ----> ilive 3, 3\n");
										}
									}
									else if((k + 4 < BOARD_SIZE  && l - 4 >= 0 && temp[k + 4][l - 4] == oChessman) || (k + 4 >= BOARD_SIZE) || l - 4 < 0){

									}
									else{
										this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
									}
								}
								else if((k + 3 < BOARD_SIZE  && l - 3 >= 0 && temp[k + 3][l - 3] == oChessman) || (k + 3 >= BOARD_SIZE) || l - 3 < 0){

								}
								else{
									this->analysis_ilives(info,ILIVE2,index,rotate + 1);
								}
							}
							else if((k + 2 < BOARD_SIZE  && l - 2 >= 0 && temp[k + 2][l - 2] == oChessman) || (k + 2 >= BOARD_SIZE) || l - 2 < 0){

							}
							else{
							   if(k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == chessman){
							   		if(k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == chessman){
										if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman){
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
										}
										else if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || (k + 5 >= BOARD_SIZE) || l - 5 < 0){

										}
										else{
											this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
										}
									}
									else if((k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == oChessman) || (k + 4 >= BOARD_SIZE) || l - 4 < 0){

									}
									else{
										if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman){
											
										}
										else if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || (k + 5 >= BOARD_SIZE) || l - 5 < 0){

										}
										else{
											this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
										}
									}
							   }
							   else if((k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == oChessman) || (k + 3 >= BOARD_SIZE) || l - 3 < 0){

							   }
							   else{
								   	if(k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == chessman){
										if(k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == chessman){
											if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman){
												this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
											}
											else if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || (k + 5 >= BOARD_SIZE) || l - 5 < 0){

											}
											else{
												this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
											}
										}
										else if((k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == oChessman) || (k + 4 >= BOARD_SIZE) || l - 4 < 0){

										}
										else{
											if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman){
												this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
											}
											else if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || (k + 5 >= BOARD_SIZE) || l - 5 < 0){

											}
											else{
												this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
											}
										}
									}
									else if((k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == oChessman) || (k + 3 >= BOARD_SIZE) || l - 3 < 0){

									}
									else{
										if(k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == chessman){
											if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman){
												this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
											}
											else if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || (k + 5 >= BOARD_SIZE) || l - 5 < 0){
												
											}
											else{
												printf("xujiwei...isleep2, 3, x = %d, y = %d\n",k,l);
												this->analysis_ilives(info,ISLEEP2,index,rotate + 1);
											}
										}
										else if((k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == oChessman) || (k + 4 >= BOARD_SIZE) || l - 4 < 0){

										}
										else{

										}
									}
							   }
							}
							
						}
						else{
							if(k - 1 >= 0 && l + 1 < BOARD_SIZE && temp[k - 1][l + 1] == chessman){
								if(k - 2 >= 0 && l + 2 < BOARD_SIZE && temp[k - 2][l + 2] == chessman){
									if(k - 3 >= 0  && l + 3 < BOARD_SIZE && temp[k - 3][l + 3] == chessman){
										this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
									}
									else if(k - 3 >= 0  && l + 3 < BOARD_SIZE && temp[k - 3][l + 3] == oChessman || k - 3 < 0 || l + 3 >= BOARD_SIZE){
										if(k + 2 < BOARD_SIZE && l - 2 >= 0 && temp[k + 2][l - 2] == chessman){
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
										}
										else if((k + 2 < BOARD_SIZE && l - 2 >= 0 && temp[k + 2][l - 2] == oChessman) || (k + 2 >= BOARD_SIZE) || l - 2 < 0){

										}
										else{
											this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
										}
									}
									else{
										if(k + 2 < BOARD_SIZE  && l - 2 >= 0 && temp[k + 2][l - 2] == chessman){
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
										}
										else if((k + 2 < BOARD_SIZE  && l - 2 >= 0 && temp[k + 2][l - 2] == oChessman) || (k + 2 >= BOARD_SIZE) || l - 2 < 0){
											this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
										}
										else{
											this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
										}
									}
								}
								else if(k - 2 >= 0 && l + 2 < BOARD_SIZE && temp[k - 2][l + 2] == oChessman || k - 2 < 0 || l + 2 >= BOARD_SIZE){
									if(k + 2 < BOARD_SIZE && l - 2 >= 0 && temp[k + 2][l - 2] == chessman){
										if(k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == chessman){
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
										}
										else if((k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == oChessman) || (k + 3 >= BOARD_SIZE) || l - 3 < 0){

										}
										else{
											this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
										}
										
									}
									else if((k + 2 < BOARD_SIZE && l - 2 >= 0 && temp[k + 2][l - 2] == oChessman) || (k + 2 >= BOARD_SIZE) || l - 2 < 0){
									
									}
									else{
										if(k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == chessman){
											this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
										}
										else if((k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == oChessman) || (k + 3 >= BOARD_SIZE) || l - 3 < 0){

										}
										else{
											printf("xujiwei...isleep2, 4, x = %d, y = %d\n",k,l);
											this->analysis_ilives(info,ISLEEP2,index,rotate + 1);
										}
									}
								}
								else{
									if(k + 2 < BOARD_SIZE && l - 2 >= 0 && temp[k + 2][l - 2] == chessman){
										if(k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == chessman){
											this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
										}
										else if((k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == oChessman) || (k + 3 >= BOARD_SIZE) || l - 3 < 0){
											this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
										}
										else{
											this->analysis_ilives(info,ILIVE3,index,rotate + 1);
										}

									}
									else if((k + 2 < BOARD_SIZE && l - 2 >= 0 && temp[k + 2][l - 2] == oChessman) || (k + 2 >= BOARD_SIZE) || l - 2 < 0){
										this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
									}
									else{
										this->analysis_ilives(info,ILIVE2,index,rotate + 1);
									}
								}
							}
							else if(k - 1 >= 0 && l + 1 < BOARD_SIZE && temp[k - 1][l + 1] == oChessman || k - 1 < 0 || l + 1 >= BOARD_SIZE){
								if(k + 2 < BOARD_SIZE && l - 2 >= 0 && temp[k + 2][l - 2] == chessman){
									if(k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == chessman){
										if(k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == chessman){
											if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman){
												this->analysis_ilives(info,IHAS_WON,index,rotate + 1);
											}
											else if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || (k + 5 >= BOARD_SIZE) || l - 5 < 0){
												this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
											}
											else{
												this->analysis_ilives(info,ILIVE4,index,rotate + 1);
											}
										}
										else if((k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == oChessman) || (k + 4 >= BOARD_SIZE) || l - 4 < 0){

										}
										else{
											this->analysis_ilives(info,ILIVE3,index,rotate + 1);
										}
									}
									else if((k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == oChessman) || (k + 3 >= BOARD_SIZE) || l - 3 < 0){
										if(k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == chessman || l - 4 < 0){
											if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman){
												this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
											}
											else if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || (k + 5 >= BOARD_SIZE) || l - 5 < 0){
												this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
											}
											else{
												this->analysis_ilives(info,ILIVE3,index,rotate + 1);
											}
										}
										else if((k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == oChessman) || (k + 4 >= BOARD_SIZE) || l - 4 < 0){

										}
										else{
											this->analysis_ilives(info,ILIVE3,index,rotate + 1);
										}
									}
									else{
										if(k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == chessman){
											if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman){
												this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
											}
											else if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || (k + 5 >= BOARD_SIZE) || l - 5 < 0){
												this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
											}
											else{
												this->analysis_ilives(info,ILIVE3,index,rotate + 1);
											}
										}
										else if((k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == oChessman) || (k + 4 >= BOARD_SIZE) || l - 4 < 0){

										}
										else{
											this->analysis_ilives(info,ILIVE2,index,rotate + 1);
										}
									}
								}
								else if((k + 2 < BOARD_SIZE && temp[k + 2][j] == oChessman) || (k + 2 >= BOARD_SIZE)){

								}
								else{
									if(k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == chessman){
										if(k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == chessman){
											if(k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == chessman){
												this->analysis_ilives(info,ILIVE4HEAP,index,rotate + 1);
											}
											else if((k + 5 < BOARD_SIZE && l - 5 >= 0 && temp[k + 5][l - 5] == oChessman) || (k + 5 >= BOARD_SIZE) || l - 5 < 0){
												this->analysis_ilives(info,ISLEEP3,index,rotate + 1);
											}
											else{
												this->analysis_ilives(info,ILIVE3,index,rotate + 1);
											}
										}
										else if((k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == oChessman) || (k + 4 >= BOARD_SIZE) || l - 4 < 0){
											
										}
										else{
											this->analysis_ilives(info,ILIVE2,index,rotate + 1);
										}
									}
									else if((k + 3 < BOARD_SIZE && l - 3 >= 0 && temp[k + 3][l - 3] == oChessman) || (k + 3 >= BOARD_SIZE) || l - 3 < 0){
									
									}
									else{//need more analysis down 2018.4.16
										if(k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][l - 4] == chessman){
											printf("xujiwei...isleep2, 6, x = %d, y = %d\n",i,j);
											this->analysis_ilives(info,ISLEEP2,index,rotate + 1);
										}
										else if((k + 4 < BOARD_SIZE && l - 4 >= 0 && temp[k + 4][j] == oChessman) || (k + 4 >= BOARD_SIZE) || l - 4 < 0){

										}
										else{

										}
									}
								}
							}
							else{

							}
						}
					}break;
					default:break;
				 }
			 }
			 else{ continue;}
		 }
	}

}

Chessmen_info* JudgeWin::scan_analysis_chessmen(char chessman)
{
   int chessmen_of_each_direction[BOARD_SIZE][BOARD_SIZE][8] = { 0 };
   Chessmen_info* info = new Chessmen_info();

   this->rotate(ROTATE0);
   this->analysis_for_each_direction(chessman,this->each_direction_board_for_judge,info,ROTATE0);
   this->rotate(ROTATE90);
   this->analysis_for_each_direction(chessman,this->each_direction_board_for_judge,info,ROTATE90);
   this->rotate(ROTATE180);
   this->analysis_for_each_direction(chessman,this->each_direction_board_for_judge,info,ROTATE180);
   this->rotate(ROTATE270);
   this->analysis_for_each_direction(chessman,this->each_direction_board_for_judge,info,ROTATE270);
   
return info;
}

bool JudgeWin::won_the_game(char chessman) const
{
   //judge analysis

return true;
}

char JudgeWin::whois_winner() const
{
   if(be_won) return this->winner;
   return '+';
}
