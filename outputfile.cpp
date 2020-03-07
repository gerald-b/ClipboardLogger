#include "outputfile.hpp"

void OutputFile::setOutputFile(QFile *file)
{
    if(nullptr != this->outputFile)
    {
        delete this->outputFile;
    }
    this->outputFile = file;
}

void OutputFile::setOutputFile(QString filepath)
{

    this->setOutputFile(new QFile(filepath));
}

QFile *OutputFile::getOutputFile()
{
    return this->outputFile;
}

OutputFile::OutputFile()
{

}

OutputFile::~OutputFile()
{
    if(nullptr != this->outputFile)
    {
        delete this->outputFile;
    }
}

void OutputFile::writeContent(QString content)
{
    if (!this->getOutputFile()->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        return;
    }
    QTextStream outTextStream(this->getOutputFile());
    outTextStream << content.trimmed() << "\n";
    if (this->getOutputFile()->isOpen())
    {
        this->getOutputFile()->close();
    }
}
