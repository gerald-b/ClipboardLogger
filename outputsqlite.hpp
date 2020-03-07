#ifndef OUTPUTSQLITE_HPP
#define OUTPUTSQLITE_HPP

#include <QFileInfo>
#include <QDateTime>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "ioutput.hpp"

class OutputSqlite : public IOutput
{
private:
    QSqlDatabase myDb;
public:
    OutputSqlite();
    virtual ~OutputSqlite() override;
    void setDBFile(QString file);

    // IOutput interface
public:
    virtual void writeContent(QString content) override;
};

#endif // OUTPUTSQLITE_HPP
