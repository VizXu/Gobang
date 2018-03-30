#include "gameinfo.h"
#include <iostream>

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
    return this->level;
}

void gameinfo::setLevel(int _level)
{
    this->level = _level;
}

int gameinfo::getStatus() const
{
    return this->status;
}

void gameinfo::setStatus(int _status)
{
    this->status = _status;
}

int gameinfo::getStep() const
{
    return this->steps;
}

int ChessboardInfo::getStep() const
{
    return this->info.getStep();
}

int ChessboardInfo::getSize() const
{
    return this->info.getSize();
}

char* ChessboardInfo::getChessboard() const
{
    return this->chessboard ? this->chessboard:NULL;
}

bool ChessboardInfo::copyInfoFromClient(char *src, int dataSize)
{
    const int size = this->getSize();
    if(!src || size != dataSize) return false;

    this->chessboard = new char[size*size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            this->chessboard[i*size + j] = src[i*size + j];
        }
    }
return true;
}
