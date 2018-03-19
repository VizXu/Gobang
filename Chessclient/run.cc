#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <memory.h>
#include <cstdlib>

#define CMD_BUF 64

struct client_info
{
  char cmd[CMD_BUF];
  struct _info{
	int size;
	int xpos;
	int ypos;
  }info;
};
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
   info.info.size = size;

   if(-1 == send(sockfd,(void*)&info,sizeof(info),0)){
	std::cout<<"send error!"<<std::endl;
	return -1;
   }

   if(sizeof(int) != recv(sockfd,(void*)&num,sizeof(int),0)){
	std::cout<<"recv error!"<<std::endl;
	return -1;
   }

	std::cout<<"recv, num = "<<num<<std::endl;

	std::cout<<"send success!"<<std::endl;
return 0;
}

int gobang_get(int sockfd, int argc, char* args[])
{

}

int gobang_set(int sockfd, int argc, char* args[])
{

}
