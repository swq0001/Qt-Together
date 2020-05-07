QT       += core gui
QT+= core gui multimedia multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chatroom.cpp \
    commonhelper.cpp \
    controls.cpp \
    customwidget.cpp \
    logindlg.cpp \
    main.cpp \
    main.cpp \
    personalinfodialog.cpp \
    personalinfodialog.cpp \
    rtmppusher.cpp \
    rtmppusherwidget.cpp \
    signupdialog.cpp \
    signupdialog.cpp \
    tcpclient.cpp \
    tcpserver.cpp \
    tcpserver.cpp \
    titlebar.cpp \
    videoplayer.cpp

HEADERS += \
    chatroom.h \
    commonhelper.h \
    controls.h \
    customwidget.h \
    logindlg.h \
    personalinfodialog.h \
    personalinfodialog.h \
    rtmppusher.h \
    rtmppusherwidget.h \
    signupdialog.h \
    signupdialog.h \
    tcpclient.h \
    tcpclient.h \
    tcpserver.h \
    tcpserver.h \
    titlebar.h \
    videoplayer.h

FORMS += \
    signupdialog.ui \
    tcpclient.ui \
    tcpserver.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    MyImages.qrc

LIBS+=-L$$PWD/lib/ -lQtAV1 -lQtAVWidgets1 -lQmlAV
LIBS+=-L$$PWD/lib/ffmpeg/ -lavcodec -lavdevice -lavfilter \
-lavformat -lavresample -lavutil -lswresample -lswscale

########## template for QtAV app project BEGIN ################
greaterThan(QT_MAJOR_VERSION, 4) {
  QT += avwidgets
} else {
  CONFIG += avwidgets
}

RC_ICONS=TIcon.ico
