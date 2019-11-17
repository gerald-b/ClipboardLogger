#include "myclipboardlogger.hpp"

void MyClipboardLogger::setTimer(QTimer *to)
{
    if(nullptr != this->timer)
    {
        delete  this->timer;
    }
    this->timer = to;
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

}
