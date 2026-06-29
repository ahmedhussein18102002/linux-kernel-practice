#include <linux/module.h>
#include <linux/init.h>
#include <linux/gpio/consumer.h>
#include <linux/moduleparam.h>
#include <linux/fs.h>
#include <linux/cdev.h>

//int number = 0 ;
//int major_number;
//module_param(number, int, 0664);
dev_t device_number ;
static int driver_open( struct inode *device_file, struct file *instance){
	printk("%s dev_nr - open was called!\n",__FUNCTION__);
	return 0;
}
static int driver_close( struct inode *device_file, struct file *instance){
	printk("%s dev_nr - close was called!\n",__FUNCTION__);
	return 0;
}

struct file_operations fops =
{
	.owner   = THIS_MODULE,
	.open    = driver_open,
	.release = driver_close 

};

static int __init files_driver_init(void){
	int retval;
	//major_number = number;
	//retval = register_chrdev(major_number, "mytest_driver", &fops);
	retval = alloc_chrdev_region(&device_number, 0, 1, "mytest_driver");
	if(retval == 0){
		printk("%s retval=0 - registered Device Major: %d, Minor: %d\n",__FUNCTION__, MAJOR(device_number), MINOR(device_number));
 
	}else{
		printk("Couldn't register device number!\n");
		return -1;
	}
	printk("hello kernel\n");
	return 0;
}

static void __exit my_exit(void)
{
    //unregister_chrdev(major_number, "mytest_driver");
    unregister_chrdev_region(device_number , 1); 
    printk("Ahmed, Goodbye Kernel! %d\n", MAJOR(device_number));
}
module_init(files_driver_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ahmed Hussein");
MODULE_DESCRIPTION("SIMPLE HELLO WORLD LINUX KERNEL MODULE");


