#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("sai kiran goud");
MODULE_DESCRIPTION("array kernel module");

static int arr[5]={0};
int count=5;
module_param_array(arr,int,&count,S_IRUGO);

static int __init array_init(void)
{
	size_t i=0;
	while(i<count)
	{
		printk("array values are %d\n",arr[i]);
		i++;
	}
    return 0;
}

static void __exit array_exit(void)
{
	printk( "\n GOODBYE\n");
}

module_init(array_init);
module_exit(array_exit);
