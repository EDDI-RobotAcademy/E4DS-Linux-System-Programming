PWD = $(shell pwd)
SRC = $(PWD)/src
INC = $(PWD)/include

FILE = $(SRC)/file
MAIN = $(SRC)/main

WAIT_TEST1 = $(MAIN)/wait_test1
WAIT_TEST2 = $(MAIN)/wait_test2
WAIT_TEST3 = $(MAIN)/wait_test3
WAIT_TEST4 = $(MAIN)/wait_test4
SYNC_WAIT = $(MAIN)/sync_wait
ASYNC_WAIT = $(MAIN)/async_wait

SUBDIRS = $(FILE)

all:	main
	$(shell rm -rf build)
	$(shell mkdir build)
	$(shell cp $(WAIT_TEST1) ./build/)
	$(shell cp $(WAIT_TEST2) ./build/)
	$(shell cp $(WAIT_TEST3) ./build/)
	$(shell cp $(WAIT_TEST4) ./build/)
	$(shell cp $(SYNC_WAIT) ./build/)
	$(shell cp $(ASYNC_WAIT) ./build/)

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

