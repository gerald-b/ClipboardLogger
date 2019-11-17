#ifndef MYCLIPBOARDLOGGER_HPP
#define MYCLIPBOARDLOGGER_HPP

#include <QObject>
#include <QTimer>
#include <QString>
#include <QSettings>
#include <QFile>
#include <QMessageBox>
#include <QGuiApplication>
#include <QClipboard>
#include <QTextStream>

#define TIMER_CBL_INTERVAL 1000

class MyClipboardLogger : public QObject
{
    Q_OBJECT
private:
    QTimer *timer = nullptr;
    QString lastEntry;
    QSettings *mySettings = nullptr;
protected:
    void setTimer(QTimer *to, int msec = TIMER_CBL_INTERVAL);
    QTimer * getTimer(void);
    void setTimerInterval(int msec);
    int getTimerInterval(void);
    void setLastEntry(QString entry);
    QString getLastEntry(void);
    void setSettings(QSettings *settings);
    QSettings * getSettings(void);
    void loadAndDeploySettings(void);
public:
    explicit MyClipboardLogger(QObject *parent = nullptr);
    virtual ~MyClipboardLogger(void);
    void startTimer(void);
    void stopTimer(void);
signals:

public slots:

private slots:
    void handleTimeout(void);
};

#endif // MYCLIPBOARDLOGGER_HPP
