#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("i am");
MODULE_DESCRIPTION("parameter passing module");

static char* charvar = "module";
static int intvar = 10;

module_param(charvar,charp,S_IRUGO);
module_param(intvar,int,S_IRUGO);

static int __init param_init(void)
{
	printk(KERN_ALERT "\n we are in init function\n");
	printk(KERN_ALERT "\n the value of charvar is %s\n",charvar);
	return 0;
}

static void __exit param_exit(void)
{
	printk(KERN_ALERT "\n GOODBYE\n");
}

module_init(param_init);
module_exit(param_exit);
