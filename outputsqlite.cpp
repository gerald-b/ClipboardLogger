#include "outputsqlite.hpp"

OutputSqlite::OutputSqlite()
{

}

OutputSqlite::~OutputSqlite()
{

}

void OutputSqlite::setDBFile(QString file)
{
    this->myDb = QSqlDatabase::addDatabase("QSQLITE");

    if (!QFileInfo::exists(file))
    {
        this->myDb.setDatabaseName(file);
        if (!this->myDb.open())
        {

        }
        QString sqlCreate = "";
        sqlCreate += "CREATE TABLE \"logdata\" (";
        sqlCreate += "    \"id\" INTEGER PRIMARY KEY AUTOINCREMENT,";
        sqlCreate += "    \"timestamp\" TEXT,";
        sqlCreate += "    \"content\" TEXT";
        sqlCreate += ")";
        QSqlQuery query(sqlCreate,this->myDb);
        query.exec();
        if (this->myDb.isOpen())
        {
            this->myDb.close();
        }
    }
    else
    {
        this->myDb.setDatabaseName(file);
    }
}

void OutputSqlite::writeContent(QString content)
{
    QString sql = "";
    sql += "INSERT INTO `logdata` ";
    sql += " (`timestamp`,`content`) ";
    sql += "VALUES (";
    sql += "'";
    sql += QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
    sql += "','";
    sql += content.replace("'","''");
    sql += "')";

    if (!this->myDb.isOpen())
    {
        this->myDb.open();
    }

    QSqlQuery query("",this->myDb);
    query.exec(sql);
    // QMessageBox::critical(nullptr,"ERR",query.lastError().text(),QMessageBox::Ok);

    if(this->myDb.isOpen())
    {
        this->myDb.close();
    }
}
