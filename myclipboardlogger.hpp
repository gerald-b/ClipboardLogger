#ifndef MYCLIPBOARDLOGGER_HPP
#define MYCLIPBOARDLOGGER_HPP

#include <QObject>

class MyClipboardLogger : public QObject
{
    Q_OBJECT
public:
    explicit MyClipboardLogger(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MYCLIPBOARDLOGGER_HPP
