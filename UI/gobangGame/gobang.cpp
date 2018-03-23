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
    this->g_client->clinetInit(this->ip,_level,_size);
}

gameinfo gobang::getGameInfo() const
{
    gameinfo t_info;
    t_info = this->g_client->clinetGet(this->ip);
    return t_info;
}

void gobang::setPosition(int _x, int _y)
{
    gameinfo _info;
    _info.setXpos(_x);
    _info.setYpos(_y);

    this->g_client->clinetSet(this->ip,_info);
}
