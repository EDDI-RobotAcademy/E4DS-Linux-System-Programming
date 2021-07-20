PWD = $(shell pwd)
SRC = $(PWD)/src
INC = $(PWD)/include

FILE = $(SRC)/file
MAIN = $(SRC)/main

EDDI_CAT = $(MAIN)/eddi_cat
EDDI_CP = $(MAIN)/eddi_cp
EDDI_WC = $(MAIN)/eddi_wc
EDDI_TAR = $(MAIN)/eddi_tar
EDDI_TAR_FREE = $(MAIN)/eddi_tar_free

SUBDIRS = $(FILE)

all:	main
	$(shell rm -rf build)
	$(shell mkdir build)
	$(shell cp $(EDDI_CAT) ./build/)
	$(shell cp $(EDDI_CP) ./build/)
	$(shell cp $(EDDI_WC) ./build/)
	$(shell cp $(EDDI_TAR) ./build/)
	$(shell cp $(EDDI_TAR_FREE) ./build/)

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

