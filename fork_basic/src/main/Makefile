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

TARGET = fork_test parent_child child_task_id multi_tasking1 multi_tasking2 ps_test1 ps_test2 cow_test1 cow_test2 process_comm_test

FILE_CONTROL_DIR = $(PWD)/../file

FILE_CONTROL_OBJS = $(shell find $(FILE_CONTROL_DIR) -name '*.o')
#MATH_TECH_OBJS = $(shell find $(MATH_TECH_DIR) -name '*.o')
#OGL_OBJS = $(shell find $(OGL_DIR) -name '*.o')
#RADAR_PRINCIPLES_OBJS = $(shell find $(RADAR_PRINCIPLES_DIR) -name '*.o')
#RADAR_SIGNAL_PROCESSING_OBJS = $(shell find $(RADAR_SIGNAL_PROCESSING_DIR) -name '*.o')

all:	$(TARGET)

fork_test:	fork_test.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

parent_child:	parent_child.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

child_task_id:	child_task_id.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

multi_tasking1:	multi_tasking1.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

multi_tasking2:	multi_tasking2.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

ps_test1:	ps_test1.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

ps_test2:	ps_test2.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

cow_test1:	cow_test1.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

cow_test2:	cow_test2.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

process_comm_test:	process_comm_test.o
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
