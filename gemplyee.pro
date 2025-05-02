QT       += core gui
QT +=sql
QT += core gui serialport sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT +=core gui sql printsupport
QT += core gui sql printsupport widgets charts
QT += core gui widgets network
QT += networkauth
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    dashboardwindow.cpp \
    emailsender.cpp \
    employee.cpp \
    gprojett.cpp \
    login.cpp \
    loginform.cpp \
    main.cpp \
    mainwindow.cpp \
    projetmanager.cpp \
    serialhandler.cpp \
    statspostewindow.cpp

HEADERS += \
    connexion.h \
    dashboardwindow.h \
    emailsender.h \
    employee.h \
    gprojett.h \
    login.h \
    loginform.h \
    mainwindow.h \
    projetmanager.h \
    serialhandler.h \
    statspostewindow.h


FORMS += \
    dashboardwindow.ui \
    gprojett.ui \
    loginform.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
