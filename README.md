# Kernel command line parameter to your own driver
This Program is about getting the kernel command line parameter from command line txt file to my own driver and printiing it out in kernel log (dmesg)

I have done it using Raspberry PI with my Two days of effort researching it and refering some documents 
https://www.kernel.org/doc/html/v4.14/admin-guide/kernel-parameters.html


After Refering this documents i got to know about this point 
" Parameters for modules which are built into the kernel need to be specified on the kernel command line. modprobe looks through the kernel command line (/proc/cmdline) and collects module parameters when it loads a module, so the kernel command line can be used for loadable modules too. "

# Add these two line to your driver
module_param(my_custom parm, int, 0644);
MODULE_PARM_DESC(my_custom_parm, "My custom parameter is ");
# Then after succesfull compilation 

Do modprobe over insmod

# I.E
> modinfo my_file.ko
modinfo temp1 


filename:       /lib/modules/6.1.0-rpi7-rpi-v8/temp1.ko

license:        Dual MIT/GPL

description:    Kernel driver for the DHT2x temperature & humidity sensor

author:         Suresh Bhagath 

srcversion:     8CFFEA679FCEE38225EAE32

alias:          of:N*T*CSURESH,dht2xC*

alias:          of:N*T*CSURESH,dht2x

depends:        

name:           temp1

vermagic:       6.1.0-rpi7-rpi-v8 SMP preempt mod_unload modversions aarch64

parm:           slave_address:Temparature address parameter (int)


> sudo cp my_file.ko /lib/modules/`uname -r`/drivers
> sudo depmod -a
> cat /lib/modules/6.1.0-rpi7-rpi-v8/modules.dep | grep temp1
temp1.ko:

> sudo modprobe my_file

