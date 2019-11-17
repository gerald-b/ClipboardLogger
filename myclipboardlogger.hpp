#ifndef MYCLIPBOARDLOGGER_HPP
#define MYCLIPBOARDLOGGER_HPP

#include <QObject>
#include <QTimer>
#include <QString>

class MyClipboardLogger : public QObject
{
    Q_OBJECT
private:
    QTimer *timer = nullptr;
    QString lastEntry;
protected:
    void setTimer(QTimer *to);
    QTimer * getTimer(void);
    void setLastEntry(QString entry);
    QString getLastEntry(void);
public:
    explicit MyClipboardLogger(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MYCLIPBOARDLOGGER_HPP
