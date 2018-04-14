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
      ofile.open(file_name,std::ios_base::out|std::ios_base::binary|std::ios_base::app);
      if(!ofile.is_open()){
        DEBUG_LOG("can not open the file!");
        return -1;
      }
   }
   else throw "open file error!";
}

int StoreChessManual::read_file(char* buf)
{

}

int StoreChessManual::write_file(char* buf)
{
  // ofile.write();
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

int StoreChessManual::store_chessboard_info_to_file(const std::string& file_name,chessboard_info& info)
{
   if(-1 == this->open_file(file_name,StoreChessManual::out)) return -1;
   
    
   this->close_file(StoreChessManual::out);
return 0;  
}

int StoreChessManual::read_chessboard_info_from_file(const std::string& file_name,chessboard_info& info)
{
  if(-1 == this->open_file(file_name,StoreChessManual::in)) return -1;

  this->close_file(StoreChessManual::in);
return 0;
}

StoreChessManual* StoreChessManual::s = NULL;
