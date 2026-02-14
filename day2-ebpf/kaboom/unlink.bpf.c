#define BPF_NO_GLOBAL_DATA

// clang-format off
#include <vmlinux.h>
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>
#include <bpf/bpf_core_read.h>
// clang-format on

char LICENSE[] SEC("license") = "Dual BSD/GPL";

SEC("kprobe/do_unlinkat")
int BPF_KPROBE(probe_do_unlinkat_entry, int dfd, struct filename* f) {
    int* ptr = 0;

    bpf_printk("Loaded eBPF program at do_unlinkat\n");

    *ptr = 42;

    return 0;
}
