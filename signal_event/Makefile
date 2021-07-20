PWD = $(shell pwd)
SRC = $(PWD)/src
INC = $(PWD)/include

FILE = $(SRC)/file
MAIN = $(SRC)/main

SIGNAL_TEST = $(MAIN)/signal_test
SIGNAL_TEST2 = $(MAIN)/signal_test2
SIGNAL_TEST3 = $(MAIN)/signal_test3
SIG_IGN_TEST = $(MAIN)/sig_ign_test
SIGKILL_TEST = $(MAIN)/sigkill_test
GOTO_WHY = $(MAIN)/goto_why
GOTO_WHY2 = $(MAIN)/goto_why2
GOTO_TEST = $(MAIN)/goto_test
SETJMP_TEST = $(MAIN)/setjmp_test
SETJMP_TEST2 = $(MAIN)/setjmp_test2
SETJMP_TEST3 = $(MAIN)/setjmp_test3
SIGALARM_TEST = $(MAIN)/sigalarm_test
EDDI_HANGMAN = $(MAIN)/eddi_hangman

#GOTO_PROBLEM = $(MAIN)/goto_problem

SUBDIRS = $(FILE)

all:	main
	$(shell rm -rf build)
	$(shell mkdir build)
	$(shell cp $(SIGNAL_TEST) ./build/)
	$(shell cp $(SIGNAL_TEST2) ./build/)
	$(shell cp $(SIGNAL_TEST3) ./build/)
	$(shell cp $(SIG_IGN_TEST) ./build/)
	$(shell cp $(SIGKILL_TEST) ./build/)
	$(shell cp $(GOTO_WHY) ./build/)
	$(shell cp $(GOTO_WHY2) ./build/)
	$(shell cp $(GOTO_TEST) ./build/)
	$(shell cp $(SETJMP_TEST) ./build/)
	$(shell cp $(SETJMP_TEST2) ./build/)
	$(shell cp $(SETJMP_TEST3) ./build/)
	$(shell cp $(SIGALARM_TEST) ./build/)
	$(shell cp $(EDDI_HANGMAN) ./build/)
#	$(shell cp $(GOTO_PROBLEM) ./build/)

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

