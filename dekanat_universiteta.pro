TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        menu.cpp \
        rwFunc.cpp

HEADERS += \
    menu.h \
    rwFunc.h \
    student.h

DISTFILES += \
    doffice.db
