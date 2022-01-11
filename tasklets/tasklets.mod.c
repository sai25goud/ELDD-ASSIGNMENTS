#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xeeab4c1e, "module_layout" },
	{ 0xc498609c, "device_destroy" },
	{ 0x37a0cba, "kfree" },
	{ 0xea3c74e, "tasklet_kill" },
	{ 0x3c03d27a, "cdev_del" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x7c038979, "class_destroy" },
	{ 0x20b4369f, "sysfs_remove_file_ns" },
	{ 0x2b68b15f, "kobject_put" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x2364c85a, "tasklet_init" },
	{ 0xd60e87c0, "kmem_cache_alloc_trace" },
	{ 0x6aa9e858, "kmalloc_caches" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xd5973871, "sysfs_create_file_ns" },
	{ 0x81515fc2, "kobject_create_and_add" },
	{ 0x9b3ee8b3, "kernel_kobj" },
	{ 0xba9cf391, "device_create" },
	{ 0xbd59df1c, "__class_create" },
	{ 0x44d7ad45, "cdev_add" },
	{ 0xdc74c97c, "cdev_init" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x9d2ab8ac, "__tasklet_schedule" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "B2BCB14FB5FB743613995CB");
