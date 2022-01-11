#include <linux/init.h>           // Macros used to mark up functions e.g. __init __exit
#include <linux/module.h>         // Core header for loading LKMs into the kernel
#include <linux/device.h>         // Header to support the kernel Driver Model
#include <linux/kernel.h>         // Contains types, macros, functions for the kernel
#include <linux/fs.h>             // Header for the Linux file system support
#include <asm/uaccess.h>          // Required for the copy to user function
#include <linux/uaccess.h>   
#include <linux/types.h>
#include <asm/atomic.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("i am");

static int __init initialize(void)
{
   /* declare atomic variable */
   atomic_t atomic_variable;
   bool test_variable;
   int value;
   
   printk(KERN_INFO "hello world\n");
   /* a few atomic variable functions */
   atomic_set(&atomic_variable,10);
   printk(KERN_INFO "atomic_set value is %d\n",atomic_read((const atomic_t *) &atomic_variable));
   
   atomic_add(2,&atomic_variable);
   printk(KERN_INFO "atomic_add value is %d\n",atomic_read((const atomic_t *) &atomic_variable));
   
   atomic_sub(1,&atomic_variable);
   printk(KERN_INFO "atomic_sub value is %d\n",atomic_read((const atomic_t *) &atomic_variable));
   
   atomic_inc(&atomic_variable);
   printk(KERN_INFO "atomic_inc value is %d\n",atomic_read((const atomic_t *) &atomic_variable));
   
   atomic_dec(&atomic_variable);
   printk(KERN_INFO "atomic_dec value is %d\n",atomic_read((const atomic_t *) &atomic_variable));
   
   atomic_sub_and_test(3,&atomic_variable);
   printk(KERN_INFO "atomic_sub_and_test value is %d\n",atomic_read((const atomic_t *) &atomic_variable));
   
   atomic_dec_and_test(&atomic_variable);
   printk(KERN_INFO "atomic_dec_and_test value is %d\n",atomic_read((const atomic_t *) &atomic_variable));
   
   atomic_inc_and_test(&atomic_variable);
   printk(KERN_INFO "atomic_inc_and_test value is %d\n",atomic_read((const atomic_t *) &atomic_variable));
   
   /* add value atomically to variable and return true if added value is negative */
   test_variable=atomic_add_negative(4,&atomic_variable);
   printk(KERN_INFO "atomic_add_negative return value is %d\n",test_variable);
   printk(KERN_INFO "atomic_add_negative atomic variable value is %d\n",atomic_read((const atomic_t *) &atomic_variable));
   
   value=atomic_add_return(8,&atomic_variable);
   printk(KERN_INFO "atomic_add_return value is %d\n",value);
   return 0;
}

static void __exit clean_exit(void)
{
   printk(KERN_INFO "Goodbye\n"); /* kernel print function */
}

/* kernel exit points */
module_init(initialize);
module_exit(clean_exit);
