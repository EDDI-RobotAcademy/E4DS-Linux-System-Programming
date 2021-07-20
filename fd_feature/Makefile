PWD = $(shell pwd)
SRC = $(PWD)/src
INC = $(PWD)/include

FILE = $(SRC)/file
MAIN = $(SRC)/main

INDEPENDENT_FD = $(MAIN)/independent_fd
DUP_TEST1 = $(MAIN)/dup_test1
DUP_TEST2 = $(MAIN)/dup_test2
EDDI_TAIL = $(MAIN)/eddi_tail
EDDI_PIPE = $(MAIN)/eddi_pipe
EDDI_ADV_PIPE = $(MAIN)/eddi_adv_pipe

SUBDIRS = $(FILE)

all:	main
	$(shell rm -rf build)
	$(shell mkdir build)
	$(shell ls >> ./build/test.txt)
	$(shell cp $(INDEPENDENT_FD) ./build/)
	$(shell cp $(DUP_TEST1) ./build/)
	$(shell cp $(DUP_TEST2) ./build/)
	$(shell cp $(EDDI_TAIL) ./build/)
	$(shell cp $(EDDI_PIPE) ./build/)
	$(shell cp $(EDDI_ADV_PIPE) ./build/)

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

