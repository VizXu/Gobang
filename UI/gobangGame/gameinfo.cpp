#include "gameinfo.h"

gameinfo::gameinfo()
{
}

gameinfo::~gameinfo()
{
}

int gameinfo::getXpos() const
{
    return this->xpos;
}

void gameinfo::setXpos(int x_pos)
{
    this->xpos = x_pos;
}

int gameinfo::getYpos() const
{
    return this->ypos;
}

void gameinfo::setYpos(int y_pos)
{
    this->ypos = y_pos;
}

int gameinfo::getSize() const
{
    return this->size;
}

void gameinfo::setSize(int _size)
{
    this->size = _size;
}

int gameinfo::getLevel() const
{
    return this->lelve;
}

void gameinfo::setLevel(int _level)
{
    this->lelve = _level;
}

int gameinfo::getStatus() const
{
    return this->status;
}

void gameinfo::setStatus(int _status)
{
    this->status = _status;
}

