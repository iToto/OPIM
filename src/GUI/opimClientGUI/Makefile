#############################################################################
# Makefile for building: opimClientGUI
# Generated by qmake (2.01a) (Qt 4.4.3) on: Sun Apr 26 16:46:39 2009
# Project:  opimClientGUI.pro
# Template: app
# Command: /usr/bin/qmake -unix -o Makefile opimClientGUI.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/include/libxml2 -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I. -I.
LINK          = g++
LFLAGS        = -Wl,--no-undefined
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtGui -lQtCore -lpthread -lxml2
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		opimClientGUI.cpp \
		../../opim/opim.cpp \
		../UserList/opimUserList.cpp \
		../Chat/opimClientChat.cpp \
		../../delegateThread/delegateThread.cpp moc_opimClientGUI.cpp \
		moc_opimUserList.cpp \
		moc_opimClientChat.cpp
OBJECTS       = main.o \
		opimClientGUI.o \
		opim.o \
		opimUserList.o \
		opimClientChat.o \
		delegateThread.o \
		moc_opimClientGUI.o \
		moc_opimUserList.o \
		moc_opimClientChat.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		opimClientGUI.pro
QMAKE_TARGET  = opimClientGUI
DESTDIR       = 
TARGET        = opimClientGUI

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_opimClientGUI.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: opimClientGUI.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -unix -o Makefile opimClientGUI.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile opimClientGUI.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/opimClientGUI1.0.0 || $(MKDIR) .tmp/opimClientGUI1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/opimClientGUI1.0.0/ && $(COPY_FILE) --parents opimClientGUI.h ../../opim/opim.h ../UserList/opimUserList.h ../UserList/ui_opimUserList.h ../Chat/opimClientChat.h ../Chat/ui_opimClientChat.h ../../delegateThread/delegateThread.h .tmp/opimClientGUI1.0.0/ && $(COPY_FILE) --parents main.cpp opimClientGUI.cpp ../../opim/opim.cpp ../UserList/opimUserList.cpp ../Chat/opimClientChat.cpp ../../delegateThread/delegateThread.cpp .tmp/opimClientGUI1.0.0/ && $(COPY_FILE) --parents opimClientGUI.ui .tmp/opimClientGUI1.0.0/ && (cd `dirname .tmp/opimClientGUI1.0.0` && $(TAR) opimClientGUI1.0.0.tar opimClientGUI1.0.0 && $(COMPRESS) opimClientGUI1.0.0.tar) && $(MOVE) `dirname .tmp/opimClientGUI1.0.0`/opimClientGUI1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/opimClientGUI1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_opimClientGUI.cpp moc_opimUserList.cpp moc_opimClientChat.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_opimClientGUI.cpp moc_opimUserList.cpp moc_opimClientChat.cpp
moc_opimClientGUI.cpp: ../../opim/opim.h \
		ui_opimClientGUI.h \
		../UserList/opimUserList.h \
		../UserList/ui_opimUserList.h \
		../Chat/opimClientChat.h \
		../Chat/ui_opimClientChat.h \
		../../delegateThread/delegateThread.h \
		opimClientGUI.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) opimClientGUI.h -o moc_opimClientGUI.cpp

moc_opimUserList.cpp: ../../opim/opim.h \
		../UserList/ui_opimUserList.h \
		../Chat/opimClientChat.h \
		../Chat/ui_opimClientChat.h \
		../../delegateThread/delegateThread.h \
		../UserList/opimUserList.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ../UserList/opimUserList.h -o moc_opimUserList.cpp

moc_opimClientChat.cpp: ../Chat/ui_opimClientChat.h \
		../../opim/opim.h \
		../../delegateThread/delegateThread.h \
		../Chat/opimClientChat.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ../Chat/opimClientChat.h -o moc_opimClientChat.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_opimClientGUI.h
compiler_uic_clean:
	-$(DEL_FILE) ui_opimClientGUI.h
ui_opimClientGUI.h: opimClientGUI.ui
	/usr/bin/uic-qt4 opimClientGUI.ui -o ui_opimClientGUI.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp opimClientGUI.h \
		../../opim/opim.h \
		ui_opimClientGUI.h \
		../UserList/opimUserList.h \
		../UserList/ui_opimUserList.h \
		../Chat/opimClientChat.h \
		../Chat/ui_opimClientChat.h \
		../../delegateThread/delegateThread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

opimClientGUI.o: opimClientGUI.cpp opimClientGUI.h \
		../../opim/opim.h \
		ui_opimClientGUI.h \
		../UserList/opimUserList.h \
		../UserList/ui_opimUserList.h \
		../Chat/opimClientChat.h \
		../Chat/ui_opimClientChat.h \
		../../delegateThread/delegateThread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o opimClientGUI.o opimClientGUI.cpp

opim.o: ../../opim/opim.cpp ../../opim/opim.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o opim.o ../../opim/opim.cpp

opimUserList.o: ../UserList/opimUserList.cpp ../UserList/opimUserList.h \
		../../opim/opim.h \
		../UserList/ui_opimUserList.h \
		../Chat/opimClientChat.h \
		../Chat/ui_opimClientChat.h \
		../../delegateThread/delegateThread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o opimUserList.o ../UserList/opimUserList.cpp

opimClientChat.o: ../Chat/opimClientChat.cpp ../Chat/opimClientChat.h \
		../Chat/ui_opimClientChat.h \
		../../opim/opim.h \
		../../delegateThread/delegateThread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o opimClientChat.o ../Chat/opimClientChat.cpp

delegateThread.o: ../../delegateThread/delegateThread.cpp ../../delegateThread/delegateThread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o delegateThread.o ../../delegateThread/delegateThread.cpp

moc_opimClientGUI.o: moc_opimClientGUI.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_opimClientGUI.o moc_opimClientGUI.cpp

moc_opimUserList.o: moc_opimUserList.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_opimUserList.o moc_opimUserList.cpp

moc_opimClientChat.o: moc_opimClientChat.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_opimClientChat.o moc_opimClientChat.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

