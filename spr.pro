TEMPLATE = app

CONFIG += console c++11
CONFIG -= app_bundle qt

QMAKE_CXXFLAGS += -std=c++11 -fopenmp
QMAKE_LFLAGS += -std=c++11 -fopenmp
QMAKE_CXXFLAGS_RELEASE -= -O
QMAKE_CXXFLAGS_RELEASE -= -O1
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE *= -O3

LIBS += -larmadillo

INCLUDEPATH += include/

OTHER_FILES += .astylerc

SOURCES += \
    src/main.cpp \
    src/GeneralClasses/Vector.cpp \
    src/Materials/Material.cpp \
    src/GeneralClasses/Length.cpp \
    src/Materials/Material_Gold.cpp \
    src/InterpolationMethods/InterpolationMethod.cpp \
    src/InterpolationMethods/CubicHermiteInterpolator.cpp

HEADERS += \
    include/GeneralClasses/Complex.h \
    include/GeneralClasses/Vector.h \
    include/Materials/Material.h \
    include/GeneralClasses/PhysicalConstants.h \
    include/GeneralClasses/Length.h \
    include/Materials/Material_Gold.h \
    include/Materials.h \
    include/InterpolationMethods/InterpolationMethod.h \
    include/InterpolationMethods/CubicHermiteInterpolator.h
