#Makefile for randnum generator .

obj-m := random.o

KDIR ?= /lib/modules/$(shell uname -r)/build
PWD = $(shell pwd)

all :
	make -C $(KDIR) M=$(PWD) modules

clean:
	rm -rf Module.symvers  modules.order *.o *~  *.mod.c .*.cmd .tmp_versions
