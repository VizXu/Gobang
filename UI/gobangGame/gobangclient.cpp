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

void gobangClient::handleRecv(const QString& cmd)
{
    this->clientProcess->start(cmd);
    this->clientProcess->waitForFinished(3000);
    QString boardinfo = this->clientProcess->readAllStandardOutput();
    qDebug()<<boardinfo.toStdString().c_str();
}

void gobangClient::clientInit(const char * _ip, int _level, int _size)
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
    this->handleRecv(cmd);
}

void gobangClient::clientGet(const char* _ip)
{
    QString cmd("ChessClient get");
    cmd += " --host ";
    cmd += _ip;
    bug_log.LOG(cmd);
}

void gobangClient::clientSet(const char* _ip,gameinfo info)
{
    QString cmd("ChessClient set");
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
