# -----------------------------------------------------------
#  Project created by ./ImageToolbox lun. janv. 27 2020
# -----------------------------------------------------------
QT -= core
QT -= gui
TARGET = DynamiqueExpon
TEMPLATE = lib
CONFIG += release
DEFINES += DYNAMIQUEEXPON_LIBRARY
win32:DEFINES += __WINDOWS__ _USE_MATH_DEFINES EXP_STL
win32:OBJECTS_DIR = ./objs
unix:OBJECTS_DIR = ./.objs
UI_DIR = ui
MOC_DIR = tmp
DESTDIR = release
INCLUDEPATH += ./ ui ../../../../../../bib/vautrot/Toolbox/ImageToolbox
SOURCES += DynamiqueExpon.cpp
HEADERS += DynamiqueExpon.hpp
LIBS += -L../../../../../../bib/vautrot/Toolbox/ImageToolbox/release -lplugin
