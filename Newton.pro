TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
QT += widgets

SOURCES += \
        complex.cpp \
        fraction.cpp \
        interpol.cpp \
        lagrange.cpp \
        main.cpp \
        monomial.cpp \
        pointdialog.cpp \
        polynom.cpp \
        widget.cpp




HEADERS += \
    complex.h \
    fraction.h \
    lagrange.h \
    interpol.h \
    monomial.h \
    pointdialog.h \
    polynom.h \
    interpol.h \
    widget.h

FORMS += \
    pointdialog.ui \
    widget.ui
