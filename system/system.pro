QT       += core gui sql
QT += webenginewidgets webchannel

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alterbase.cpp \
    deletebase.cpp \
    enrollwidget.cpp \
    insertbase.cpp \
    main.cpp \
    mainwindow.cpp \
    selectbase.cpp \
    widget.cpp

HEADERS += \
    alterbase.h \
    deletebase.h \
    enrollwidget.h \
    insertbase.h \
    mainwindow.h \
    selectbase.h \
    widget.h

FORMS += \
    alterbase.ui \
    deletebase.ui \
    enrollwidget.ui \
    insertbase.ui \
    mainwindow.ui \
    selectbase.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
