
# CPU 绑定和程序优先级设置

- [CPU 绑定和程序优先级设置](#cpu-绑定和程序优先级设置)
  - [CPU 绑定](#cpu-绑定)
    - [概念](#概念)
    - [为什么要绑定](#为什么要绑定)
    - [进程绑定接口](#进程绑定接口)
    - [线程绑定接口](#线程绑定接口)
    - [taskset](#taskset)
    - [使用示例](#使用示例)
  - [优先级设置](#优先级设置)
  - [隔离 CPU 核心](#隔离-cpu-核心)

## CPU 绑定

### 概念

Affinity 是进程的一个属性，这个属性指明了进程调度器能够把这个进程调度到哪些 CPU 上。

在 linux 中，我们可以利用 CPU affinity 把一个或多个进程绑定到一个或多个 CPU 上。

CPU Affinity 分为2种：soft affinity 和 hard affinity。

soft affinity 仅是一个建议，如果不可避免，调度器还是会把进程调度到其它的 CPU 上。

hard affinity 是调度器必须遵守的规则。

### 为什么要绑定

CPU 之间是不共享缓存的，如果频繁的在各个CPU间进行切换，则需要不断的使旧CPU的cache失效。

如果进程只在某个CPU上执行，则不会出现失效的情况。

在多个线程操作的是相同的数据的情况下，如果把这些线程调度到一个处理器上：

- 增加了CPU缓存的命中率
- 可能导致并发性能的降低

在实时或对时间敏感的应用中，我们可以：

- 把系统进程绑定到某些CPU上
- 把应用进程绑定到剩余的CPU上

### 进程绑定接口

```c
//#define _GNU_SOURCE    //网上查到的大部分都需要这一行，但在我的环境中不需要
#include <sched.h>

// 设置进程优先级
int sched_setaffinity(pid_t pid, size_t cpusetsize, cpu_set_t *mask);
// 获取进程优先级
int sched_getaffinity(pid_t pid, size_t cpusetsize, cpu_set_t mask);
// 说明：
//     pid：进程的pid值，即某个进程绑定到某个CPU
//     cpu_set_size：sizeof(cpu_set_t)
//     cpu_set_t：掩码数组，共1024位，每一位对应一个cpu核
//     mask：类型为cpu_set_t，代表进程要绑定到的CPU核

void CPU_ZERO(cpu_set_t mask);             // 用于清空mask
void CPU_SET(int cpu, cpu_set_t *mask);    // 对mask某一位做置位操作
void CPU_CLR(int cpu, cpu_set_t *mask);    // 对mask某一位做清零操作

cpu_set_t mask;
CPU_ZERO(&mask);
CPU_SET(0, &mask);  // 绑定到 0 核
if (sched_setaffinity(0, sizeof(mask), &mask) == -1) {
  printf("Set affinity failed, ERROR:%s\n", strerror(errno));
}
```

注意：子进程会继承父进程的绑定关系。

### 线程绑定接口

```c
#include <sys/sysinfo.h>
#include <pthread.h>

int cpu_num = get_nprocs();    // 获取cpu核心数

int pthread_setaffinity_np(pthread_t thread, size_t cpusetsize, const cpu_set_t *cpuset);
int pthread_getaffinity_np(pthread_t thread, size_t cpusetsize, cpu_set_t *cpuset);

void CPU_ZERO (cpu_set_t *set);                   // 初始化，设为空
void CPU_SET (int cpu, cpu_set_t *set);           // 将某个cpu加入cpu集
void CPU_CLR (int cpu, cpu_set_t *set);           // 将某个cpu从cpu集中移出
int CPU_ISSET (int cpu, const cpu_set_t *set);    // 判断某个cpu是否已在cpu集
```

### taskset

taskset 是 linux 提供的一个命令，可以让某个程序运行在某个或某些 CPU 上。

1. 显示进程运行的 CPU：`taskset -p PID`
2. 指定进程运行在某个特定的 CPU：`taskset -pc core_id PID`
3. 进程启动时指定CPU：`taskset -c core_id ./a.out`

### 使用示例

```c
#include <stdio.h>
#include <sched.h>

int main() {
    cpu_set_t mask;

    CPU_ZERO(&mask);
    CPU_SET(1, &mask);

    if (sched_setaffinity(0, sizeof(mask), &mask) < 0) {
        printf("error.");
    }

    while(1) {}

    return 0; 
}
```

## 优先级设置

Linux进程调度策略：

- 非实时策略：
  - SCHED_OTHER：标准循环分时
  - SCHED_BATCH：用于"批处理"样式的进程执行
  - SCHED_IDLE：用于运行优先级较低的后台作业
- 实时策略：
  - SCHED_FIFO：先到先服务
  - SCHED_RR：时间片轮转

**设置进程调度策略和优先级的相关接口**：

```c
#include <sched.h>

struct sched_param {
   ...
   int sched_priority;
   ...
};

int sched_setscheduler(pid_t pid, int policy, const struct sched_param *param);
    // 功能：
    //     为 pid 指定的进程设置调度策略和相关参数
    //     如果 pid 等于 0，则设置调用进程的调度策略和参数
    // 注意：多进程情况下以上设置影响子进程，pid 不等于 0 时需要 root 权限

int sched_getscheduler(pid_t pid);
    // 功能：
    //     查询 pid 指定进程的调度策略
    //     如果 pid 等于 0，则查询调用进程的调度策略

int sched_get_priority_max(int policy);
    // 功能：获取进程可以 为调度算法 设置的 最高优先级　　

int sched_get_priority_min(int policy);
    // 功能：获取进程可以 为调度算法 设置的 最低优先级
```

**更改调用进程以使用最强的 FIFO 优先级**，如下所示：

```c
#include <sched.h>

int main(int argc,char *argv[]) {
    int maxpri = sched_get_priority_max(SCHED_FIFO);
    if (maxpri == -1) {
        perror("sched_get_priority_max() failed");
        exit(1);
    }

    struct sched_param param;
    param.sched_priority = maxpri;

    // 进程调度策略：SCHED_FIFO，优先级：maxpri
    if (sched_setscheduler(getpid(), SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler() failed");
        exit(1);
    }

    return 0;
}
```

**设置线程调度策略和优先级的相关接口**：

```c
int pthread_attr_getschedpolicy(const pthread_attr_t *attr, int *policy);
    // 功能：获取使用的调度策略

int sched_get_priority_max(int policy);
int sched_get_priority_min(int policy);
    // 功能：获取线程线程可设置的最大和最小优先级值
    // 返回值：成功返回最大和最小优先级值，失败返回－1

int pthread_attr_setschedpolicy(pthread_attr_t *attr, int policy);
    // 功能：设定调度策略
    // 注：有些系统需要定义 _POSIX_THREAD_PRIORITY_SCHEDULING

struct sched_param {
   ...
   int sched_priority;
   ...
};

int pthread_attr_setschedparam(pthread_attr_t *attr, const struct sched_param *param);
    // 功能：设置调度参数(sched_priority -> 调度优先级)
int pthread_attr_getschedparam(const pthread_attr_t *attr, struct sched_param *param);
    // 功能：获取调度参数(sched_priority -> 调度优先级)
```

注：**设置优先级先要获取最大、最小值，以确认系统在该调度策略下是否支持优先级使用**。

```c
#include <unistd.h >

int nice(int incr); 
    // 功能：设置进程调度优先级
    // 参数：incr 被增加到调用进程的 nice 值上
    // 返回值：成功返回调整后的 nice 值，错误返回-1
    // 注意：返回的 nice 也可能为 -1，因此使用前需要清除 errno，调用后检查 errno 以判断是否出错

    // 其它：
    // PR = nice + 20
    // PR 取值范围：[0, 2 * NZERO - 1]，则 nice 取值范围：[-20, 2 * NZERO - 21]
    // 头文件中会定义：NZERO 最大值，未定义则通过 sysconf(_SC_NZERO) 得到

errno = 0;
nice(-20);  // 进程优先级调整到最高
if (errno != 0) {
  printf("Set priority failed, ERROR:%s\n", strerror(errno));
}
```

**nice 和 renice 命令**：

```shell
nice --help
# Usage: nice [OPTION] [COMMAND [ARG]...]
# Run COMMAND with an adjusted niceness, which affects process scheduling.
# With no COMMAND, print the current niceness.  Niceness values range from
# -20 (most favorable to the process) to 19 (least favorable to the process).
# 
# Mandatory arguments to long options are mandatory for short options too.
#   -n, --adjustment=N   add integer N to the niceness (default 10)
#       --help     display this help and exit
#       --version  output version information and exit

renice --help
# Usage:
# renice [-n] <priority> [-p|--pid] <pid>...
# renice [-n] <priority>  -g|--pgrp <pgid>...
# renice [-n] <priority>  -u|--user <user>...
# 
# Alter the priority of running processes.
# 
# Options:
# -n, --priority <num>   specify the nice increment value
# -p, --pid <id>         interpret argument as process ID (default)
# -g, --pgrp <id>        interpret argument as process group ID
# -u, --user <name>|<id> interpret argument as username or user ID
# 
# -h, --help             display this help
# -V, --version          display version
# 
# For more details see renice(1).
```

## 隔离 CPU 核心

```shell
sudo vim /etc/default/grub
# GRUB_CMDLINE_LINUX_DEFAULT="quiet splash"
# 以上 GRUB_CMDLINE_LINUX_DEFAULT 修改为
# GRUB_CMDLINE_LINUX_DEFAULT="quiet splash isolcpus=0,2"

sudo update-grub && reboot
# 更新，并重启生效

more /proc/cmdline
# 确认修改是否生效
# 可以启动用户态程序查看 CPU 使用率，以确认配置在用户态是否生效
# 可以 cat /proc/interrupts 查看配置在内核态是否生效
```
