#include "myclipboardlogger.hpp"

void MyClipboardLogger::setTimer(QTimer *to, int msec)
{
    if(nullptr != this->timer)
    {
        delete  this->timer;
    }
    this->timer = to;

    this->setTimerInterval(msec);
}

QTimer *MyClipboardLogger::getTimer()
{
    return this->timer;
}

void MyClipboardLogger::setTimerInterval(int msec)
{
    if (msec > 0)
    {
        this->timer->setInterval(msec);
    }
    else
    {
        this->timer->setInterval(TIMER_CBL_INTERVAL);
    }
}

int MyClipboardLogger::getTimerInterval()
{
    return this->timer->interval();
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

void MyClipboardLogger::setOutput(IOutput *output)
{
    if(nullptr == this->myOutput)
    {
        delete this->myOutput;
    }
    this->myOutput = output;
}

IOutput *MyClipboardLogger::getOutput()
{
    return this->myOutput;
}


void MyClipboardLogger::loadAndDeploySettings()
{
    if (nullptr == this->mySettings)
    {
        QMessageBox::critical(nullptr,tr("Error"),tr("Settings Pointer not set!"),QMessageBox::Ok);
        return;
    }
    this->setTimerInterval(this->mySettings->value("global/interval", 1000).toInt());
    OutputFactory * outF = new OutputFactory(this->getSettings());
    QString otfs = this->getSettings()->value("global/outtype","file").toString();
    if (otfs.toUpper() == "FILE")
    {
        this->setOutput(outF->getOutput(OutputType::FILE));
    }
    else // non valid setting is also file output
    {
        this->setOutput(outF->getOutput(OutputType::FILE));
    }
    delete outF;
}

MyClipboardLogger::MyClipboardLogger(QObject *parent) : QObject(parent)
{
    this->setLastEntry("");
    this->setTimer(new QTimer(this));
    if (!QFile::exists("settings.ini"))
    {
        QMessageBox::critical(nullptr,
                              tr("Error"),
                              tr("The settings-file \"settings.ini\" was not found! Program will be terminated!"),
                              QMessageBox::Ok);
        exit(1);
    }
    this->setSettings(new QSettings("settings.ini",QSettings::IniFormat));

    connect(this->timer,&QTimer::timeout,this,&MyClipboardLogger::handleTimeout);
    this->loadAndDeploySettings();
}

MyClipboardLogger::~MyClipboardLogger()
{
    if (nullptr != this->timer)
    {
        delete this->timer;
    }
    if (nullptr != this->mySettings)
    {
        delete this->mySettings;
    }
}

void MyClipboardLogger::startTimer()
{
    this->timer->start();
}

void MyClipboardLogger::stopTimer()
{
    this->timer->stop();
}

void MyClipboardLogger::handleTimeout()
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    QString originalText = clipboard->text();
    if (originalText != this->getLastEntry())
    {
        this->getOutput()->writeContent(originalText);
        this->setLastEntry(originalText);
    }
}
