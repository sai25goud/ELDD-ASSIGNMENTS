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
	{ 0xc1514a3b, "free_irq" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x3c03d27a, "cdev_del" },
	{ 0x7c038979, "class_destroy" },
	{ 0xc498609c, "device_destroy" },
	{ 0xfe990052, "gpio_free" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x259622f, "gpiod_to_irq" },
	{ 0x4e7f1ab5, "gpiod_direction_input" },
	{ 0xc3b06abc, "gpiod_direction_output_raw" },
	{ 0x47229b5c, "gpio_request" },
	{ 0xba9cf391, "device_create" },
	{ 0xbd59df1c, "__class_create" },
	{ 0x44d7ad45, "cdev_add" },
	{ 0xdc74c97c, "cdev_init" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x56470118, "__warn_printk" },
	{ 0x1dd3e24c, "gpiod_set_raw_value" },
	{ 0x1a81ff9c, "pv_ops" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc959d152, "__stack_chk_fail" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x9404f9d9, "gpiod_get_raw_value" },
	{ 0x425c9095, "gpio_to_desc" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "96F0DA15CC842AF0488CB54");
