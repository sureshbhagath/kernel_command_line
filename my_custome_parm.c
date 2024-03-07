#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>
MODULE_LICENSE("Dual MIT/GPL");
// Define a variable to store the value of the new parameter
static int slave_address;
// Register the new kernel command-line parameter
module_param(slave_address, int, 0644);
MODULE_PARM_DESC(slave_address, "Temparature address parameter");
static int __init my_module_init(void) {
    printk(KERN_INFO "My Module: Initializing\n");
    // Access and use the value of the new parameter
    pr_info("This is my slave address from command line : 0x%x ",slave_address);
    return 0;
}
 
 

static void __exit my_module_exit(void) {
    printk(KERN_INFO "My Module: Exiting\n");
}
