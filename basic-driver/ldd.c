#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Martin");
MODULE_DESCRIPTION("first dynamically loadable kernel module");

static int main_module_init(void) {
	printk("Hello World! (from kernel module)");
	return 0;
}

static void main_module_exit(void) {
	printk("Goodbye (from kernel module)");
}

moudle_init(main_module_init);
module_exit(main_module_exit);
