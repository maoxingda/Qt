#-------------------------------------------------
#
# Project created by QtCreator 2018-10-22T13:50:51
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = http
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    json/json_reader.cpp \
    json/json_value.cpp \
    json/json_writer.cpp

HEADERS += \
        mainwindow.h \
    json/autolink.h \
    json/config.h \
    json/forwards.h \
    json/json.h \
    json/json_batchallocator.h \
    json/json_features.h \
    json/json_tool.h \
    json/reader.h \
    json/value.h \
    json/writer.h

FORMS += \
        mainwindow.ui
