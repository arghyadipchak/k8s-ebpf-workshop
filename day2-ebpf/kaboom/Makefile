MODULE_NAME := unlink
KDIR := /lib/modules/$(shell uname -r)/build

obj-m += $(MODULE_NAME).o

.PHONY: all build clean load unload reload verify logs
all: build

build:
	make -C $(KDIR) M=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean

load:
	sudo insmod $(MODULE_NAME).ko

unload:
	sudo rmmod $(MODULE_NAME)

reload: unload load

verify:
	lsmod | grep $(MODULE_NAME)

logs:
	sudo dmesg | tail -20
