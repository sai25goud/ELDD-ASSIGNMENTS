#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h> // required for various structures related to files liked fops.
#include <asm/uaccess.h> // required for copy_from and copy_to user functions
#include <linux/semaphore.h>
#include <linux/cdev.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/wait.h>
#include <linux/time.h>

wait_queue_head_t queue;
static int Major;
char flag='n';
struct task_struct *task;

struct char_arr {
    char array[100];
    struct rw_semaphore rwsem;
}char_arr;

int open(struct inode *inode, struct file *filp)
{
   
    printk(KERN_INFO "Inside open \n");
    task = current;

    return 0;
}

int release(struct inode *inode, struct file *filp) {
    printk (KERN_INFO "Inside close \n");
    return 0;
}

ssize_t read(struct file *filp, char *buff, size_t count, loff_t *offp) {
    unsigned long ret;
    down_read(&char_arr.rwsem);
    printk("Inside read \n");
    ret = copy_to_user(buff, char_arr.array, count);
    wait_event_timeout(queue,flag!='n',30*HZ);
    up_read(&char_arr.rwsem);
    return ret;
}

ssize_t write(struct file *filp, const char *buff, size_t count, loff_t *offp) {   
    unsigned long ret;
    down_write(&char_arr.rwsem);
    printk(KERN_INFO "Inside write \n");
    ret =    copy_from_user(char_arr.array, buff, count);
    up_write(&char_arr.rwsem);
    return ret;
}


struct file_operations fops = {
    read:        read,
    write:        write,
    open:         open,
    release:    release
};


struct cdev *kernel_cdev;


int char_arr_init (void) {
    int ret;
    dev_t dev_no,dev;

    kernel_cdev = cdev_alloc();   
     kernel_cdev->ops = &fops;
    kernel_cdev->owner = THIS_MODULE;
    printk (" Inside init module\n");
     ret = alloc_chrdev_region( &dev_no , 0, 1,"chr_arr_dev");
    if (ret < 0) {
        printk("Major number allocation is failed\n");
        return ret;   
    }
   
    Major = MAJOR(dev_no);
    dev = MKDEV(Major,0);

    printk (" The major number for your device is %d\n", Major);
    ret = cdev_add( kernel_cdev,dev,1);
    if(ret < 0 )
    {
    printk(KERN_INFO "Unable to allocate cdev");
    return ret;
    }
    init_rwsem(&char_arr.rwsem);
    init_waitqueue_head(&queue);
   
    return 0;
}

void char_arr_cleanup(void) {
    printk(KERN_INFO " Inside cleanup_module\n");
    cdev_del(kernel_cdev);
    unregister_chrdev_region(Major, 1);
}

MODULE_LICENSE("GPL"); 
MODULE_AUTHOR("sai kiran goud");
  
module_init(char_arr_init);
module_exit(char_arr_cleanup);
