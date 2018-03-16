#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<unistd.h>
#include<cstring>
#include<iostream>

#define MAX_SOCK 20

extern int handle_process(int);

int main(int argc,char* args[])
{
    int server_fd = 0;
    int listen_fd = 0;
    int client_fd = 0; 
    struct sockaddr_in server_input;
    memset(&server_input,0,sizeof(struct sockaddr_in));
    server_input.sin_family = AF_INET;
    server_input.sin_addr.s_addr = htonl(INADDR_ANY);
    server_input.sin_port = 80;

    if(daemon(0,0) < 0){
	std::cerr<<"daemon error,exit!"<<std::endl;
	return -1;
    }

    server_fd = socket(AF_INET,SOCK_STREAM,0);
    if(server_fd < 0){
	std::cerr<<"create socket error!"<<std::endl;
	return -1;
    }

    if(-1 == bind(server_fd,(struct sockaddr*)&server_input,sizeof(struct sockaddr))){
	std::cerr<<"bind socket error!"<<std::endl;
	return -1;
    }

    listen_fd = listen(server_fd,MAX_SOCK);
    if(-1 == listen_fd){
	std::cerr<<"listen socket error!"<<std::endl;
	return -1;
    }

    while(true){
	if((client_fd = accept(server_fd,(struct sockaddr*)NULL,NULL)) == -1){
		std::cerr<<"accept error!"<<std::endl;
		continue;
	}
	if(!fork()){//child process
		handle_process(client_fd);
		close(client_fd);	
	}
	close(client_fd);
	break;
    }
return 0;
}

