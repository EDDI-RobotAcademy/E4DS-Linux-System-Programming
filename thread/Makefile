PWD = $(shell pwd)
SRC = $(PWD)/src
INC = $(PWD)/include

FILE = $(SRC)/file
IPC = $(SRC)/ipc
MAIN = $(SRC)/main

PTHREAD_TEST = $(MAIN)/pthread_test
PTHREAD_TEST2 = $(MAIN)/pthread_test2
PTHREAD_TEST3 = $(MAIN)/pthread_test3
PTHREAD_TEST4 = $(MAIN)/pthread_test4
NONTHREAD_INTEGRAL = $(MAIN)/nonthread_integral
PTHREAD_INTEGRAL = $(MAIN)/pthread_integral
NONTHREAD_INTEGRAL_FIX = $(MAIN)/nonthread_integral_fix
PTHREAD_INTEGRAL_FIX = $(MAIN)/pthread_integral_fix

SUBDIRS = $(FILE) $(IPC)

all:	main
	$(shell rm -rf build)
	$(shell mkdir build)
	$(shell cp $(PTHREAD_TEST) ./build/)
	$(shell cp $(PTHREAD_TEST2) ./build/)
	$(shell cp $(PTHREAD_TEST3) ./build/)
	$(shell cp $(PTHREAD_TEST4) ./build/)
	$(shell cp $(NONTHREAD_INTEGRAL) ./build/)
	$(shell cp $(PTHREAD_INTEGRAL_FIX) ./build/)
	$(shell cp $(NONTHREAD_INTEGRAL_FIX) ./build/)
	$(shell cp $(PTHREAD_INTEGRAL) ./build/)

main:	_all
	$(MAKE) -C $(MAIN)
    
_all:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
    done

clean:  mclear
	$(shell rm -rf build)

mclear:	_clean
	$(MAKE) -C $(MAIN) clean

_clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
    done

