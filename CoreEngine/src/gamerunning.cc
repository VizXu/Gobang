#include<iostream>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>

#include "chessboardpattern.h"
#include "chessboard.h"

#define BUF_SIZE 1024

int sendInfo(int sockfd)
{

}

int recvInfo(int sockfd,int xpos,int ypos,char player,int steps)
{

}

int handle_process(int sockfd)
{
	int b_size = 0;
	char buf[BUF_SIZE] = { 0 };
	if(!sockfd) return -1;
	
	if((b_size = recv(sockfd,buf,BUF_SIZE,0)) == -1){
		std::cerr<<"recv error!"<<std::endl;
		return -1;
	}

return 0;
}
