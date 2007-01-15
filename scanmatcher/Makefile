OBJS= smmap.o scanmatcher.o scanmatcherprocessor.o 
APPS= scanmatch_test icptest

LDFLAGS+= $(GSL_LIB) -lutils -lsensor_range -llog
CPPFLAGS+=-I../sensor $(GSL_INCLUDE)

-include ../global.mk
-include ../build_tools/Makefile.generic-shared-object

