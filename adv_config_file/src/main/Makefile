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

TARGET = file_write file_read file_lseek file_rdwr eddi_cat

FILE_CONTROL_DIR = $(PWD)/../file

FILE_CONTROL_OBJS = $(shell find $(FILE_CONTROL_DIR) -name '*.o')
#MATH_TECH_OBJS = $(shell find $(MATH_TECH_DIR) -name '*.o')
#OGL_OBJS = $(shell find $(OGL_DIR) -name '*.o')
#RADAR_PRINCIPLES_OBJS = $(shell find $(RADAR_PRINCIPLES_DIR) -name '*.o')
#RADAR_SIGNAL_PROCESSING_OBJS = $(shell find $(RADAR_SIGNAL_PROCESSING_DIR) -name '*.o')

all:	$(TARGET)

file_write:	file_write.o
	@echo "$<" # file_write.o
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

file_read:	file_read.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

file_lseek:	file_lseek.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

file_rdwr:	file_rdwr.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

eddi_cat:	eddi_cat.o
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
