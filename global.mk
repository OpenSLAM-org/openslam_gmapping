### You should not need to change anything below.
LINUX=1
MACOSX=0

# Compilers
CC=gcc
CXX=g++

# Paths
MAPPING_ROOT=/home/giorgio/src/gmapping-openslam/trunk
LIBDIR=/home/giorgio/src/gmapping-openslam/trunk/lib
BINDIR=/home/giorgio/src/gmapping-openslam/trunk/bin

# Build tools
PRETTY=/home/giorgio/src/gmapping-openslam/trunk/build_tools/pretty_compiler
MESSAGE=/home/giorgio/src/gmapping-openslam/trunk/build_tools/message
TESTLIB=/home/giorgio/src/gmapping-openslam/trunk/build_tools/testlib

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
MAKEFILE_GENERIC=/home/giorgio/src/gmapping-openslam/trunk/build_tools/Makefile.generic-shared-object
MAKEFILE_APP=/home/giorgio/src/gmapping-openslam/trunk/build_tools/Makefile.app
MAKEFILE_SUBDIRS=/home/giorgio/src/gmapping-openslam/trunk/build_tools/Makefile.subdirs


# Flags
CPPFLAGS+=-DLINUX -I/home/giorgio/src/gmapping-openslam/trunk -DCARMEN_SUPPORT 
CXXFLAGS+=
LDFLAGS+=
CARMENSUPPORT=1
ARIASUPPORT=0

GSL_LIB=-lgsl -lgslcblas
GSL_INCLUDE=-I/usr/include/



include /home/giorgio/src/gmapping-openslam/trunk/manual.mk

