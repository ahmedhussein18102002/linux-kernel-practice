#include <linux/module.h>
#include <linux/init.h>
#include <linux/gpio/consumer.h>
#include <linux/moduleparam.h>
/*
static struct gpio_desc *led, *button;

#define IO_LED 21
#define IO_BUTTON 20

#define IO_OFFSET 512
*/

int param = 0 ;
module_param(param, int, 0664);

static int __init my_init(void){
	/*
	int status;
	printk("Ahmed, Hello Kernel!\n");
	led = gpio_to_desc(IO_LED + IO_OFFSET);
	if(!led){
		printk("gpioctrl- Error getting pin %d\n", IO_LED);
		return -ENODEV;
	}
	button = gpio_to_desc(IO_BUTTON + IO_OFFSET);
	if(!button){
		printk("gpioctrl- Error getting pin %d\n", IO_BUTTON);
		return -ENODEV;
	}
	status = gpiod_direction_output(led, 0);
	if(status){
		printk("gpioctrl- Error setting pin %d to output\n", IO_BUTTON);
		return status;
	}
	status = gpiod_direction_input(button);
	if(status){
		printk("gpioctrl- Error setting pin %d to input\n", IO_BUTTON);
		return status;
	}
	gpiod_set_value(led, 1);
	
	printk("Button is %spressed\n",(gpiod_get_value(button)?"":"not"));
	*/
	int i;
	for( i = 0; i < param ; i++){
		printk("Ahmed, Kernel Module %d\n", i);
	}
	printk("Ahmed Kernel Bymassy\n");
	return 0;
}

static void __exit my_exit(void){

	printk("Ahmed, Goodbye Kernel! %d \n", param);
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ahmed Hussein");
MODULE_DESCRIPTION("SIMPLE HELLO WORLD LINUX KERNEL MODULE");


