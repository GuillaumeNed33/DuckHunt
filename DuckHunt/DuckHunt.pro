TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    image.cpp \
    chien.cpp \
    evenement.cpp \
    boucle.cpp \
    gestionFichier.cpp \
    canard.cpp \
    gestionScore.cpp \
    chicken.cpp

LIBS+=`sdl-config --libs` -lSDL_image -lSDL_ttf
INCLUDEPATH+=-I/usr/include/SDL/

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    image.h \
    chien.h \
    evenement.h \
    boucle.h \
    gestionFichier.h \
    canard.h \
    gestionScore.h \
    chicken.h

