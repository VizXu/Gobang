#ifndef GAMEINFO_
#define GAMEINFO_

#define BUF_SIZE 1024
#define BOARD_BUF 2048

#define CMD_BUF 64

#define STATUS_OK      0
#define COMPUTER_WIN   1
#define CLIENT_WIN     2
#define BALANCE	       3
#define INVALID_POS    -1
#define INLEGAL_POS    -2

struct game_status{
   int status;
};

struct client_info{
   char cmd[CMD_BUF];
   struct _info{
	int level;
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

#endif //gameinfo.h
