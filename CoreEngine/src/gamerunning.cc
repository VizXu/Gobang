#include<iostream>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<cstdlib>
#include<cstring>

#include "chessboardpattern.h"
#include "chessboard.h"

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

int handle_init(int sockfd, struct client_info& info, struct game_info& game)
{
	ChessboardPattern* pattern = ChessboardPattern::getPattern();
	Chessboard board = pattern->getChessboard();
	game.status = 0;
	game.step = 1;
	game.size = info.info.size;	

return 0;
}

int handle_set(int sockfd, struct client_info& info, struct game_info& game)
{
	ChessboardPattern* pattern = ChessboardPattern::getPattern();
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
	char cmd[CMD_BUF] = { 0 };


	if(!sockfd) return -1;
	
	if((b_size = recv(sockfd,&c_info,sizeof(struct client_info),0)) != sizeof(struct client_info)){
		std::cerr<<"recv error!"<<std::endl;
		return -1;
	}

	strncpy(cmd,c_info.cmd,CMD_BUF);

	if(!strncpy(cmd,"init",sizeof("init"))){
	   rc = handle_init(sockfd, c_info,game);
	}
	else if(!strncpy(cmd,"set",sizeof("set"))){
	   rc = handle_init(sockfd, c_info,game);
	}
	else if(!strncpy(cmd,"get",sizeof("get"))){
	   rc = handle_init(sockfd, c_info,game);
	}
	else{
	   rc = -1;
	}
	rc = sendGameInfo(sockfd,game);

return rc;
}
