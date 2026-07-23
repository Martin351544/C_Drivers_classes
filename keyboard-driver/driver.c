#include<linux/module.h>
#include<linux/init.h>
#include<linux/input.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Martin");
MODULE_DESCRIPTION("simple vertual keeb driver");

static struct input_dev *keyboard;

static int __init keyboard_init(void) {
	printk(KERN_INFO "Keyboard device driver loaded\n");

	keyboard = input_allocate_device();

	if (!keyboard)
		return -ENOMEM;

	keyboard->name = "Virtual keyboard";
	keyboard->phys = "driver/input0";

	keyboard->id.bustype = BUS_USB;
	keyboard->id.vendor = 0x1234;
	keyboard->id.product = 1;
	keyboard->id.version = 1;

	// tell linux this device can generate keys
	__set_bit(EV_KEY, keyboard->evbit);
	__set_bit(KEY_A, keyboard->keybit);

	if (input_register_device(keyboard)) {
		printk(KERN_ERR "failed to register keyboard\n");
		input_free_device(keyboard);
		return -EINVAL;
	}

	printk(KERN_INFO "VKeyboard registerd\n");
	return 0;	
}

static void __exit keyboard_exit(void) {
	printk(KERN_INFO "Keyboard driver unloaded\n");

	input_unregister_device(keyboard);
}

module_init(keyboard_init);
module_exit(keyboard_exit);



