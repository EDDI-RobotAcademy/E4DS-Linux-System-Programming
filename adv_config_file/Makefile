PWD = $(shell pwd)
SRC = $(PWD)/src
INC = $(PWD)/include

FILE = $(SRC)/file
MAIN = $(SRC)/main

FILE_WRITE = $(MAIN)/file_write
FILE_READ = $(MAIN)/file_read
FILE_LSEEK = $(MAIN)/file_lseek
FILE_RDWR = $(MAIN)/file_rdwr
EDDI_CAT = $(MAIN)/eddi_cat

SUBDIRS = $(FILE)

all:	main
	$(shell rm -rf build)
	$(shell mkdir build)
	$(shell cp $(FILE_WRITE) ./build/)
	$(shell cp $(FILE_READ) ./build/)
	$(shell cp $(FILE_LSEEK) ./build/)
	$(shell cp $(FILE_RDWR) ./build/)
	$(shell cp $(EDDI_CAT) ./build/)

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

