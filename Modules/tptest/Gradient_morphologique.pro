# -----------------------------------------------------------
#  Project created by ./ImageToolbox lun. mars 9 2020
# -----------------------------------------------------------
QT -= core
QT -= gui
TARGET = Gradient_morphologique
TEMPLATE = lib
CONFIG += release
DEFINES += GRADIENT_MORPHOLOGIQUE_LIBRARY
win32:DEFINES += __WINDOWS__ _USE_MATH_DEFINES EXP_STL
win32:OBJECTS_DIR = ./objs
unix:OBJECTS_DIR = ./.objs
UI_DIR = ui
MOC_DIR = tmp
DESTDIR = release
INCLUDEPATH += ./ ui ../../../../../../bib/vautrot/Toolbox/ImageToolbox
SOURCES += Gradient_morphologique.cpp
HEADERS += Gradient_morphologique.hpp
LIBS += -L../../../../../../bib/vautrot/Toolbox/ImageToolbox/release -lplugin
