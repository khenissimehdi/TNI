# -----------------------------------------------------------
#  Project created by ./ImageToolbox lun. mars 2 2020
# -----------------------------------------------------------
QT -= core
QT -= gui
TARGET = nagao
TEMPLATE = lib
CONFIG += release
DEFINES += NAGAO_LIBRARY
win32:DEFINES += __WINDOWS__ _USE_MATH_DEFINES EXP_STL
win32:OBJECTS_DIR = ./objs
unix:OBJECTS_DIR = ./.objs
UI_DIR = ui
MOC_DIR = tmp
DESTDIR = release
INCLUDEPATH += ./ ui ../../../../../../bib/vautrot/Toolbox/ImageToolbox
SOURCES += nagao.cpp
HEADERS += nagao.hpp
LIBS += -L../../../../../../bib/vautrot/Toolbox/ImageToolbox/release -lplugin
