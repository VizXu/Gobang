#ifndef _DEBUG_H
#define _DEBUG_H

#include<cstdio>
#define DEBUG
#define DEBUG_LOG(x,arg...) do{ \
                      printf(x,##arg);\
		   }while(0)
#endif // debug.h
