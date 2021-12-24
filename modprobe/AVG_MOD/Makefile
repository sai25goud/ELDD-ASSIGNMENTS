PWD := $(shell pwd)
KERNEL_DIR = /lib/modules/$(shell uname -r)/build/

obj-m := ../ADD_MOD/add_mod.o avg_mod.o

default:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules

install:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) install_modules
	depmod -a

clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean
	rm -rf /lib/modules/$(shell uname -r)/extra/*

