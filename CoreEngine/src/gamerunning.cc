#include<iostream>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<cstdlib>
#include<cstring>

#include "chessboardpattern.h"
#include "chessboard.h"
#include "gameinfo.h"

/*
#define BUF_SIZE 1024
#define BOARD_BUF 2048

#define CMD_BUF 64

struct client_info{
   char cmd[CMD_BUF];
   struct _info{
	int size;
	int xpos;
	int ypos;
   }info;
};

struct game_info{
   int status;
   int step;
   int size;
   char chessinfo[BOARD_BUF];
};
*/

void transfer(const Chessboard& board, struct game_info& info)
{
   const int size = BOARD_SIZE;
   int k = 0;
   for(int i = 0; i < BOARD_SIZE; i++){
      for(int j = 0; j < BOARD_SIZE; j++){
	 info.chessinfo[k++] = board.get_chess(i,j);
      }
   }
}

int sendGameInfo(int sockfd, struct game_info& game)
{
    if(-1 == send(sockfd,(void*)&game,sizeof(struct game_info),0)){
	return -1;
    }
return 0;
}

int recvInfo(int sockfd,int xpos,int ypos,char player,int steps)
{

}

int handle_init(struct client_info& info, struct game_info& game)
{
	ChessboardPattern* pattern = ChessboardPattern::getPattern();
	pattern->initGame(BOARD_SIZE);
	Chessboard board = pattern->getChessboard();
	game.status = 0;
	game.step = 1;
	game.size = info.info.size;	
	transfer(board,game);

return 0;
}

int handle_set(struct client_info& info, struct game_info& game)
{
	struct game_status gameStatus;
	ChessboardPattern* pattern = ChessboardPattern::getPattern();
	gameStatus = pattern->gameRunning(info);
	Chessboard board = pattern->getChessboard();
        game.status = 0;
        game.step = info.info.xpos;
        game.size = BOARD_SIZE;//info.info.size;
        transfer(board,game);
return 0;
}

int handle_get(int sockfd, struct client_info& info, struct game_info& game)
{
	ChessboardPattern* pattern = ChessboardPattern::getPattern();
return 0;
}

int handle_process(int sockfd)
{
	int b_size = 0;
	int rc = 0;
	struct client_info c_info;
	struct game_info game;
	memset(&c_info, 0, sizeof(struct client_info));
	memset(&game, 0, sizeof(struct game_info));

	char cmd[CMD_BUF] = { 0 };


	if(!sockfd) return -1;
	
	if((b_size = recv(sockfd,&c_info,sizeof(struct client_info),0)) != sizeof(struct client_info)){
		std::cerr<<"recv error!"<<std::endl;
		return -1;
	}

	strncpy(cmd,c_info.cmd,CMD_BUF);

	   //rc = handle_init(sockfd, c_info,game);
	if(!strncmp(cmd,"init",sizeof("init"))){
	   rc = handle_init(c_info,game);
	}
	else if(!strncmp(cmd,"set",sizeof("set"))){
	   rc = handle_set(c_info,game);
	}
	else if(!strncmp(cmd,"get",sizeof("get"))){
	   rc = handle_get(sockfd, c_info,game);
	}
	else{
	   rc = -1;
	}
	rc = sendGameInfo(sockfd,game);

return rc;
}
