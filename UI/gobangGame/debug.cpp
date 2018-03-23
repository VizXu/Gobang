#include "debug.h"

debug::debug()
{
}

debug::~debug()
{
}

void debug::LOG(QString& s) const
{
    qDebug()<<s.toStdString().data();
}

