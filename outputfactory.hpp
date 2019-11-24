#ifndef OUTPUTFACTORY_HPP
#define OUTPUTFACTORY_HPP

#include <QSettings>
#include "ioutput.hpp"
#include "enum_outputtype.hpp"
#include "outputfile.hpp"

class OutputFactory
{
private:
    QSettings * mySettings = nullptr;
    void setMySettings(QSettings * settings);
    QSettings * getMySettings(void);
public:
    OutputFactory(QSettings * settings);
    IOutput * getOutput(OutputType ot);
};

#endif // OUTPUTFACTORY_HPP
