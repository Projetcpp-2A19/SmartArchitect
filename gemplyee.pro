QT       += core gui
QT +=sql
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT +=core gui sql printsupport
QT += core gui sql printsupport widgets charts
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    emailsender.cpp \
    employee.cpp \
    login.cpp \
    loginform.cpp \
    main.cpp \
    mainwindow.cpp \
    passwordresetform.cpp \
    statspostewindow.cpp

HEADERS += \
    connexion.h \
    emailsender.h \
    employee.h \
    login.h \
    loginform.h \
    mainwindow.h \
    passwordresetform.h \
    statspostewindow.h

FORMS += \
    loginform.ui \
    mainwindow.ui \
    passwordresetform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
