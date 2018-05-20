#ifndef CHESSBOARDPATTERN
#define CHESSBOARDPATTERN

#include <exception>
#include <stdexcept>
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
    int gameStep;
    int gamelevel;
    struct game_status currentGameStatus;
    Chessboard chessboard;
    Computer* computer;
    Human* human;
    Testwinner test_winner;
    Balance_Territory test_balance;
public:
    static ChessboardPattern* getPattern();
    struct game_status getCurrentGameStatus() const;
private:
    ChessboardPattern(const char*,const char*);
    void setCurrentGameStatus(struct game_status&);
    void setLevel(int);
    int getLevel() const;
    struct game_status&& gameRunningLevel(const struct client_info& info,int level); 
public:
    ~ChessboardPattern();
public:
    int getGameStep() const;
    void initGame(int,int);
    struct game_status gameRunning(const struct client_info& info); 
    const char* getComputerName() const;
    const char* getHumanName() const;
    const Chessboard& getChessboard() const;
};
#endif//chessboardpattern.h
