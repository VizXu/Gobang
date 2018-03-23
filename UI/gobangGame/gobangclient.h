#ifndef GOBANGCLIENT_H
#define GOBANGCLIENT_H

#include <QProcess>
#include "debug.h"
#include "gameinfo.h"

class gobangClient
{
private:
    QProcess* clientProcess;
    gameinfo info;
    debug bug_log;
public:
    gobangClient();
    ~gobangClient();
public slots:
    void clinetInit(const char* _ip,int _level,int _size);
    gameinfo clinetGet(const char* _ip);
    void clinetSet(const char* _ip,gameinfo _info);
};

#endif // GOBANGCLIENT_H
