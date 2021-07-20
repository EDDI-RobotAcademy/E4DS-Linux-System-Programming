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

TARGET = independent_fd dup_test1 dup_test2 eddi_tail eddi_pipe eddi_adv_pipe

FILE_CONTROL_DIR = $(PWD)/../file

FILE_CONTROL_OBJS = $(shell find $(FILE_CONTROL_DIR) -name '*.o')
#MATH_TECH_OBJS = $(shell find $(MATH_TECH_DIR) -name '*.o')
#OGL_OBJS = $(shell find $(OGL_DIR) -name '*.o')
#RADAR_PRINCIPLES_OBJS = $(shell find $(RADAR_PRINCIPLES_DIR) -name '*.o')
#RADAR_SIGNAL_PROCESSING_OBJS = $(shell find $(RADAR_SIGNAL_PROCESSING_DIR) -name '*.o')

all:	$(TARGET)

independent_fd:	independent_fd.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

dup_test1:	dup_test1.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

dup_test2:	dup_test2.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

eddi_tail:	eddi_tail.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

eddi_pipe:	eddi_pipe.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

eddi_adv_pipe:	eddi_adv_pipe.o
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
