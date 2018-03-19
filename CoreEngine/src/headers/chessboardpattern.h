#ifndef CHESSBOARDPATTERN
#define CHESSBOARDPATTERN

#include "computer.h"
#include "chessboard.h"
#include "human.h"
#include "testwinner.h"

class ChessboardPattern
{
public:
    static ChessboardPattern* pattern;
private:
    const char* computerName;
    const char* humanName;
    Chessboard chessboard;
    Computer* computer;
    Human* human;
    Testwinner test_winner;
    Balance_Territory test_balance;
public:
    ChessboardPattern* getPattern(const char*,const char*);
private:
    ChessboardPattern(const char*,const char*);
public:
    ~ChessboardPattern();
public:
    void gameRunning(); 
    const char* getComputerName() const;
    const char* getHumanName() const;
};
#endif//chessboardpattern.h
