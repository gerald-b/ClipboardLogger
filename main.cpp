
#include <QApplication>
#include <iostream>
#include <cstdlib>
#include "myclipboardlogger.hpp"

#ifdef Q_OS_WIN
#include <windows.h>
#endif

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		QCoreApplication a(argc, argv);
        for(int i=1; i<argc; ++i)
        {
            QString curElement = QString(argv[i]);
            if (curElement.toUpper() == "--VERSION" ||
                    curElement.toUpper() == "-V"
                    )
            {
                std::cout << MY_VERSION << std::endl;
            }
        }
		return EXIT_SUCCESS;
	}
	else
	{
#if defined( Q_OS_WIN )
		::ShowWindow(::GetConsoleWindow(), SW_HIDE); //hide console window
#endif
		QApplication a(argc, argv);
		MyClipboardLogger *logger = new MyClipboardLogger();
		logger->startTimer();
		int e = a.exec();
		delete logger; //needed to execute deconstructor
		exit(e); //needed to exit the hidden console
	}

	return EXIT_FAILURE;
}
