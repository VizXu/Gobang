#ifndef CHESSBOARDPATTERN
#define CHESSBOARDPATTERN

#include "computer.h"
#include "chessboard.h"
#include "human.h"
#include "testwinner.h"
#include "gameinfo.h"

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
    static ChessboardPattern* getPattern();
private:
    ChessboardPattern(const char*,const char*);
public:
    ~ChessboardPattern();
public:
    void initGame(int);
    struct game_status gameRunning(const struct client_info& info); 
    const char* getComputerName() const;
    const char* getHumanName() const;
    const Chessboard& getChessboard() const;
};
#endif//chessboardpattern.h
