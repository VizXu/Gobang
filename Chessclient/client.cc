#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<cstring>
#include<cstdlib>
#include<memory.h>
#include<getopt.h>

#define BUF_SIZE 1024
#define PORT 80

extern int gobang_init(int sockfd, int argc,char* args[]);
extern int gobang_get(int sockfd, int argc,char* args[]);
extern int gobang_set(int sockfd, int argc,char* args[]);

void usage()
{
  std::cout<<"usage:    "<<std::endl;
  std::cout<<"ChessClient init --host(-h) [127.0.0.1] <--port(-p) 80> --size(-s) [10]"<<std::endl;
  std::cout<<"ChessClient set  --host(-h) [127.0.0.1] <--port(-p) 80> --xpos(-x) [5] --ypos(-y) [4]"<<std::endl;
  std::cout<<"ChessClient get  --host(-h) [127.0.0.1] <--port(-p) 80>"<<std::endl;
}

int gobang_help(int sockfd, int argc,char* args[])
{
   (void)sockfd;
   (void)argc;
   (void)args;
   usage();
return 0;
}

int gobang_version(int sockfd, int argc,char* args[])
{
   (void)sockfd;
   (void)argc;
   (void)args;
   std::cout<<"version:0.0.1"<<std::endl;
return 0;
}

struct command {
	const char *name;
	int (*fn)(int sockfd, int argc, char *argv[]);
	const char *help;
	void (*usage)(void);
};

static const struct command cmds[] = {
	{
		"help",
		gobang_help,
		NULL,
		NULL
	},
	{
		"version",
		gobang_version,
		NULL,
		NULL
	},
	{
		"init",
		gobang_init,
		"init gobang game",
		//gobang_init_usage
		NULL
	},
	{
		"set",
		gobang_set,
		"set the position on the chessboard",
		//gobang_set_usage
		NULL
	},
	{
		"get",
		gobang_get,
		"set the position on the chessboard",
		//obang_get_usage
		NULL
	},
	{ NULL, NULL, NULL, NULL }
};

static int run_command(const struct command *cmd, int fd, int argc, char *argv[])
{
	return cmd->fn(fd, argc, argv);
}

void set_server(struct sockaddr_in& server,int port,char* ip)
{
	server.sin_family = AF_INET;
	server.sin_port   = port;
	server.sin_addr.s_addr = inet_addr(ip);
}

int init_sock(struct sockaddr_in& server,int port,char* ip)
{

	int sockfd;

	set_server(server,port,ip);

	sockfd = socket(AF_INET,SOCK_STREAM,0);

	if(sockfd < 0){
	   std::cerr<<"create sockfd error!"<<std::endl;
	   return -1;
	}

	if(connect(sockfd,(sockaddr*)&server,sizeof(server)) < 0){
	   std::cerr<<"connect failed!"<<std::endl;
	   return -1;
	}
return sockfd;
}

int main(int argc, char* args[])
{

	static const struct option opts[] = {
		{ "host",     required_argument, NULL, 'h' },
		{ "size",     required_argument, NULL, 's' },
		{ "xpos",     required_argument, NULL, 'x' },
		{ "ypos",     required_argument, NULL, 'y' },
		{ "port",     optional_argument, NULL, 'p' },
		{ NULL,       0,                 NULL,  0  }
	};

	int sockfd;
	int rc;
	char* ip = NULL;
	int port = 0;
	char results = 0;
	char* cmd;
	sockaddr_in server;
	memset(&server, 0, sizeof(server));
	
	for(;;){
	   results = getopt_long(argc,args,"h:p::s:x:y:",opts,NULL);	
	   if(-1 == results){
		break;	
	   }

	   switch(results){
		case 'h':  ip         = optarg;                   break;
		case 'p':  port       = optarg?atoi(optarg):PORT; break;
		case '?': goto usage;
		default: break;
	   }
	}
	
	if(NULL == ip) goto usage;

	if(0 == port) port = PORT;

	sockfd = init_sock(server,port,ip);

	cmd = args[optind];

	if (cmd) {
		for (int i = 0; cmds[i].name != NULL; i++)
			if (!strcmp(cmds[i].name, cmd)) {
				optind = 0;
				rc = run_command(&cmds[i], sockfd, argc, args);
				goto success;
		}
	}
	
usage:	
   usage();
success:
   return rc;
}
