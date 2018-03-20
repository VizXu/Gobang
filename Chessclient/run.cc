#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <memory.h>
#include <cstdlib>

#define CMD_BUF 64
#define BOARD_BUF 2048

struct client_info
{
  char cmd[CMD_BUF];
  struct _info{
	int size;
	int xpos;
	int ypos;
  }info;
};

struct game_info
{
   int status;
   int step;
   int size;
   char chessboard[BOARD_BUF];
};

void display_chessboard(struct game_info& info)
{
   const int size = info.size;
  // std::cout<<"board_size = "<<size<<std::endl;
   for(int i = 0; i < size; i++){
      for(int j = 0; j < size; j++){
	 std::cout<<info.chessboard[i*size + j]<<" ";
      }
	std::endl(std::cout);
   }
}

int gobang_init(int sockfd, int argc, char* args[])
{

   static const struct option opts[] = {
	{"size", required_argument, NULL, 's'},
	{"host", required_argument, NULL, 'h'},
	{NULL, 0, NULL, 0}
   };
  
   int rc = 0;
   int size = 0;
   int num = 0;

   struct client_info info;
   memset(&info, 0, sizeof(info));
   struct game_info game;
   memset(&game, 0, sizeof(game));

   for(;;){
	rc = getopt_long(argc,args,"s:h:",opts,NULL);
	if(-1 == rc) break;
	switch(rc){
	   case 's':size = atoi(optarg); break;
	   case 'h':break;
	   case '?':break;
	   default:break;
	}
   }
   if(0 == size) return -1;

   strncpy(info.cmd,"init",sizeof("init"));

   //std::cout<<"info.cmd = "<<info.cmd<<std::endl;
   info.info.size = size;

   if(-1 == send(sockfd,(void*)&info,sizeof(info),0)){
	std::cout<<"send error!"<<std::endl;
	return -1;
   }

   if(sizeof(struct game_info) != recv(sockfd,(void*)&game,sizeof(struct game_info),0)){
	std::cout<<"recv error!"<<std::endl;
	return -1;
   }

	std::cout<<"init success! game running!"<<std::endl;
	//std::cout<<"recv game info,status = "<<game.status<<",size = "<<game.size<<",step = "<<game.step<<std::endl;
	display_chessboard(game);	
return 0;
}

int gobang_set(int sockfd, int argc, char* args[])
{
   static const struct option opts[] = {
        {"xpos", required_argument, NULL, 'x'},
        {"ypos", required_argument, NULL, 'y'},
        {"host", required_argument, NULL, 'h'},
        {NULL, 0, NULL, 0}
   };

   int rc = 0;
   int num = 0;
   int x = 0;
   int y = 0;

   struct client_info info;
   memset(&info, 0, sizeof(info));
   struct game_info game;
   memset(&game, 0, sizeof(game));

   for(;;){
        rc = getopt_long(argc,args,"x:y:h:",opts,NULL);
        if(-1 == rc) break;
        switch(rc){
           case 'x':x = atoi(optarg); break;
           case 'y':y = atoi(optarg); break;
           case 'h':break;
           case '?':break;
           default:break;
        }
   }

   strncpy(info.cmd,"set",sizeof("set"));
   std::cout<<"x = "<<x<<",y = "<<y<<std::endl;

   info.info.xpos = x;
   info.info.ypos = y;

   //std::cout<<"info.cmd = "<<info.cmd<<std::endl;
   //info.info.size = size;

   if(-1 == send(sockfd,(void*)&info,sizeof(info),0)){
        std::cout<<"send error!"<<std::endl;
        return -1;
   }

   if(sizeof(struct game_info) != recv(sockfd,(void*)&game,sizeof(struct game_info),0)){
        std::cout<<"recv error!"<<std::endl;
        return -1;
   }

        std::cout<<"set success!"<<std::endl;
        std::cout<<"recv game info,status = "<<game.status<<",size = "<<game.size<<",step = "<<game.step<<std::endl;
        display_chessboard(game);
return 0;
}

int gobang_get(int sockfd, int argc, char* args[])
{

}
