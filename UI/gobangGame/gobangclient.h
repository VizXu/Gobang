#ifndef GOBANGCLIENT_H
#define GOBANGCLIENT_H

#include <QProcess>
#include <QStringList>
#include <QMessageBox>
#include "debug.h"
#include "gameinfo.h"

class gobangClient
{
private:
    QProcess* clientProcess;
    ChessboardInfo statusinfo;
    QStringList chessboard;
    QStringList boardInfo;
    debug bug_log;
public:
    gobangClient();
    ~gobangClient();
public:
    QStringList getChessboardInfo() const;
    void handleRecv(const QString& cmd);
    void clientGet(const char* _ip);
public slots:
    void clientInit(const char* _ip,int _level,int _size);
    void clientSet(const char* _ip,gameinfo _info);
signals:
    void sendChessboard(ChessboardInfo info);
};

#endif // GOBANGCLIENT_H
