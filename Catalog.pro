#-------------------------------------------------
#
# Project created by Evgeniy Zorin
#
#-------------------------------------------------

QT       += core gui
QT       += core
QT       += xml
#CONFIG   += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Catalog
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
    BaseClass.cpp \
    firmclass.cpp \
        main.cpp \
        mainwindow.cpp \
    projectclass.cpp \
    xmlparser.cpp \
    implementation.cpp \
    search_method.cpp

HEADERS += \
    BaseClass.h \
    firmclass.h \
        mainwindow.h \
        implementation.h \
    projectclass.h \
    xmlparser.h \
    search_method.h

FORMS += \
        mainwindow.ui
TRANSLATIONS += Catalog_ru.ts
               #Catalog_eu.ts



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Catalog_ru.ts
