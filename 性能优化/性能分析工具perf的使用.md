
# Perf 的使用

- [Perf 的使用](#perf-的使用)
  - [安装](#安装)
  - [使用](#使用)
    - [子命令：list](#子命令list)
      - [软件预定义事件列表](#软件预定义事件列表)
      - [strace事件](#strace事件)
    - [子命令：stat](#子命令stat)
    - [子命令：top](#子命令top)
    - [子命令：record](#子命令record)
    - [子命令：report](#子命令report)
    - [子命令：bench](#子命令bench)

Perf 是用于基于linux的操作系统的简单但功能强大的性能监视工具。

- 用于跟踪或计数硬件和软件事件
- 提供了许多子命令，并且能够对整个系统进行统计分析

## 安装

默认情况下，Perf 软件包在`Ubuntu 20.04`默认存储库中不可用。

可以使用以下命令进行安装：

```shell
apt-get install linux-tools-$(uname -r) linux-tools-generic -y
```

## 使用

安装完成后，可以使用以下命令验证Perf的安装版本：

```shell
perf -v
```

显示帮助信息：

```shell
perf --help
```

### 子命令：list

#### 软件预定义事件列表

```shell
perf list sw

# 显示信息如下：
# List of pre-defined events (to be used in -e):
# 
#   alignment-faults                                   [Software event]
#   bpf-output                                         [Software event]
#   context-switches OR cs                             [Software event]
#   cpu-clock                                          [Software event]
#   cpu-migrations OR migrations                       [Software event]
#   dummy                                              [Software event]
#   emulation-faults                                   [Software event]
#   major-faults                                       [Software event]
#   minor-faults                                       [Software event]
#   page-faults OR faults                              [Software event]
#   task-clock                                         [Software event]
# 
#   duration_time                                      [Tool event]
# 
# (END)
```

#### strace事件

```shell
perf list stat

# 显示信息如下：
# List of pre-defined events (to be used in -e):
# 
# 
#   cstate_core/c3-residency/                          [Kernel PMU event]
#   cstate_core/c6-residency/                          [Kernel PMU event]
#   cstate_core/c7-residency/                          [Kernel PMU event]
#   cstate_pkg/c10-residency/                          [Kernel PMU event]
#   cstate_pkg/c2-residency/                           [Kernel PMU event]
#   cstate_pkg/c3-residency/                           [Kernel PMU event]
#   cstate_pkg/c6-residency/                           [Kernel PMU event]
#   cstate_pkg/c7-residency/                           [Kernel PMU event]
#   cstate_pkg/c8-residency/                           [Kernel PMU event]
#   cstate_pkg/c9-residency/                           [Kernel PMU event]
# 
# (END)
```

### 子命令：stat

用于获取执行程序的性能统计信息。

```shell
perf stat free -m

# 显示信息如下：
#               total        used        free      shared  buff/cache   available
# Mem:          31826        3074       24996          10        3755       28287
# Swap:          2047           0        2047
# 
#  Performance counter stats for 'free -m':
# 
#               1.01 msec task-clock                #    0.663 CPUs utilized
#                  1      context-switches          #    0.994 K/sec
#                  0      cpu-migrations            #    0.000 K/sec
#                152      page-faults               #    0.151 M/sec
#          3,044,958      cycles                    #    3.027 GHz                      (14.71%)
#          3,032,906      instructions              #    1.00  insn per cycle
#            601,673      branches                  #  598.188 M/sec
#             22,519      branch-misses             #    3.74% of all branches          (85.29%)
# 
#        0.001516515 seconds time elapsed
# 
#        0.001330000 seconds user
#        0.000000000 seconds sys
```

### 子命令：top

实时显示性能计数器概要文件。

```shell
perf top -a  # 查看所有已知事件类型

# 显示信息如下：
# Samples: 4K of event 'cycles', 4000 Hz, Event count (approx.): 1150561101 lost: 0/0 drop: 0/0
# Overhead  Shared Object                Symbol
#    6.82%  perf                         [.] rb_next
#    6.05%  perf                         [.] __symbols__insert
#    4.95%  [kernel]                     [k] module_get_kallsym
#    3.18%  perf                         [.] d_print_comp_inner
#    3.14%  perf                         [.] map__process_kallsym_symbol
#    2.76%  [unknown]                    [.] 0000000000000000
#    2.68%  [kernel]                     [k] kallsyms_expand_symbol.constprop.0
#    2.53%  libc-2.31.so                 [.] __libc_calloc
#    2.19%  perf                         [.] rust_demangle_callback
#    1.88%  perf                         [.] kallsyms__parse
#    1.87%  [kernel]                     [k] number
#    1.76%  [kernel]                     [k] vsnprintf
#    1.61%  [kernel]                     [k] memcpy_erms
#    1.58%  [kernel]                     [k] format_decode
#    1.55%  perf                         [.] rb_insert_color
#    1.46%  [kernel]                     [k] string_nocheck
#    1.37%  libc-2.31.so                 [.] _int_malloc
#    1.26%  perf                         [.] d_print_comp
#    1.13%  perf                         [.] d_count_templates_scopes
#    0.92%  libc-2.31.so                 [.] __strcmp_avx2
#    0.76%  perf                         [.] maps__split_kallsyms
#    0.74%  perf                         [.] dso__load_sym
#    0.73%  libc-2.31.so                 [.] _int_free
#    0.66%  perf                         [.] d_name
#    0.66%  libc-2.31.so                 [.] sysmalloc
#    0.65%  [kernel]                     [k] native_irq_return_iret
#    0.58%  perf                         [.] cplus_demangle_print_callback
#    0.54%  perf                         [.] symbol__new
#    0.48%  perf                         [.] dso__find_symbol
#    0.47%  libelf-0.176.so              [.] gelf_getsym
#    0.46%  perf                         [.] d_demangle_callback
#    0.45%  perf                         [.] d_make_comp
#    0.44%  libc-2.31.so                 [.] malloc
#    0.43%  [kernel]                     [k] cpuidle_enter_state
#    0.42%  libc-2.31.so                 [.] __memmove_avx_unaligned_erms
#    0.42%  libc-2.31.so                 [.] __strlen_avx2
```

```shell
perf top -e cpu-clock  # 显示所有与CPU时钟相关的事件

# 显示内容如下：
# Samples: 757K of event 'cpu-clock', 4000 Hz, Event count (approx.): 139551834755 lost: 0/0 drop: 0/0
# Overhead  Shared Object                Symbol
#   99.70%  [kernel]                     [k] cpuidle_enter_state
#    0.03%  perf                         [.] queue_event
#    0.02%  libc-2.31.so                 [.] _int_free
#    0.02%  libc-2.31.so                 [.] _int_malloc
#    0.01%  perf                         [.] evsel__parse_sample
#    0.01%  perf                         [.] __hists__add_entry.constprop.0
#    0.01%  perf                         [.] rb_next
#    0.01%  perf                         [.] hists__findnew_entry
#    0.01%  perf                         [.] maps__find
#    0.01%  perf                         [.] __symbols__insert
#    0.01%  perf                         [.] deliver_event
#    0.01%  libc-2.31.so                 [.] __strcmp_avx2
#    0.01%  [kernel]                     [k] module_get_kallsym
#    0.01%  perf                         [.] perf_hpp__is_dynamic_entry
#    0.00%  perf                         [.] map__process_kallsym_symbol
#    0.00%  perf                         [.] ordered_events__queue
#    0.00%  perf                         [.] hpp__nop_cmp
#    0.00%  libc-2.31.so                 [.] malloc
#    0.00%  perf                         [.] hist_entry_iter__add
#    0.00%  perf                         [.] kallsyms__parse
#    0.00%  libpthread-2.31.so           [.] __pthread_mutex_trylock
#    0.00%  perf                         [.] sort__dso_cmp
#    0.00%  perf                         [.] d_print_comp_inner
#    0.00%  perf                         [.] thread__get
#    0.00%  libpthread-2.31.so           [.] __pthread_mutex_unlock
#    0.00%  perf                         [.] map__put
#    0.00%  [kernel]                     [k] kallsyms_expand_symbol.constprop.0
#    0.00%  perf                         [.] sort__sym_cmp
#    0.00%  perf                         [.] __sort__hpp_cmp
```

### 子命令：record

用于将性能记录到当前工作目录中的perf.data中。

```shell
perf record ls -l

# 显示信息如下：
# total 120
# drwxrwxr-x  5 shiyucun shiyucun  4096 5月   4 19:53 bags
# drwxr-xr-x  2 shiyucun shiyucun  4096 3月  16 11:56 Desktop
# drwxr-xr-x  3 shiyucun shiyucun  4096 5月   6 10:18 Documents
# drwxr-xr-x  2 shiyucun shiyucun 53248 5月  12 12:58 Downloads
# drwxr-xr-x  2 shiyucun shiyucun  4096 9月  27  2021 Music
# drwxr-xr-x  2 root     root      4096 9月  27  2021 nas
# drwxr-xr-x 11 shiyucun shiyucun  4096 9月  27  2021 NVIDIA_CUDA-11.4_Samples
# -rw-------  1 shiyucun shiyucun 18680 5月  12 19:18 perf.data
# drwxr-xr-x  2 shiyucun shiyucun  4096 1月   8 22:34 Pictures
# drwxr-xr-x  2 shiyucun shiyucun  4096 9月  27  2021 Public
# drwx------  6 shiyucun shiyucun  4096 10月 14  2021 snap
# drwxr-xr-x  2 shiyucun shiyucun  4096 9月  27  2021 Templates
# drwxr-xr-x  2 shiyucun shiyucun  4096 9月  27  2021 Videos
# drwxrwxr-x  6 shiyucun shiyucun  4096 11月 29 15:20 workspace
# [ perf record: Woken up 1 times to write data ]
# [ perf record: Captured and wrote 0.019 MB perf.data (8 samples) ]
```

### 子命令：report

用于分析record子命令生成的文件`perf.data`。

```shell
perf report  # 在 perf record ls -l 的执行目录

# 显示信息如下：
# Samples: 8  of event 'cycles', Event count (approx.): 6934865
# Overhead  Command  Shared Object      Symbol
#   70.44%  ls       [kernel.kallsyms]  [k] apparmor_file_alloc_security
#   28.26%  ls       [kernel.kallsyms]  [k] vma_interval_tree_insert
#    1.25%  perf     [kernel.kallsyms]  [k] perf_event_addr_filters_exec
#    0.05%  perf     [kernel.kallsyms]  [k] native_write_msr
```

### 子命令：bench

在系统上执行多个基准测试。

```shell
perf bench mem all  # 内存基准测试

# 显示信息如下：
# Running mem/memcpy benchmark...
# function 'default' (Default memcpy() provided by glibc)
# Copying 1MB bytes ...
# 
#       30.517578 GB/sec
# function 'x86-64-unrolled' (unrolled memcpy() in arch/x86/lib/memcpy_64.S)
# Copying 1MB bytes ...
# 
#       23.818598 GB/sec
# function 'x86-64-movsq' (movsq-based memcpy() in arch/x86/lib/memcpy_64.S)
# Copying 1MB bytes ...
# 
#       33.674569 GB/sec
# function 'x86-64-movsb' (movsb-based memcpy() in arch/x86/lib/memcpy_64.S)
# Copying 1MB bytes ...
# 
#       33.674569 GB/sec
# 
# Running mem/memset benchmark...
# function 'default' (Default memset() provided by glibc)
# Copying 1MB bytes ...
# 
#       54.253472 GB/sec
# function 'x86-64-unrolled' (unrolled memset() in arch/x86/lib/memset_64.S)
# Copying 1MB bytes ...
# 
#       27.901786 GB/sec
# function 'x86-64-stosq' (movsq-based memset() in arch/x86/lib/memset_64.S)
# Copying 1MB bytes ...
# 
#       54.253472 GB/sec
# function 'x86-64-stosb' (movsb-based memset() in arch/x86/lib/memset_64.S)
# Copying 1MB bytes ...
# 
#       54.253472 GB/sec
```
