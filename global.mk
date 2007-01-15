### You should not need to change anything below.
LINUX=1
MACOSX=0

# Compilers
CC=gcc
CXX=g++

# Paths
MAPPING_ROOT=/home/merci/stachnis/code/svn-gmapping2
LIBDIR=/home/merci/stachnis/code/svn-gmapping2/lib
BINDIR=/home/merci/stachnis/code/svn-gmapping2/bin

# Build tools
PRETTY=/home/merci/stachnis/code/svn-gmapping2/build_tools/pretty_compiler
MESSAGE=/home/merci/stachnis/code/svn-gmapping2/build_tools/message
TESTLIB=/home/merci/stachnis/code/svn-gmapping2/build_tools/testlib

# QT support
MOC=/usr/lib/qt3/bin/moc
QT_LIB=-L /usr/lib/qt3/lib -lqt-mt
QT_INCLUDE=-I /usr/lib/qt3/include

# ARIA support
ARIA_LIB=
ARIA_INCLUDE=


# # KDE support
# KDE_LIB=
# KDE_INCLUDE=
# UIC=

# Generic makefiles
MAKEFILE_GENERIC=/home/merci/stachnis/code/svn-gmapping2/build_tools/Makefile.generic-shared-object
MAKEFILE_APP=/home/merci/stachnis/code/svn-gmapping2/build_tools/Makefile.app
MAKEFILE_SUBDIRS=/home/merci/stachnis/code/svn-gmapping2/build_tools/Makefile.subdirs


# Flags
CPPFLAGS+=-DLINUX -I/home/merci/stachnis/code/svn-gmapping2 -DCARMEN_SUPPORT 
CXXFLAGS+=
LDFLAGS+=
CARMENSUPPORT=1
ARIASUPPORT=0

GSL_LIB=-lgsl -lgslcblas
GSL_INCLUDE=-I/usr/include/



include /home/merci/stachnis/code/svn-gmapping2/manual.mk

