#ifdef LOG_H
#define LOG_H
#include<cstdio>
#define LOG_BUG(x,args...) printf(x,##args)
#endif//log.h
