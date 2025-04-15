QT       += core gui printsupport \
            quick sql charts serialport widgets
QT       +=serialport
CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    arduino.cpp \
    cartefidelitedialog.cpp \
    client.cpp \
    connection.cpp \
    fidelite.cpp \
    main.cpp \
    mainwindow.cpp \
    qrcodegen.cpp

HEADERS += \
    arduino.h \
    cartefidelitedialog.h \
    client.h \
    connection.h \
    fidelite.h \
    mainwindow.h \
    qrcodegen.hpp

FORMS += \
    mainwindow.ui

# === QZXing integration ===
include(qzxing/QZXing.pri)    # ✅ Assure-toi que ce chemin est bon

# Deployment (par défaut)
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
