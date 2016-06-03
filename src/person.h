#ifndef _PERSON_
#define _PERSON_
#include<string>
#include"player.h"
using std::string;
class Person:public
{
private:
  string name;
public:
  Person(){}
  Person(string n="Zhangsan"):Player(n){}
  ~Person(){}
public:
  
};
#endif//person.h
