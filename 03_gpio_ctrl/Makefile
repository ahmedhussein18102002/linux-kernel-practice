obj-m += gpioctrl.o

all: 
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules CC=gcc-12
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
