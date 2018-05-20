#include "chessboardpattern.h"

ChessboardPattern::ChessboardPattern(const char* cName = "computer",const char* hName = "human"):
computerName(cName),humanName(hName)
{
    computer = new Computer(this->computerName);
    human    = new Human(this->humanName);
    this->gameStep = 0;
    this->gamelevel = 1;
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

void ChessboardPattern::initGame(int size,int level) 
{
    this->gameStep = 0;
    this->setLevel(level);
    this->chessboard.init(size);
    this->human->initMoveState();
    this->computer->initMoveState();
}

int ChessboardPattern::getGameStep() const
{
    return this->gameStep;
}

void ChessboardPattern::setLevel(int level)
{
   if(level > 3 || level <= 0) throw std::invalid_argument(std::string("level should be 0-3"));
   this->gamelevel = level;
}

int ChessboardPattern::getLevel() const
{
   return this->gamelevel;
}

void ChessboardPattern::setCurrentGameStatus(struct game_status& status)
{
   this->currentGameStatus = status;
}

struct game_status ChessboardPattern::getCurrentGameStatus() const
{
  return this->currentGameStatus;
}

struct game_status ChessboardPattern::gameRunning(const struct client_info& info)
{
   struct game_status status;
   switch(this->getLevel()){
      case 1: status = this->gameRunningLevel(info,1); break;
      case 2: status = this->gameRunningLevel(info,2); break;
      case 3: status = this->gameRunningLevel(info,3); break;
      default: status = this->gameRunningLevel(info,1); break;
   } 
return status;
}

struct game_status&& ChessboardPattern::gameRunningLevel(const struct client_info& info,int level)
{
    int xpos = info.info.xpos;
    int ypos = info.info.ypos;
    struct game_status gameStatus;
    board_position tmp_position;
	this->computer->select_level(level);

    if(this->test_balance(chessboard)){
	 gameStatus.status = BALANCE;
         return std::move(gameStatus);
    }

    this->human->change_state();//start   
    if(!this->human->make_a_step_via_net(chessboard,xpos,ypos)){
		gameStatus.status = INVALID_POS;
        return std::move(gameStatus);
    }
    else{
		gameStatus.status = STATUS_OK;
    }

    tmp_position = this->human->get_present_position();
    if(this->test_winner(chessboard,tmp_position,'&')){
	 	gameStatus.status = CLIENT_WIN;
        return std::move(gameStatus);
    }
    this->human->change_state(); //stop

    this->computer->change_state();//start
    this->computer->make_a_step(chessboard);

    tmp_position = this->computer->get_present_position();
    if(this->test_winner(chessboard,tmp_position,'@')){
	 	gameStatus.status = COMPUTER_WIN;
        return std::move(gameStatus);
    }
    this->computer->change_state(); //stop
    this->gameStep += 1;

    this->setCurrentGameStatus(gameStatus);

return std::move(gameStatus);
}

const Chessboard& ChessboardPattern::getChessboard() const
{
	return this->chessboard;
}

ChessboardPattern* ChessboardPattern::pattern = NULL;
