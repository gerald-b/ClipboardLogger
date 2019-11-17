
#include <QApplication>
#include "myclipboardlogger.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    MyClipboardLogger logger;
    logger.startTimer();

    return a.exec();
}
