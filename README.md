# HelloKernel

A collection of Linux kernel programming exercises implemented as Loadable Kernel Modules (LKMs). The repository demonstrates fundamental kernel programming concepts, progressing from basic modules to character device registration.

## Exercises

### 01 - Hello Kernel Module

**Objective:** Create a basic Linux kernel module.

**Concepts covered:**

* Module initialization (`module_init`)
* Module cleanup (`module_exit`)
* Kernel logging with `printk`
* Module metadata (`MODULE_LICENSE`, `MODULE_AUTHOR`, `MODULE_DESCRIPTION`)

---

### 02 - Better Hello Kernel

**Objective:** Improve the basic kernel module.

**Concepts covered:**

* Cleaner module structure
* Module lifecycle
* Enhanced kernel logging
* Proper module organization

---

### 03 - GPIO Control & Module Parameters

**Objective:** Learn module parameters and experiment with GPIO access.

**Concepts covered:**

* Module parameters (`module_param`)
* Kernel command-line arguments
* Repeated kernel logging
* GPIO descriptor API (experimental code)
* Input/output GPIO configuration

**Example**

```bash
sudo insmod gpioctrl.ko param=5
dmesg
```

---

### 04 - Character Device Registration

**Objective:** Register a character device and implement basic file operations.

**Concepts covered:**

* Dynamic device number allocation
* Character device registration
* `struct file_operations`
* Device open and close callbacks
* Device cleanup during module removal

**Example**

```bash
sudo insmod files.ko
cat /proc/devices
sudo rmmod files
```

## Build

Inside each exercise directory:

```bash
make
```

## Requirements

* Linux kernel headers
* GCC
* GNU Make

## Author

Ahmed Hussein
