OBJS= stat.o  movement.o
APPS= autoptr_test stat_test test_smoother 

LDFLAGS+= $(GSL_LIB)
CPPFLAGS+= $(GSL_INCLUDE) -DFSLINE

-include ../global.mk
-include ../build_tools/Makefile.generic-shared-object

