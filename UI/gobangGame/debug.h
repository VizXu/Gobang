#ifndef DEBUG_H
#define DEBUG_H

#include <QProcess>
#include <QString>
#include <QByteArray>
#include <iostream>
#include <QDebug>

class debug
{
private:

public:
    debug();
    ~debug();
public:
    void LOG(QString&) const;
};

#endif // DEBUG_H
