#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/moduleparam.h>
#include "my_add.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("i am");
MODULE_DESCRIPTION("modprobe module");

static int one=10;
static int two=20;

static int __init add_init(void)
{
       printk(KERN_ALERT "\n we are going to add \n");
       printk(KERN_ALERT "\n average of two numbers is:%d \n",my_add(one,two)/2); 
       return 0;
}

static void __exit add_exit(void)
{
      printk(KERN_ALERT "\n we are leaving\n");
}

module_init(add_init);
module_exit(add_exit);                  

