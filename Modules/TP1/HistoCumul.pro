# -----------------------------------------------------------
#  Project created by ./ImageToolbox lun. janv. 13 2020
# -----------------------------------------------------------
QT -= core
QT -= gui
TARGET = HistoCumul
TEMPLATE = lib
CONFIG += release
DEFINES += HISTOCUMUL_LIBRARY
win32:DEFINES += __WINDOWS__ _USE_MATH_DEFINES EXP_STL
win32:OBJECTS_DIR = ./objs
unix:OBJECTS_DIR = ./.objs
UI_DIR = ui
MOC_DIR = tmp
DESTDIR = release
INCLUDEPATH += ./ ui ../../../../../../bib/vautrot/Toolbox/ImageToolbox
SOURCES += HistoCumul.cpp
HEADERS += HistoCumul.hpp
LIBS += -L../../../../../../bib/vautrot/Toolbox/ImageToolbox/release -lplugin
