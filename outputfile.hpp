#ifndef OUTPUTFILE_HPP
#define OUTPUTFILE_HPP

#include <QFile>
#include <QTextStream>
#include "ioutput.hpp"

class OutputFile : public IOutput
{
private:
    QFile * outputFile = nullptr;
public:
    OutputFile();
    virtual ~OutputFile() override;
    void setOutputFile(QFile * file);
    void setOutputFile(QString filepath);
    QFile * getOutputFile(void);

    // IOutput interface
public:
    virtual void writeContent(QString content) override;
};

#endif // OUTPUTFILE_HPP
