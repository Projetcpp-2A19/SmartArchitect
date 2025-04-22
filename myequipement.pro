QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG +=QMAKE_LFLAGS_CONSOLE
CONFIG +=QMAKE_LFLAGS_CONSOLE_DLL
CONFIG +=QMAKE_LIBS_CONSOLE
QT+=sql
QT += core gui network
QT += network
QT += printsupport
QT += core gui texttospeech


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ajouterarchitecte.cpp \
    chatbot.cpp \
    codebarres.cpp \
    connection.cpp \
    equipement.cpp \
    findarchitecte.cpp \
    main.cpp \
    mainwindow.cpp \
    supprimerarchitecte.cpp \
    trouverarchitecte.cpp \
    updatearchitecte.cpp

HEADERS += \
    ajouterarchitecte.h \
    chatbot.h \
    codebarres.h \
    connection.h \
    equipement.h \
    findarchitecte.h \
    mainwindow.h \
    supprimerarchitecte.h \
    trouverarchitecte.h \
    updatearchitecte.h

FORMS += \
    ajouterarchitecte.ui \
    chatbot.ui \
    findarchitecte.ui \
    mainwindow.ui \
    supprimerarchitecte.ui \
    trouverarchitecte.ui \
    updatearchitecte.ui

TRANSLATIONS += \
    myequipement_fr_FR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
