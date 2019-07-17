#-------------------------------------------------
#
# Project created by QtCreator 2019-07-03T14:35:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = openCV
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

CONFIG += c++11

SOURCES += \
        bba_facerecognizer.cpp \
        bba_mainthread.cpp \
        bba_objectdetect.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        bba_facerecognizer.h \
        bba_mainthread.h \
        bba_objectdetect.h \
        mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -L$$PWD/../../../OpenCV-4.1.0/x86_install/lib/ -lopencv_world

INCLUDEPATH += $$PWD/../../../OpenCV-4.1.0/x86_install_contrib/include/opencv4
DEPENDPATH += $$PWD/../../../OpenCV-4.1.0/x86_install_contrib/include/opencv4

unix:!macx: LIBS += -L$$PWD/../../../OpenCV-4.1.0/x86_install_contrib/lib/ -lopencv_img_hash

INCLUDEPATH += $$PWD/../../../OpenCV-4.1.0/x86_install_contrib/lib
DEPENDPATH += $$PWD/../../../OpenCV-4.1.0/x86_install_contrib/lib
