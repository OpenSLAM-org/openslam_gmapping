OBJS= gridslamprocessor_tree.o motionmodel.o gridslamprocessor.o gfsreader.o
APPS= gfs2log gfs2rec gfs2neff gfs2stat

LDFLAGS+= -lutils -lsensor_range -llog -lscanmatcher -lsensor_base -lsensor_odometry $(GSL_LIB)
CPPFLAGS+=-I../sensor $(GSL_INCLUDE)

-include ../global.mk
-include ../build_tools/Makefile.generic-shared-object
