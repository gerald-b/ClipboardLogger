#include "outputfactory.hpp"

OutputFactory::OutputFactory()
{

}

IOutput *OutputFactory::getOutput(OutputType ot)
{
    IOutput * ret = nullptr;
    OutputFile * retOF = nullptr;
    switch (ot) {
        case OutputType::FILE:
            retOF = new OutputFile();
            retOF->setOutputFile("outFactory.log");
            ret = retOF;
        break;
    }
    return ret;
}
