#include "myclipboardlogger.hpp"

void MyClipboardLogger::setTimer(QTimer *to, int msec)
{
    if(nullptr != this->timer)
    {
        delete  this->timer;
    }
    this->timer = to;

    if (msec > 0)
    {
        this->timer->setInterval(msec);
    }
    else
    {
        this->timer->setInterval(1000);
    }
}

QTimer *MyClipboardLogger::getTimer()
{
    return this->timer;
}

void MyClipboardLogger::setLastEntry(QString entry)
{
    this->lastEntry = entry;
}

QString MyClipboardLogger::getLastEntry()
{
    return this->lastEntry;
}

MyClipboardLogger::MyClipboardLogger(QObject *parent) : QObject(parent)
{
    this->setLastEntry("");
    this->setTimer(new QTimer(this));
}