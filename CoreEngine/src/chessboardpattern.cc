#include "chessboardpattern.h"

ChessboardPattern::ChessboardPattern(const char* cName = "computer",const char* hName = "human"):
computerName(cName),humanName(hName)
{
    computer = new Computer(this->computerName);
    human    = new Human(this->humanName);
    this->gameStep = 0;
}

ChessboardPattern::~ChessboardPattern()
{
    delete computer;
    delete human;
}

ChessboardPattern* ChessboardPattern::getPattern()
{
    const char* c = "computer";
    const char* h = "human";
    if(NULL == pattern){
	pattern = new ChessboardPattern(c,h);
	return pattern;
    }
    else{
	return pattern;
    }
}

const char* ChessboardPattern::getComputerName() const
{
    return this->computerName;
}

const char* ChessboardPattern::getHumanName() const 
{
    return this->humanName;
}

void ChessboardPattern::initGame(int size) 
{
    this->gameStep = 0;
    this->chessboard.init(size);
}

int ChessboardPattern::getGameStep() const
{
    return this->gameStep;
}

struct game_status ChessboardPattern::gameRunning(const struct client_info& info)
{
    int xpos = info.info.xpos;
    int ypos = info.info.ypos;
    struct game_status gameStatus;
    board_position tmp_position;

    this->human->change_state();//start   
    if(!this->human->make_a_step_via_net(chessboard,xpos,ypos)){
	gameStatus.status = -1;
	return gameStatus;
    }
    tmp_position = this->human->get_present_position();
    if(this->test_balance(chessboard)){
	 gameStatus.status = 0;
         return gameStatus;
    }
    if(this->test_winner(chessboard,tmp_position,'&')){
	 gameStatus.status = 1;
         return gameStatus;
    }
    this->human->change_state(); //stop

    this->computer->change_state();//start
    this->computer->make_a_step(chessboard);

    tmp_position = this->computer->get_present_position();
    if(this->test_winner(chessboard,tmp_position,'@')){
	 gameStatus.status = 2;
         return gameStatus;
    }
    this->computer->change_state(); //stop
    this->gameStep += 1;

return gameStatus;
}

const Chessboard& ChessboardPattern::getChessboard() const
{
	return this->chessboard;
}

ChessboardPattern* ChessboardPattern::pattern = NULL;
