#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("sai kiran goud");
MODULE_DESCRIPTION("hello module");

static int __init hello_init(void)
{
     printk("HELLO TO ALL\n");

     return 0;
}

static void __exit hello_exit(void)
{
    printk("BYE TO ALL\n");
}

module_init(hello_init);
module_exit(hello_exit);

