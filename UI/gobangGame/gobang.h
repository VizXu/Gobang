#ifndef GOBANG_H
#define GOBANG_H

#include "gobangclient.h"

class gobang
{
private:
    gobangClient* g_client;
    char* ip;
public:
    gobang(gobangClient* client);
    ~gobang();
public:
    QStringList getChessboardInfo() const;
    void initGame(int _size,int _level);
    gameinfo getGameInfo() const;
    void setPosition(int _x, int _y);
};

#endif // GOBANG_H
