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
        this->timer->setInterval(TIMER_CBL_INTERVAL);
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

void MyClipboardLogger::setSettings(QSettings *settings)
{
    if(nullptr != this->mySettings)
    {
        delete  this->mySettings;
    }
    this->mySettings = settings;
}

QSettings *MyClipboardLogger::getSettings()
{
    return this->mySettings;
}

MyClipboardLogger::MyClipboardLogger(QObject *parent) : QObject(parent)
{
    this->setLastEntry("");
    this->setTimer(new QTimer(this));
}

void MyClipboardLogger::startTimer()
{
    this->timer->start();
}

void MyClipboardLogger::stopTimer()
{
    this->timer->stop();
}
