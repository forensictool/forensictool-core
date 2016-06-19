include(version.pri)

TEMPLATE = app
TARGET = coex-cli
DESTDIR = bin/
OBJECTS_DIR = tmp/
QT -= gui

INCLUDEPATH += src/interfaces/

SOURCES += \
	src/helpers/config.cpp \
	src/helpers/typeos.cpp \
	src/helpers/typeos_ubuntu.cpp \
	src/taskrunner.cpp \
	src/core.cpp \
	src/app.cpp \


HEADERS += \
	src/helpers/config.h \
	src/helpers/typeos.h \
	src/helpers/typeos_ubuntu.h \
	src/taskrunner.h \
	src/core.h \

	
OBJECTS_DIR = tmp/

QT += core \
 xml \
