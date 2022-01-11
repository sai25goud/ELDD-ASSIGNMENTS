#include <linux/init.h>           // Macros used to mark up functions e.g. __init __exit
#include <linux/module.h>         // Core header for loading LKMs into the kernel
#include <linux/device.h>         // Header to support the kernel Driver Model
#include <linux/kernel.h>         // Contains types, macros, functions for the kernel
#include <linux/fs.h>             // Header for the Linux file system support
#include <asm/uaccess.h>          // Required for the copy to user function
#include <linux/uaccess.h>   
#include <linux/types.h>
#include <asm/bitops.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("i am");

static int __init initialize(void)
{
   /* declare atomic variable */
   volatile unsigned long value=0x10;
   bool test_oldbit_value;
   
   printk(KERN_INFO "hello world\n");
   /* set bit 0 */
   set_bit(0,&value);
   printk(KERN_INFO "after setting bit 0 - value is 0x%lx\n",value);
   
   /* clear bit 0 */
   clear_bit(0,&value);
   printk(KERN_INFO "after clearing bit 0 - value is 0x%lx\n",value);
   
  /* change bit 4 */
   change_bit(8,&value);
   printk(KERN_INFO "after changing bit 8 - value is 0x%lx\n",value);
   
   /* set a bit and return old value */
   test_oldbit_value=test_and_set_bit(9,&value);
   printk(KERN_INFO "after test and set bit 9 - returned test_value is %d,modified value is 0x%lx\n",test_oldbit_value,value);
   
   /* clear a bit and return old value */
   test_oldbit_value=test_and_clear_bit(8,&value);
   printk(KERN_INFO "after test and clear bit 8 - returned test_value is %d,modified value is 0x%lx\n",test_oldbit_value,value);
   
   
   return 0;
}

static void __exit clean_exit(void)
{
   printk(KERN_INFO "Goodbye\n"); /* kernel print function */
}

/* kernel exit points */
module_init(initialize);
module_exit(clean_exit);
