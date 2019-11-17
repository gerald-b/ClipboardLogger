#ifndef MYCLIPBOARDLOGGER_HPP
#define MYCLIPBOARDLOGGER_HPP

#include <QObject>
#include <QTimer>

class MyClipboardLogger : public QObject
{
    Q_OBJECT
private:
    QTimer *timer = nullptr;
protected:
    void setTimer(QTimer *to);
    QTimer * getTimer(void);
public:
    explicit MyClipboardLogger(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MYCLIPBOARDLOGGER_HPP
