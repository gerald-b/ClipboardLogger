#ifndef IOUTPUT_HPP
#define IOUTPUT_HPP

#include <QString>

class IOutput
{
public:
    IOutput();
    virtual ~IOutput();
    virtual void writeContent(QString content) = 0;
};

#endif // IOUTPUT_HPP
