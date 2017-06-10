#include "storechessmanual.h"
#include <iostream>

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

int StoreChessManual::open_file(const std::string& file_name,const enum in_out i_o)
{
   if(i_o == StoreChessManual::in){
      ifile.open(file_name,std::ios_base::in|std::ios_base::binary);
      if(!ifile.is_open()){
         DEBUG_LOG("can not open the file!");
         return -1;
      }
   }
   else if(i_o == StoreChessManual::out){
      ofile.open(file_name,std::ios_base::out|std::ios_base::app);
      if(!ofile.is_open()){
        DEBUG_LOG("can not open the file!");
        return -1;
      }
   }
   else throw "open file error!";
}

int StoreChessManual::read_file(const std::string& file_name,const enum in_out i_o)
{

}

int StoreChessManual::write_file(const std::string& file_name,const enum in_out i_o)
{

}

void StoreChessManual::close_file(const enum in_out i_o)
{
   if( i_o == StoreChessManual::in){
      ifile.close();
   }
   else if(i_o == StoreChessManual::out){
      ofile.close();
   }
   else throw "bad close file";
}

int StoreChessManual::ops_file(const std::string& file_name)
{
 
}

StoreChessManual* StoreChessManual::s = NULL;
