# -----------------------------------------------------------
#  Project created by ./ImageToolbox lun. févr. 3 2020
# -----------------------------------------------------------
QT -= core
QT -= gui
TARGET = CoupeBande
TEMPLATE = lib
CONFIG += release
DEFINES += COUPEBANDE_LIBRARY
win32:DEFINES += __WINDOWS__ _USE_MATH_DEFINES EXP_STL
win32:OBJECTS_DIR = ./objs
unix:OBJECTS_DIR = ./.objs
UI_DIR = ui
MOC_DIR = tmp
DESTDIR = release
INCLUDEPATH += ./ ui ../../../../../../bib/vautrot/Toolbox/ImageToolbox
SOURCES += CoupeBande.cpp
HEADERS += CoupeBande.hpp
LIBS += -L../../../../../../bib/vautrot/Toolbox/ImageToolbox/release -lplugin
