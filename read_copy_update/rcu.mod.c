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
	{ 0x9166fada, "strncpy" },
	{ 0xd60e87c0, "kmem_cache_alloc_trace" },
	{ 0x6aa9e858, "kmalloc_caches" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x1a81ff9c, "pv_ops" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x37a0cba, "kfree" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xc5850110, "printk" },
	{ 0x2d5f69b3, "rcu_read_unlock_strict" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "7394C024016867B4A742E2F");
