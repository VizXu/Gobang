#include "gobangclient.h"
#include "debug.h"

gobangClient::gobangClient()
{
    this->clientProcess = new QProcess;
}

gobangClient::~gobangClient()
{
    delete this->clientProcess;
}

void gobangClient::clinetInit(const char * _ip, int _level, int _size)
{
    QString cmd("ChessClient init");
    QString level = QString::number(_level,10);
    QString size = QString::number(_size,10);
    cmd += " --host ";
    cmd += _ip;
    cmd += " --size ";
    cmd += size;
    cmd += " --level ";
    cmd += level;
    bug_log.LOG(cmd);
    //this->clientProcess->start();
}

gameinfo gobangClient::clinetGet(const char* _ip)
{
    QString cmd("ChessClient get");
    cmd += " --host ";
    cmd += _ip;
    bug_log.LOG(cmd);
return this->info;
}

void gobangClient::clinetSet(const char* _ip,gameinfo info)
{
    QString cmd("ChessClient get");
    QString xpos = QString::number(info.getXpos(),10);
    QString ypos = QString::number(info.getYpos(),10);
    cmd += " --host ";
    cmd += _ip;
    cmd += " --xpos ";
    cmd += xpos;
    cmd += " --ypos ";
    cmd += ypos;
    bug_log.LOG(cmd);
}
