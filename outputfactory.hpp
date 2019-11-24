#ifndef OUTPUTFACTORY_HPP
#define OUTPUTFACTORY_HPP

#include "ioutput.hpp"
#include "enum_outputtype.hpp"
#include "outputfile.hpp"

class OutputFactory
{
public:
    OutputFactory();
    IOutput * getOutput(OutputType ot);
};

#endif // OUTPUTFACTORY_HPP
