#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/iversion.h>

static struct dentry *testfs_mount(struct file_system_type *fs_type,
		       int flags, const char *dev_name,
		       void *data)
{
	printk(KERN_INFO "testfs Mount succesful.\n");
	return 0;
}

static void testfs_kill_sb(struct super_block *sb)
{
	printk(KERN_INFO "testfs Unmount succesful.\n");
	return;
}

static struct file_system_type vfat_fs_type = {
	.owner		= THIS_MODULE,
	.name		= "testfs",
	.mount		= testfs_mount,
	.kill_sb	= testfs_kill_sb,
	.fs_flags	= FS_REQUIRES_DEV,
};

MODULE_ALIAS_FS("testfs");

static int __init init_vfat_fs(void)
{
	return register_filesystem(&vfat_fs_type);
}

static void __exit exit_vfat_fs(void)
{
	unregister_filesystem(&vfat_fs_type);
}

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Testfs A dummy filesystem");
MODULE_AUTHOR("You Know Who");

module_init(init_vfat_fs)
module_exit(exit_vfat_fs)
