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

QStringList gobangClient::getChessboardInfo(bool isOriginal)
{
    if(isOriginal){
        this->initBoardInfo();
        return this->originalInfo;
    }
    return this->boardInfo;
}

void gobangClient::initBoardInfo()
{
    QString eachLine;
    QStringList tmp;
    this->originalInfo.swap(tmp);
    for(int i = 0; i < this->boardInfo.size(); i++){
        eachLine = this->boardInfo.at(i);
        eachLine.replace(QChar('&'),QChar('+'));
        this->originalInfo.push_back(eachLine);
    }
}

void gobangClient::handleRecv(const QString& cmd)
{
    this->clientProcess->start(cmd);
    this->clientProcess->waitForFinished(3000);
    QString boardinfo = this->clientProcess->readAllStandardOutput();
    QStringList info = boardinfo.split(QRegExp("[\n\r]"));
    QString action = cmd.split(" ").at(1);
    QList<QString> tmp;
    this->boardInfo.swap(tmp);

    if(QString("send error!") == info.at(0)){
       QMessageBox::information(NULL, "error!", "send error! the core server is down!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
       return;
    }

    if(action == QString("init")){
        QString eachLine;
        for(int i = 0; i < this->statusinfo.getSize(); i++){
            eachLine = info.at(i + 1);
            this->boardInfo.push_back(eachLine);
        }
        QMessageBox::information(NULL, "Init the Game!", "Game Start!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return;
    }
    else if(action == QString("get")){
    }
    else if(action == QString("set")){
        QString gameStatus = info.at(2);

        QString winnerStatus = gameStatus.split(',').at(1).split('=').at(1);
        //qDebug()<<"winnerStatus = "<<winnerStatus.toStdString().c_str();

        if(winnerStatus.contains(QString("2"))){
            QMessageBox::information(NULL, "Human Win!", "Congratulations! You won the game!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            return;
        }
        else if(winnerStatus.contains(QString("1"))){
            QMessageBox::information(NULL, "Computer Win!", "Sorry! You failed!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            return;
        }

        QString eachLine;
        for(int i = 0; i < this->statusinfo.getSize(); i++){
            eachLine = info.at(i + 3);
            this->boardInfo.push_back(eachLine);
        }
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
    //bug_log.LOG(cmd);
    this->handleRecv(cmd);
}

void gobangClient::clientGet(const char* _ip)
{
    QString cmd("ChessClient get");
    cmd += " --host ";
    cmd += _ip;
    //bug_log.LOG(cmd);
    this->handleRecv(cmd);
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
    this->handleRecv(cmd);
}
