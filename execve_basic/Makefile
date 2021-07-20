PWD = $(shell pwd)
SRC = $(PWD)/src
INC = $(PWD)/include

FILE = $(SRC)/file
MAIN = $(SRC)/main

EXECVE_TEST = $(MAIN)/execve_test
EXECVE_TEST2 = $(MAIN)/execve_test2
EXECVE_HOWTO = $(MAIN)/execve_howto
NEWPGM = $(MAIN)/newpgm
EXECVE_HOWTO2 = $(MAIN)/execve_howto2
NEWPGM2 = $(MAIN)/newpgm2
EXECVE_HOWTO3 = $(MAIN)/execve_howto3
EXECVE_HOWTO4 = $(MAIN)/execve_howto4
MULTI_PROCESS = $(MAIN)/multi_process
MULTI_PROCESS2 = $(MAIN)/multi_process2
DAEMON_HOWTO = $(MAIN)/daemon_howto

SUBDIRS = $(FILE)

all:	main
	$(shell rm -rf build)
	$(shell mkdir build)
	$(shell cp $(EXECVE_TEST) ./build/)
	$(shell cp $(EXECVE_TEST2) ./build/)
	$(shell cp $(EXECVE_HOWTO) ./build/)
	$(shell cp $(NEWPGM) ./build/)
	$(shell cp $(EXECVE_HOWTO2) ./build/)
	$(shell cp $(NEWPGM2) ./build/)
	$(shell cp $(EXECVE_HOWTO3) ./build/)
	$(shell cp $(EXECVE_HOWTO4) ./build/)
	$(shell cp $(MULTI_PROCESS) ./build/)
	$(shell cp $(MULTI_PROCESS2) ./build/)
	$(shell cp $(DAEMON_HOWTO) ./build/)

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

