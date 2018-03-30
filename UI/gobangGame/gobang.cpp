#include "gobang.h"

gobang::gobang(gobangClient* client)
{
    this->g_client = client;
    this->ip = "127.0.0.1";
}

gobang::~gobang()
{
}

void gobang::initGame(int _size, int _level)
{
    this->g_client->clientInit(this->ip,_level,_size);
}

gameinfo gobang::getGameInfo() const
{
    gameinfo t_info;
    this->g_client->clientGet(this->ip);
    return t_info;
}

void gobang::setPosition(int _x, int _y)
{
    gameinfo _info;
    _info.setXpos(_x);
    _info.setYpos(_y);

    this->g_client->clientSet(this->ip,_info);
}
