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

TARGET = signal_test signal_test2 signal_test3 sig_ign_test sigkill_test goto_why goto_why2 goto_test setjmp_test setjmp_test2 setjmp_test3 sigalarm_test eddi_hangman
#TARGET += goto_problem

FILE_CONTROL_DIR = $(PWD)/../file

FILE_CONTROL_OBJS = $(shell find $(FILE_CONTROL_DIR) -name '*.o')
#MATH_TECH_OBJS = $(shell find $(MATH_TECH_DIR) -name '*.o')
#OGL_OBJS = $(shell find $(OGL_DIR) -name '*.o')
#RADAR_PRINCIPLES_OBJS = $(shell find $(RADAR_PRINCIPLES_DIR) -name '*.o')
#RADAR_SIGNAL_PROCESSING_OBJS = $(shell find $(RADAR_SIGNAL_PROCESSING_DIR) -name '*.o')

all:	$(TARGET)

signal_test:	signal_test.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

signal_test2:	signal_test2.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

signal_test3:	signal_test3.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

sig_ign_test:	sig_ign_test.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

sigkill_test:	sigkill_test.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

goto_why:	goto_why.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

goto_why2:	goto_why2.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

goto_test:	goto_test.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

setjmp_test:	setjmp_test.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

setjmp_test2:	setjmp_test2.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

setjmp_test3:	setjmp_test3.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

sigalarm_test:	sigalarm_test.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

eddi_hangman:	eddi_hangman.o
	@echo "$<"
	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

#goto_problem:	goto_problem.o
#	@echo "$<"
#	$(CC) -o $@ $< $(FILE_CONTROL_OBJS) $(LIBS)

.c.o:
	@echo "======================================="
	@echo "========= Compiling Main Prog ========="
	@echo "======================================="
	$(CC) $(DBG_FLAGS) -c $< -o $@ $(INC_DIRS)

clean:
	rm -rf *.o
	rm -rf $(TARGET)
