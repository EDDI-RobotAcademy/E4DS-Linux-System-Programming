PWD = $(shell pwd)
SRC = $(PWD)/src
INC = $(PWD)/include

FILE = $(SRC)/file
MAIN = $(SRC)/main

FORK_TEST = $(MAIN)/fork_test
PARENT_CHILD = $(MAIN)/parent_child
CHILD_TASK_ID = $(MAIN)/child_task_id
MULTI_TASKING1 = $(MAIN)/multi_tasking1
MULTI_TASKING2 = $(MAIN)/multi_tasking2
PS_TEST1 = $(MAIN)/ps_test1
PS_TEST2 = $(MAIN)/ps_test2
COW_TEST1 = $(MAIN)/cow_test1
COW_TEST2 = $(MAIN)/cow_test2
PROCESS_COMM_TEST = $(MAIN)/process_comm_test

SUBDIRS = $(FILE)

all:	main
	$(shell rm -rf build)
	$(shell mkdir build)
	$(shell cp $(FORK_TEST) ./build/)
	$(shell cp $(PARENT_CHILD) ./build/)
	$(shell cp $(CHILD_TASK_ID) ./build/)
	$(shell cp $(MULTI_TASKING1) ./build/)
	$(shell cp $(MULTI_TASKING2) ./build/)
	$(shell cp $(PS_TEST1) ./build/)
	$(shell cp $(PS_TEST2) ./build/)
	$(shell cp $(COW_TEST1) ./build/)
	$(shell cp $(COW_TEST2) ./build/)
	$(shell cp $(PROCESS_COMM_TEST) ./build/)

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

