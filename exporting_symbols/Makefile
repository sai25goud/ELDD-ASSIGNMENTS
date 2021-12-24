PWD := $(shell pwd)
KERNEL_DIR = /lib/modules/$(shell uname -r)/build

obj-m := kern_sym.o kern_sym1.o


all:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean
