#-------------------------------------------------
#
# Project created by QtCreator 2013-03-04T15:57:39
#
#-------------------------------------------------
QT += testlib


TARGET = testtrack
CONFIG   += console
CONFIG   += dirs

LEVEL=""

TEMPLATE = app


SOURCES += main.cpp \
    test_func.cpp \
    ../tracking/clear_version/track/functions.cpp \
    ../tracking/clear_version/track/track_clear_function.cpp \
    test_tracking.cpp

HEADERS += \
    AutoTest.h \
    TestObjects.h \
    test_func.h \
    ../tracking/clear_version/track/functions.h \
    ../tracking/clear_version/track/track_clear_function.h \
    test_tracking.h

OPENCVDIR = "C:/workspace/opencv-2.4.10/opencv/build"

CONFIG(debug, debug|release) {
      OPENCVDIR = $$OPENCVDIR
      CVVER=2410d
      DESTDIR = bin/debug
}
CONFIG(release, debug|release) {
       OPENCVDIR = $$OPENCVDIR
       CVVER=2410
       DESTDIR = bin/release
}

INCLUDEPATH += $${OPENCVDIR}/include

LIBS += -L$${OPENCVDIR}/x86/vc11/lib \
-lopencv_core$${CVVER} \
-lopencv_imgproc$${CVVER} \
-lopencv_highgui$${CVVER} \
-lopencv_calib3d$${CVVER} \
-lopencv_features2d$${CVVER} \
-lopencv_nonfree$${CVVER} \
-lopencv_video$${CVVER} \
-lopencv_flann$${CVVER} \
-lopencv_ml$${CVVER}

