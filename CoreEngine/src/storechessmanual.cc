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

int StoreChessManual::open_file(const std::string& file_name)
{

}

int StoreChessManual::read_file(const std::string& file_name)
{

}

void StoreChessManual::close_file(const enum in_out)
{

}

int StoreChessManual::ops_file(const std::string& file_name)
{
 
}

StoreChessManual* StoreChessManual::s = NULL;
