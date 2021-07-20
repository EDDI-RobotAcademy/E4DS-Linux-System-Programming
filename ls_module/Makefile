PWD = $(shell pwd)
SRC = $(PWD)/src
INC = $(PWD)/include

FILE = $(SRC)/file
MAIN = $(SRC)/main

LS_DIR = $(MAIN)/ls_dir
LS_OPTION = $(MAIN)/ls_option
LS_A = $(MAIN)/ls_a
LS_ADV_OPTION = $(MAIN)/ls_adv_option
LS_STAT = $(MAIN)/ls_stat
LS_ADV_STAT = $(MAIN)/ls_adv_stat
LS_RECURSIVE = $(MAIN)/ls_recursive

SUBDIRS = $(FILE)

all:	main
	$(shell rm -rf build)
	$(shell mkdir build)
	$(shell cp $(LS_DIR) ./build/)
	$(shell cp $(LS_OPTION) ./build/)
	$(shell cp $(LS_A) ./build/)
	$(shell cp $(LS_ADV_OPTION) ./build/)
	$(shell cp $(LS_STAT) ./build/)
	$(shell cp $(LS_ADV_STAT) ./build/)
	$(shell cp $(LS_RECURSIVE) ./build/)

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

