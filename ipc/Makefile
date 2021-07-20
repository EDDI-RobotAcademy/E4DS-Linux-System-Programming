PWD = $(shell pwd)
SRC = $(PWD)/src
INC = $(PWD)/include

FILE = $(SRC)/file
IPC = $(SRC)/ipc
MAIN = $(SRC)/main

MQ_CLIENT = $(MAIN)/mq_client
MQ_SERVER = $(MAIN)/mq_server
SEMAPHORE_TEST = $(MAIN)/semaphore_test
SHM_SEND = $(MAIN)/shm_send
SHM_RECV = $(MAIN)/shm_recv
NON_SEM = $(MAIN)/non_sem
SEM = $(MAIN)/sem

SUBDIRS = $(FILE) $(IPC)

all:	main
	$(shell rm -rf build)
	$(shell mkdir build)
	$(shell cp $(MQ_CLIENT) ./build/)
	$(shell cp $(MQ_SERVER) ./build/)
	$(shell cp $(SEMAPHORE_TEST) ./build/)
	$(shell cp $(SHM_SEND) ./build/)
	$(shell cp $(SHM_RECV) ./build/)
	$(shell cp $(NON_SEM) ./build/)
	$(shell cp $(SEM) ./build/)

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

