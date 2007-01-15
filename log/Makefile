OBJS= configuration.o carmenconfiguration.o sensorlog.o sensorstream.o
APPS= log_test log_plot scanstudio2carmen rdk2carmen

LDFLAGS+= -lsensor_base -l sensor_odometry -l sensor_range
CPPFLAGS+= -I../sensor 

-include ../global.mk
-include ../build_tools/Makefile.generic-shared-object

