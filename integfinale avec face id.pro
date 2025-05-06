QT       += core gui quick
QT +=sql
QT += core gui serialport sql network texttospeech
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT +=core gui sql printsupport
QT += core gui sql printsupport widgets charts
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    architecte.cpp \
    arduino.cpp \
    arduinomanager.cpp \
    cartefidelitedialog.cpp \
    chatbot.cpp \
    chatbotwindow.cpp \
    client.cpp \
    codebarres.cpp \
    connection.cpp \
    dashboardwindow.cpp \
    emailsender.cpp \
    employee.cpp \
    envoyermail.cpp \
    equipement.cpp \
    fidelite.cpp \
    fournisseur.cpp \
    gprojett.cpp \
    login.cpp \
    loginform.cpp \
    main.cpp \
    mainarch.cpp \
    mainclient.cpp \
    mainequip.cpp \
    mainprojet.cpp \
    mainwindow.cpp \
    passwordresetform.cpp \
    projetmanager.cpp \
    qrcodegen.cpp \
    serialhandler.cpp \
    statspostewindow.cpp

HEADERS += \
    architecte.h \
    arduino.h \
    arduinomanager.h \
    cartefidelitedialog.h \
    chatbot.h \
    chatbotwindow.h \
    client.h \
    codebarres.h \
    connection.h \
    dashboardwindow.h \
    emailsender.h \
    employee.h \
    envoyermail.h \
    equipement.h \
    fidelite.h \
    fournisseur.h \
    gprojett.h \
    login.h \
    loginform.h \
    mainarch.h \
    mainclient.h \
    mainequip.h \
    mainprojet.h \
    mainwindow.h \
    passwordresetform.h \
    projetmanager.h \
    qrcodegen.hpp \
    serialhandler.h \
    statspostewindow.h

FORMS += \
    chatbot.ui \
    chatbotwindow.ui \
    dashboardwindow.ui \
    gprojett.ui \
    loginform.ui \
    mainclient.ui \
    mainequip.ui \
    mainprojet.ui \
    mainwindow.ui \
    mainarch.ui \
    passwordresetform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
