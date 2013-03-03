#-------------------------------------------------
#Copyright (c) 2013 Clement Roblot
#
#
#This file is part of Generateur de photo d'identite.
#
#Generateur de photo d'identite is free software: you can redistribute it and/or modify
#it under the terms of the GNU General Public License as published by
#the Free Software Foundation, either version 3 of the License, or
#(at your option) any later version.
#
#Generateur de photo d'identite is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.
#
#You should have received a copy of the GNU General Public License
#along with Generateur de photo d'identite.  If not, see <http://www.gnu.org/licenses/>.
#-------------------------------------------------


#-------------------------------------------------
#
# Project created by QtCreator 2013-01-06T20:36:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = generateur-de-photo-identite
TEMPLATE = app

unix:INCLUDEPATH += /usr/include/
unix:INCLUDEPATH += /usr/local/lib/
unix:CONFIG += link_pkgconfig
unix:PKGCONFIG += opencv




win32:RC_FILE = Generateur_de_photo_identitee.rc
#begin{opencv}
win32:INCLUDEPATH += "C:/opencv/build/include"
win32:INCLUDEPATH += "C:/opencv/build/include/opencv"
win32:INCLUDEPATH += "C:/opencv/build/include/opencv2"


win32:LIBS += C:/opencv/build/x86/mingw/lib/libopencv_calib3d243.dll.a
win32:LIBS += C:/opencv/build/x86/mingw/lib/libopencv_contrib243.dll.a
win32:LIBS += C:/opencv/build/x86/mingw/lib/libopencv_core243.dll.a
win32:LIBS += C:/opencv/build/x86/mingw/lib/libopencv_features2d243.dll.a
win32:LIBS += C:/opencv/build/x86/mingw/lib/libopencv_flann243.dll.a
win32:LIBS += C:/opencv/build/x86/mingw/lib/libopencv_gpu243.dll.a
win32:LIBS += C:/opencv/build/x86/mingw/lib/libopencv_highgui243.dll.a
win32:LIBS += C:/opencv/build/x86/mingw/lib/libopencv_imgproc243.dll.a
win32:LIBS += C:/opencv/build/x86/mingw/lib/libopencv_legacy243.dll.a
win32:LIBS += C:/opencv/build/x86/mingw/lib/libopencv_ml243.dll.a
win32:LIBS += C:/opencv/build/x86/mingw/lib/libopencv_nonfree243.dll.a
win32:LIBS += C:/opencv/build/x86/mingw/lib/libopencv_objdetect243.dll.a
win32:LIBS += C:/opencv/build/x86/mingw/lib/libopencv_stitching243.dll.a
win32:LIBS += C:/opencv/build/x86/mingw/lib/libopencv_video243.dll.a
win32:LIBS += C:/opencv/build/x86/mingw/lib/libopencv_videostab243.dll.a





SOURCES += main.cpp\
        mainwindow.cpp \
    refait.cpp \
    clicableqgraphicsview.cpp \
    conceptionplanche.cpp \
    recadragephoto.cpp

HEADERS  += mainwindow.h \
    refait.h \
    clicableqgraphicsview.h \
    conceptionplanche.h \
    recadragephoto.h

FORMS    += mainwindow.ui \
    conceptionplanche.ui \
    recadragephoto.ui

RESOURCES += \
    ressource.qrc


INSTALLS += target man lien icon16 icon22 icon32 icon48 icon64 icon128 iconscal

target.path = /$(DESTDIR)/usr/bin

man.files = doc/generateur-de-photo-identite.1.gz
man.path = /$(DESTDIR)/usr/share/man/man1

lien.files = lien/generateur-de-photo-identite.desktop
lien.path = /$(DESTDIR)/usr/share/applications

icon16.files = icon/debian/usr/share/icons/hicolor/16x16/apps/generateur-de-photo-identite.png
icon16.path = /$(DESTDIR)/usr/share/icons/hicolor/16x16/apps

icon22.files = icon/debian/usr/share/icons/hicolor/22x22/apps/generateur-de-photo-identite.png
icon22.path = /$(DESTDIR)/usr/share/icons/hicolor/22x22/apps

icon32.files = icon/debian/usr/share/icons/hicolor/32x32/apps/generateur-de-photo-identite.png
icon32.path = /$(DESTDIR)/usr/share/icons/hicolor/32x32/apps

icon48.files = icon/debian/usr/share/icons/hicolor/48x48/apps/generateur-de-photo-identite.png
icon48.path = /$(DESTDIR)/usr/share/icons/hicolor/48x48/apps

icon64.files = icon/debian/usr/share/icons/hicolor/64x64/apps/generateur-de-photo-identite.png
icon64.path = /$(DESTDIR)/usr/share/icons/hicolor/64x64/apps

icon128.files = icon/debian/usr/share/icons/hicolor/128x128/apps/generateur-de-photo-identite.png
icon128.path = /$(DESTDIR)/usr/share/icons/hicolor/128x128/apps

iconscal.files = icon/debian/usr/share/icons/hicolor/scalable/apps/generateur-de-photo_identite.svgz
iconscal.path = /$(DESTDIR)/usr/share/icons/hicolor/scalable/apps