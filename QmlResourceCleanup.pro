TEMPLATE = app

QT += qml quick

QMAKE_CFLAGS += "-O0"
QMAKE_CXXFLAGS += "-O0"

SOURCES += main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS +=
