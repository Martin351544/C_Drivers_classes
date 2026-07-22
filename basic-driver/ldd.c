#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Martin");
MODULE_DESCRIPTION("First dynamically loadable kernel module");

static int main_module_init(void) {
	printk(KERN_INFO"Hello world! (from kernel module)");
	return 0;
}

static void main_module_exit(void) {
	printk(KERN_INFO "Good bye! (from kernel module)");
}

module_init(main_module_init);
module_exit(main_module_exit);
