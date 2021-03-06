QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += console

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ioutput.cpp \
    main.cpp \
    myclipboardlogger.cpp \
    outputfactory.cpp \
    outputfile.cpp \
    outputsqlite.cpp

HEADERS += \
    enum_outputtype.hpp \
    ioutput.hpp \
    myclipboardlogger.hpp \
    outputfactory.hpp \
    outputfile.hpp \
    outputsqlite.hpp

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    settings.ini \
    settings_sample.ini

CONFIG(debug, debug|release) {
    VARIANT = debug
} else {
    VARIANT = release
}

win32 {
    COPY_FROM_PATH=$$shell_path($$PWD/settings*.ini)
    COPY_TO_PATH=$$shell_path($$OUT_PWD/$$VARIANT/)
}
else {
    COPY_FROM_PATH=$$PWD/settings*.ini
    COPY_TO_PATH=$$OUT_PWD/
}

copydata.commands = $(COPY_DIR) $$COPY_FROM_PATH $$COPY_TO_PATH
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata


#Target Version
MY_VERSION_MAJOR=0
MY_VERSION_MINOR=1
MY_VERSIOM_PATCH=0
MY_VERSION_REVISON=0

DEFINES += MY_VERSION_MAJOR=\"\\\"$${MY_VERSION_MAJOR}\\\"\"
DEFINES += MY_VERSION_MAJOR=\"\\\"$${MY_VERSION_MAJOR}\\\"\"
DEFINES += MY_VERSION_MINOR=\"\\\"$${MY_VERSION_MINOR}\\\"\"
DEFINES += MY_VERSIOM_PATCH=\"\\\"$${MY_VERSIOM_PATCH}\\\"\"
DEFINES += MY_VERSION_REVISON=\"\\\"$${MY_VERSION_REVISON}\\\"\"

# Version must be set for Windows to set "File-Version"
VERSION = $${MY_VERSION_MAJOR}"."$${MY_VERSION_MINOR}"."$${MY_VERSIOM_PATCH}"."$${MY_VERSION_REVISON}
MY_VERSION = $${VERSION}
DEFINES += MY_VERSION=\"\\\"$${MY_VERSION}\\\"\"
