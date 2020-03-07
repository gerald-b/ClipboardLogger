#include "outputfactory.hpp"

void OutputFactory::setMySettings(QSettings *settings)
{
    // delete is not necessary must be deleted by
    // the other class (who uses the factory)
    this->mySettings = settings;
}

QSettings *OutputFactory::getMySettings()
{
    return this->mySettings;
}

OutputFactory::OutputFactory(QSettings *settings)
{
    this->setMySettings(settings);
}

IOutput *OutputFactory::getOutput(OutputType ot)
{
    IOutput * ret = nullptr;
    OutputFile * retOF = nullptr;
    OutputSqlite * retOS = nullptr;
    switch (ot) {
        case OutputType::FILE:
            retOF = new OutputFile();
            retOF->setOutputFile(this->getMySettings()->value("global/outputFile", "out.log").toString());
            ret = retOF;
        break;
        case OutputType::SQLITE:
            retOS = new OutputSqlite();
            retOS->setDBFile(this->getMySettings()->value("global/outputDatabase", "out.db").toString());
            ret = retOS;
        break;
    }
    return ret;
}
