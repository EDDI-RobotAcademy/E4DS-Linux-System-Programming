ifeq ($(RELEASE), 1)
DBG_FLAGS = -O2
else
DBG_FLAGS = -g -O0 -DDEBUG
endif

PWD = $(shell pwd)

INC_DIRS = -I$(PWD)/../include

#LIBS = -lm -lGL -lglut -lGLU -lGLEW -lstdc++
LIBS = 

OBJS = $(SRCS:%.c=%.o)

TARGET = execve_test execve_test2 execve_howto newpgm execve_howto2 newpgm2 execve_howto3 execve_howto4 multi_process multi_process2 daemon_howto

FILE_CONTROL_DIR = $(PWD)/../file

FILE_CONTROL_OBJS = $(shell find $(FILE_CONTROL_DIR) -name '*.o')
#MATH_TECH_OBJS = $(shell find $(MATH_TECH_DIR) -name '*.o')
#OGL_OBJS = $(shell find $(OGL_DIR) -name '*.o')
#RADAR_PRINCIPLES_OBJS = $(shell find $(RADAR_PRINCIPLES_DIR) -name '*.o')
#RADAR_SIGNAL_PROCESSING_OBJS = $(shell find $(RADAR_SIGNAL_PROCESSING_DIR) -name '*.o')

all:	$(TARGET)

execve_test:	execve_test.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

execve_test2:	execve_test2.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

execve_howto:	execve_howto.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

newpgm:	newpgm.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

execve_howto2:	execve_howto2.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

newpgm2:	newpgm2.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

execve_howto3:	execve_howto3.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

execve_howto4:	execve_howto4.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

multi_process:	multi_process.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

multi_process2:	multi_process2.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

daemon_howto:	daemon_howto.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

.c.o:
	@echo "======================================="
	@echo "========= Compiling Main Prog ========="
	@echo "======================================="
	$(CC) $(DBG_FLAGS) -c $< -o $@ $(INC_DIRS)

clean:
	rm -rf *.o
	rm -rf $(TARGET)
