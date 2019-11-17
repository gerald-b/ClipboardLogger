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

MyClipboardLogger::MyClipboardLogger(QObject *parent) : QObject(parent)
{

}
