#include "gobangclient.h"
#include <QRegExp>
#include "debug.h"

gobangClient::gobangClient()
{
    this->clientProcess = new QProcess;
}

gobangClient::~gobangClient()
{
    delete this->clientProcess;
}

QStringList gobangClient::getChessboardInfo() const
{
    return this->boardInfo;
}

void gobangClient::handleRecv(const QString& cmd)
{
    this->clientProcess->start(cmd);
    this->clientProcess->waitForFinished(3000);
    QString boardinfo = this->clientProcess->readAllStandardOutput();
    QStringList info = boardinfo.split(QRegExp("[\n\r]"));
    QString action = cmd.split(" ").at(1);

    qDebug()<<info.size();

    if(action == QString("init")){
        QString commentLine = info.at(0);
        QString eachLine;
        for(int i = 0; i < this->statusinfo.getSize(); i++){
            eachLine = info.at(i + 1);
            qDebug()<<"line "<<i<<" = "<<eachLine.toStdString().c_str();
            this->boardInfo.push_back(eachLine);
        }
        qDebug()<<"action = "<<action.toStdString().c_str();
        qDebug()<<commentLine.toStdString().c_str();
    }
    else if(action == QString("get")){
        qDebug()<<"action = "<<action.toStdString().c_str();
    }
    else if(action == QString("set")){
        qDebug()<<"action = "<<action.toStdString().c_str();
    }
    else{
        qDebug()<<"action error!";
        return;
    }
}

void gobangClient::clientInit(const char * _ip, int _level, int _size)
{
    QString cmd("ChessClient init");
    QString level = QString::number(_level,10);
    QString size = QString::number(_size,10);
    this->statusinfo.setSize(_size);
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
