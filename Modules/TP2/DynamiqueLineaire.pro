# -----------------------------------------------------------
#  Project created by ./ImageToolbox lun. janv. 20 2020
# -----------------------------------------------------------
QT -= core
QT -= gui
TARGET = DynamiqueLineaire
TEMPLATE = lib
CONFIG += release
DEFINES += DYNAMIQUELINEAIRE_LIBRARY
win32:DEFINES += __WINDOWS__ _USE_MATH_DEFINES EXP_STL
win32:OBJECTS_DIR = ./objs
unix:OBJECTS_DIR = ./.objs
UI_DIR = ui
MOC_DIR = tmp
DESTDIR = release
INCLUDEPATH += ./ ui ../../../../../../bib/vautrot/Toolbox/ImageToolbox
SOURCES += DynamiqueLineaire.cpp
HEADERS += DynamiqueLineaire.hpp
LIBS += -L../../../../../../bib/vautrot/Toolbox/ImageToolbox/release -lplugin
