#include "storechessmanual.h"

StoreChessManual::StoreChessManual()
{

}

StoreChessManual::~StoreChessManual()
{

}

StoreChessManual* StoreChessManual::get_chess_manual()
{
  if(NULL == s){
    s = new StoreChessManual;
    return s;
  }
  else{
    return s;
  }
}

StoreChessManual* StoreChessManual::s = NULL;
