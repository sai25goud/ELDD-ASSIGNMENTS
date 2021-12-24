#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("i am");
MODULE_DESCRIPTION("modprobe module");

int my_add(int a,int b)
{
     return (a+b);
}

EXPORT_SYMBOL(my_add);

static int __init hello_init(void)
{
       printk(KERN_ALERT "\n HELLO TO ALL\n");
       return 0;
}

static void __exit hello_exit(void)
{
      printk(KERN_ALERT "\n BYE TO ALL\n");
}

module_init(hello_init);
module_exit(hello_exit);                  

