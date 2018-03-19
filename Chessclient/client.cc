#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<cstring>
#include<cstdlib>
#include<memory.h>

#define BUF_SIZE 1024
#define PORT 80

void usage()
{
  std::cout<<"usage:    "<<std::endl;
  std::cout<<"ChessClient -h 127.0.0.1 -s 10 -x <4> -y <5>"<<std::endl;
}

int main(int argc, char* args[])
{
	int sockfd;
	int err = 0;
	char* ip = NULL;
	int xpos = 0;
	int ypos = 0;
	int boardsize = 0;
	char results = 0;
	char buf[BUF_SIZE] = { 0 };
	sockaddr_in server;
	memset(&server, 0, sizeof(server));
	
	for(;;){
	   results = getopt(argc,args,"h:s:x:y:");	
	   if(-1 == results){
		break;	
	   }
		err -= 1;

	   switch(results){
		case 'h':  ip         = optarg;       break;
		case 's':  boardsize  = atoi(optarg); break;
		case 'x':  xpos       = atoi(optarg); break;
		case 'y':  ypos	      = atoi(optarg); break;
		default: break;
	   }
	}

	if(err > -4) goto usage;

	server.sin_family = AF_INET;
	server.sin_port   = PORT;
	server.sin_addr.s_addr = inet_addr(ip);

	sockfd = socket(AF_INET,SOCK_STREAM,0);

	if(sockfd < 0){
	   std::cerr<<"create sockfd error!"<<std::endl;
	   goto sock_fail;
	}

	if(connect(sockfd,(sockaddr*)&server,sizeof(server)) < 0){
	   std::cerr<<"connect failed!"<<std::endl;
	   goto connect_fail;
	}
	else{
	   if(recv(sockfd,buf,BUF_SIZE,0) == -1){
		std::cerr<<"recv error!"<<std::endl;
		goto recv_fail;
	   }
	   
	   std::cout<<"recv = "<<(int)buf[0]<<std::endl;
	}

success:
   return 0;
usage:	
   usage();
sock_fail:
connect_fail:
recv_fail:
   return 0;
}
