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

TARGET = mq_client mq_server semaphore_test shm_send shm_recv non_sem sem

FILE_CONTROL_DIR = $(PWD)/../file
IPC_DIR = $(PWD)/../ipc

FILE_CONTROL_OBJS = $(shell find $(FILE_CONTROL_DIR) -name '*.o')
IPC_OBJS = $(shell find $(IPC_DIR) -name '*.o')
#MATH_TECH_OBJS = $(shell find $(MATH_TECH_DIR) -name '*.o')
#OGL_OBJS = $(shell find $(OGL_DIR) -name '*.o')
#RADAR_PRINCIPLES_OBJS = $(shell find $(RADAR_PRINCIPLES_DIR) -name '*.o')
#RADAR_SIGNAL_PROCESSING_OBJS = $(shell find $(RADAR_SIGNAL_PROCESSING_DIR) -name '*.o')

all:	$(TARGET)

mq_client:	mq_client.o
	@echo "$<"
	$(CC) -o $@ $< $(IPC_OBJS) $(LIBS)

mq_server:	mq_server.o
	@echo "$<"
	$(CC) -o $@ $< $(IPC_OBJS) $(LIBS)

semaphore_test:	semaphore_test.o
	@echo "$<"
	$(CC) -o $@ $< $(IPC_OBJS) $(LIBS)

shm_send:	shm_send.o
	@echo "$<"
	$(CC) -o $@ $< $(IPC_OBJS) $(LIBS)

shm_recv:	shm_recv.o
	@echo "$<"
	$(CC) -o $@ $< $(IPC_OBJS) $(LIBS)

non_sem:	non_sem.o
	@echo "$<"
	$(CC) -o $@ $< $(IPC_OBJS) $(LIBS)

sem:	sem.o
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
