ifeq ($(RELEASE), 1)
DBG_FLAGS = -O2
else
DBG_FLAGS = -g -O0 -DDEBUG
endif

PWD = $(shell pwd)

INC_DIRS = -I$(PWD)/../include

#LIBS = -lm -lGL -lglut -lGLU -lGLEW -lstdc++
LIBS = -lpthread

OBJS = $(SRCS:%.c=%.o)

TARGET = pthread_test pthread_test2 pthread_test3 pthread_test4 nonthread_integral pthread_integral

FILE_CONTROL_DIR = $(PWD)/../file
IPC_DIR = $(PWD)/../ipc

FILE_CONTROL_OBJS = $(shell find $(FILE_CONTROL_DIR) -name '*.o')
IPC_OBJS = $(shell find $(IPC_DIR) -name '*.o')
#MATH_TECH_OBJS = $(shell find $(MATH_TECH_DIR) -name '*.o')
#OGL_OBJS = $(shell find $(OGL_DIR) -name '*.o')
#RADAR_PRINCIPLES_OBJS = $(shell find $(RADAR_PRINCIPLES_DIR) -name '*.o')
#RADAR_SIGNAL_PROCESSING_OBJS = $(shell find $(RADAR_SIGNAL_PROCESSING_DIR) -name '*.o')

all:	$(TARGET)

pthread_test:	pthread_test.o
	@echo "$<"
	$(CC) -o $@ $< $(IPC_OBJS) $(LIBS)

pthread_test2:	pthread_test2.o
	@echo "$<"
	$(CC) -o $@ $< $(IPC_OBJS) $(LIBS)

pthread_test3:	pthread_test3.o
	@echo "$<"
	$(CC) -o $@ $< $(IPC_OBJS) $(LIBS)

pthread_test4:	pthread_test4.o
	@echo "$<"
	$(CC) -o $@ $< $(IPC_OBJS) $(LIBS)

nonthread_integral:	nonthread_integral.o
	@echo "$<"
	$(CC) -o $@ $< $(IPC_OBJS) $(LIBS)

pthread_integral:	pthread_integral.o
	@echo "$<"
	$(CC) -o $@ $< $(IPC_OBJS) $(LIBS)

.c.o:
	@echo "======================================="
	@echo "========= Compiling Main Prog ========="
	@echo "======================================="
	$(CC) $(DBG_FLAGS) -c $< -o $@ $(INC_DIRS)

clean:
	rm -rf *.o
	rm -rf $(TARGET)
