#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include "my_add.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("i am");
MODULE_DESCRIPTION("exporting symbols module");

static int one=1;
static int two=2;

static int __init add_init(void)
{
	printk(KERN_ALERT "\n we wre going to add\n");
	printk(KERN_ALERT "\n add result is:%d\n",my_add(one,two));
        return 0;
}

static void __exit add_exit(void)
{
	printk(KERN_ALERT "\n we are leaving\n");
}

module_init(add_init);
module_exit(add_exit);


