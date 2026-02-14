// clang-format off
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kprobes.h>
// clang-format on

static struct kprobe kp = {
    .symbol_name = "do_unlinkat",
};

static int handler_pre(struct kprobe* p, struct pt_regs* regs) {
    int* ptr = NULL;

    pr_info("Module: Hooked do_unlinkat. Someone is deleting a file...\n");

    pr_info("Module: Goodbye, kernel!\n");
    *ptr = 42;

    return 0;
}

static int __init kprobe_init(void) {
    kp.pre_handler = handler_pre;
    int ret = register_kprobe(&kp);
    if (ret < 0) {
        pr_err(
            "Module: Failed to register kprobe. Symbol 'do_unlinkat' might not "
            "exist or is inlined.\n");
        return ret;
    }

    pr_info(
        "Module: kprobe registered on 'do_unlinkat'. Run 'rm <file>' to "
        "crash.\n");
    return 0;
}

static void __exit kprobe_exit(void) {
    unregister_kprobe(&kp);
    pr_info("Module: kprobe unregistered\n");
}

module_init(kprobe_init);
module_exit(kprobe_exit);
MODULE_LICENSE("GPL");
