
# Docker

- [Docker](#docker)
  - [容器的使用](#容器的使用)
    - [pull](#pull)
    - [run](#run)
    - [ps](#ps)
    - [start](#start)
    - [stop](#stop)
    - [restart](#restart)
    - [attach](#attach)
    - [exec](#exec)
    - [export](#export)
    - [import](#import)
    - [rm](#rm)
    - [port](#port)
    - [logs](#logs)
  - [镜像的使用](#镜像的使用)
    - [commit](#commit)
    - [tag](#tag)
    - [build](#build)
  - [Dockerfile](#dockerfile)
    - [FROM](#from)
    - [RUN](#run-1)
    - [COPY](#copy)
    - [ADD](#add)
    - [CMD](#cmd)
    - [ENTRYPOINT](#entrypoint)
    - [ENV](#env)
    - [ARG](#arg)
    - [VOLUME](#volume)
    - [EXPOSE](#expose)
    - [WORKDIR](#workdir)
    - [USER](#user)
    - [HEALTHCHECK](#healthcheck)
    - [ONBUILD](#onbuild)
    - [LABEL](#label)
  - [示例](#示例)

Docker是一个用于开发，交付和运行应用程序的开放平台。

Docker能够将应用程序与基础架构分离，从而实现快速交付软件。

借助Docker，可以以与管理应用程序相同的方式来管理基础架构。

Docker可以让一个应用在任何操作系统中非常方便的运行。

虚拟机也能在一个操作系统中运行另外一个操作系统，保护系统中的任何应用。

但虚拟机是在操作系统中模拟硬件设备，然后运行另一个操作系统。

而Docker仅仅是封装函数库，并没有模拟完整的操作系统。

- docker是一个系统进程；虚拟机是在操作系统中的操作系统
- docker体积小、启动速度快、性能好；虚拟机体积大、启动速度慢、性能一般

我们按照以下链接中的内容安装Docker：

- [Install Docker](https://docs.docker.com/desktop/install/ubuntu/)
- [ubuntu安装Docker](../linux/ubuntu常用软件安装和使用.md)

相关概念：

**镜像(Image)**：Docker将应用及其所需的依赖、函数库、环境、配置等文件打包在一起的文件。

**容器(Container)**：镜像中的应用程序运行后形成的进程就是容器，Docker会给容器进程做隔离。

一切应用最终都是代码组成，都是硬盘中的一个个的字节形成的文件。

代码只有在运行时，才会加载到内存，形成进程。

镜像就是把应用在硬盘上的文件、运行环境、部分系统函数库文件一起打包形成的文件包(只读)。

容器是将这些文件中编写的程序、函数加载到内存中隔离起来形成进程。

因此一个镜像可以启动多次，形成多个容器进程。

docker安装完成后可以通过`docker`命令查看所有命令选项。

## 容器的使用

### pull

用于获取镜像，如：`docker pull ubuntu`。

```shell
docker pull --help

# Usage:  docker pull [OPTIONS] NAME[:TAG|@DIGEST]

# Pull an image or a repository from a registry

# Options:
#   -a, --all-tags                Download all tagged images in the repository
#       --disable-content-trust   Skip image verification (default true)
#       --platform string         Set platform if server is multi-platform capable
#   -q, --quiet                   Suppress verbose output
```

### run

用于启动容器。如：`docker run -itd -P -p 5000:5000 ubuntu /bin/bash`。

参数说明：

- `i`：始终保持交互式操作
- `t`：分配一个伪tty设备
- `d`：后台运行容器，会打印容器ID
- `P`：容器内使用的网络端口随机映射到主机上
- `p`：容器内端口映射到主机指定端口
- `ubuntu`：创建容器使用的镜像
- `/bin/bash`：容器启动后启动bash，docker中必须保持一个进程运行，否则容器会退出

注意：默认都是绑定tcp端口，如果要绑定udp端口，可以在端口后面加上`/udp`。

```shell
docker run --help

# Usage:  docker run [OPTIONS] IMAGE [COMMAND] [ARG...]

# Run a command in a new container

# Options:
#       --add-host list                  Add a custom host-to-IP mapping (host:ip)
#   -a, --attach list                    Attach to STDIN, STDOUT or STDERR
#       --blkio-weight uint16            Block IO (relative weight), between 10 and 1000, or 0 to disable (default 0)
#       --blkio-weight-device list       Block IO weight (relative device weight) (default [])
#       --cap-add list                   Add Linux capabilities
#       --cap-drop list                  Drop Linux capabilities
#       --cgroup-parent string           Optional parent cgroup for the container
#       --cgroupns string                Cgroup namespace to use (host|private)
#                                        'host':    Run the container in the Docker host's cgroup namespace
#                                        'private': Run the container in its own private cgroup namespace
#                                        '':        Use the cgroup namespace as configured by the
#                                                   default-cgroupns-mode option on the daemon (default)
#       --cidfile string                 Write the container ID to the file
#       --cpu-period int                 Limit CPU CFS (Completely Fair Scheduler) period
#       --cpu-quota int                  Limit CPU CFS (Completely Fair Scheduler) quota
#       --cpu-rt-period int              Limit CPU real-time period in microseconds
#       --cpu-rt-runtime int             Limit CPU real-time runtime in microseconds
#   -c, --cpu-shares int                 CPU shares (relative weight)
#       --cpus decimal                   Number of CPUs
#       --cpuset-cpus string             CPUs in which to allow execution (0-3, 0,1)
#       --cpuset-mems string             MEMs in which to allow execution (0-3, 0,1)
#   -d, --detach                         Run container in background and print container ID
#       --detach-keys string             Override the key sequence for detaching a container
#       --device list                    Add a host device to the container
#       --device-cgroup-rule list        Add a rule to the cgroup allowed devices list
#       --device-read-bps list           Limit read rate (bytes per second) from a device (default [])
#       --device-read-iops list          Limit read rate (IO per second) from a device (default [])
#       --device-write-bps list          Limit write rate (bytes per second) to a device (default [])
#       --device-write-iops list         Limit write rate (IO per second) to a device (default [])
#       --disable-content-trust          Skip image verification (default true)
#       --dns list                       Set custom DNS servers
#       --dns-option list                Set DNS options
#       --dns-search list                Set custom DNS search domains
#       --domainname string              Container NIS domain name
#       --entrypoint string              Overwrite the default ENTRYPOINT of the image
#   -e, --env list                       Set environment variables
#       --env-file list                  Read in a file of environment variables
#       --expose list                    Expose a port or a range of ports
#       --gpus gpu-request               GPU devices to add to the container ('all' to pass all GPUs)
#       --group-add list                 Add additional groups to join
#       --health-cmd string              Command to run to check health
#       --health-interval duration       Time between running the check (ms|s|m|h) (default 0s)
#       --health-retries int             Consecutive failures needed to report unhealthy
#       --health-start-period duration   Start period for the container to initialize before starting health-retries countdown (ms|s|m|h) (default 0s)
#       --health-timeout duration        Maximum time to allow one check to run (ms|s|m|h) (default 0s)
#       --help                           Print usage
#   -h, --hostname string                Container host name
#       --init                           Run an init inside the container that forwards signals and reaps processes
#   -i, --interactive                    Keep STDIN open even if not attached
#       --ip string                      IPv4 address (e.g., 172.30.100.104)
#       --ip6 string                     IPv6 address (e.g., 2001:db8::33)
#       --ipc string                     IPC mode to use
#       --isolation string               Container isolation technology
#       --kernel-memory bytes            Kernel memory limit
#   -l, --label list                     Set meta data on a container
#       --label-file list                Read in a line delimited file of labels
#       --link list                      Add link to another container
#       --link-local-ip list             Container IPv4/IPv6 link-local addresses
#       --log-driver string              Logging driver for the container
#       --log-opt list                   Log driver options
#       --mac-address string             Container MAC address (e.g., 92:d0:c6:0a:29:33)
#   -m, --memory bytes                   Memory limit
#       --memory-reservation bytes       Memory soft limit
#       --memory-swap bytes              Swap limit equal to memory plus swap: '-1' to enable unlimited swap
#       --memory-swappiness int          Tune container memory swappiness (0 to 100) (default -1)
#       --mount mount                    Attach a filesystem mount to the container
#       --name string                    Assign a name to the container
#       --network network                Connect a container to a network
#       --network-alias list             Add network-scoped alias for the container
#       --no-healthcheck                 Disable any container-specified HEALTHCHECK
#       --oom-kill-disable               Disable OOM Killer
#       --oom-score-adj int              Tune host's OOM preferences (-1000 to 1000)
#       --pid string                     PID namespace to use
#       --pids-limit int                 Tune container pids limit (set -1 for unlimited)
#       --platform string                Set platform if server is multi-platform capable
#       --privileged                     Give extended privileges to this container
#   -p, --publish list                   Publish a container's port(s) to the host
#   -P, --publish-all                    Publish all exposed ports to random ports
#       --pull string                    Pull image before running ("always"|"missing"|"never") (default "missing")
#       --read-only                      Mount the container's root filesystem as read only
#       --restart string                 Restart policy to apply when a container exits (default "no")
#       --rm                             Automatically remove the container when it exits
#       --runtime string                 Runtime to use for this container
#       --security-opt list              Security Options
#       --shm-size bytes                 Size of /dev/shm
#       --sig-proxy                      Proxy received signals to the process (default true)
#       --stop-signal string             Signal to stop a container (default "SIGTERM")
#       --stop-timeout int               Timeout (in seconds) to stop a container
#       --storage-opt list               Storage driver options for the container
#       --sysctl map                     Sysctl options (default map[])
#       --tmpfs list                     Mount a tmpfs directory
#   -t, --tty                            Allocate a pseudo-TTY
#       --ulimit ulimit                  Ulimit options (default [])
#   -u, --user string                    Username or UID (format: <name|uid>[:<group|gid>])
#       --userns string                  User namespace to use
#       --uts string                     UTS namespace to use
#   -v, --volume list                    Bind mount a volume
#       --volume-driver string           Optional volume driver for the container
#       --volumes-from list              Mount volumes from the specified container(s)
#   -w, --workdir string                 Working directory inside the container
```

### ps

用于查看容器，如：`docker ps -a`。

以上命令输出：

```shell
docker ps -a
# CONTAINER ID   IMAGE          COMMAND   CREATED        STATUS        PORTS     NAMES
# d40753ffd30f   eb574ad4e57c   "bash"    47 hours ago   Up 46 hours             docker-test
```

```shell
docker ps --help

# Usage:  docker ps [OPTIONS]

# List containers

# Options:
#   -a, --all             Show all containers (default shows just running)
#   -f, --filter filter   Filter output based on conditions provided
#       --format string   Pretty-print containers using a Go template
#   -n, --last int        Show n last created containers (includes all states) (default -1)
#   -l, --latest          Show the latest created container (includes all states)
#       --no-trunc        Don't truncate output
#   -q, --quiet           Only display container IDs
#   -s, --size            Display total file sizes
```

### start

用于启动一个已停止的容器，如：`docker start d40753ffd30f`。

```shell
docker start --help

# Usage:  docker start [OPTIONS] CONTAINER [CONTAINER...]

# Start one or more stopped containers

# Options:
#   -a, --attach               Attach STDOUT/STDERR and forward signals
#       --detach-keys string   Override the key sequence for detaching a container
#   -i, --interactive          Attach container's STDIN
```

### stop

用于停止容器，如：`docker stop d40753ffd30f`。

```shell
docker stop --help

# Usage:  docker stop [OPTIONS] CONTAINER [CONTAINER...]

# Stop one or more running containers

# Options:
#   -t, --time int   Seconds to wait for stop before killing it (default 10)
```

### restart

用于重启容器，如：`docker restart d40753ffd30f`。

```shell
docker restart --help

# Usage:  docker restart [OPTIONS] CONTAINER [CONTAINER...]

# Restart one or more containers

# Options:
#   -t, --time int   Seconds to wait for stop before killing the container (default 10)
```

### attach

用于进入已启动的容器，如：`docker attach d40753ffd30f`。

**注意**：如果从这个容器退出，会导致容器的停止。

```shell
docker attach --help

# Usage:  docker attach [OPTIONS] CONTAINER

# Attach local standard input, output, and error streams to a running container

# Options:
#       --detach-keys string   Override the key sequence for detaching a container
#       --no-stdin             Do not attach STDIN
#       --sig-proxy            Proxy all received signals to the process (default true)
```

### exec

用于进入已启动的容器，如：`docker exec -it d40753ffd30f /bin/bash`。

**注意**：如果从这个容器退出，不会导致容器的停止。

```shell
docker exec --help

# Usage:  docker exec [OPTIONS] CONTAINER COMMAND [ARG...]

# Run a command in a running container

# Options:
#   -d, --detach               Detached mode: run command in the background
#       --detach-keys string   Override the key sequence for detaching a container
#   -e, --env list             Set environment variables
#       --env-file list        Read in a file of environment variables
#   -i, --interactive          Keep STDIN open even if not attached
#       --privileged           Give extended privileges to the command
#   -t, --tty                  Allocate a pseudo-TTY
#   -u, --user string          Username or UID (format: <name|uid>[:<group|gid>])
#   -w, --workdir string       Working directory inside the container
```

### export

用于导出容器快照，如：`docker export d40753ffd30f > docker-test.tar`。

```shell
docker export --help

# Usage:  docker export [OPTIONS] CONTAINER

# Export a container's filesystem as a tar archive

# Options:
#   -o, --output string   Write to a file, instead of STDOUT
```

### import

用于导入容器快照，如：`docker import docker-test.tar docker-test2`。

```shell
docker import --help

# Usage:  docker import [OPTIONS] file|URL|- [REPOSITORY[:TAG]]

# Import the contents from a tarball to create a filesystem image

# Options:
#   -c, --change list       Apply Dockerfile instruction to the created image
#   -m, --message string    Set commit message for imported image
#       --platform string   Set platform if server is multi-platform capable
```

### rm

用于删除容器，如：`docker rm -f d40753ffd30f`。

```shell
docker rm --help

# Usage:  docker rm [OPTIONS] CONTAINER [CONTAINER...]

# Remove one or more containers

# Options:
#   -f, --force     Force the removal of a running container (uses SIGKILL)
#   -l, --link      Remove the specified link
#   -v, --volumes   Remove anonymous volumes associated with the container
```

### port

用于查看指定容器的某个确定端口所映射到的主机端口，如：`docker port d40753ffd30f`。

```shell
docker port --help

# Usage:  docker port CONTAINER [PRIVATE_PORT[/PROTO]]

# List port mappings or a specific mapping for the container
```

### logs

用于输出容器内部的标准输出，如：`docker logs -f d40753ffd30f`。

```shell
docker logs --help

# Usage:  docker logs [OPTIONS] CONTAINER

# Fetch the logs of a container

# Options:
#       --details        Show extra details provided to logs
#   -f, --follow         Follow log output
#       --since string   Show logs since timestamp (e.g. 2013-01-02T13:23:37Z) or relative (e.g. 42m for 42 minutes)
#   -n, --tail string    Number of lines to show from the end of the logs (default "all")
#   -t, --timestamps     Show timestamps
#       --until string   Show logs before a timestamp (e.g. 2013-01-02T13:23:37Z) or relative (e.g. 42m for 42 minutes)
```

## 镜像的使用

- `docker images`：列出主机镜像
- `docker search`：查找镜像
- `docker pull`：获取镜像
- `docker rmi`：删除镜像
- `docker run`：使用镜像创建容器
- `docker commit`：提交更新镜像
- `docker tag`：为镜像添加新的标签
- `docker build`：构建镜像

### commit

容器按需求更改后，此命令可用于提交容器副本，如：

`docker commit -m="soft update" -a="shiyucun" d40753ffd30f docker-test/ubuntu:v2`

参数说明：

- `m`：描述信息
- `a`：镜像作者
- `d40753ffd30f`：容器ID(也可输入容器名字)
- `docker-test/ubuntu:v2`：要创建的目标镜像名

```shell
docker commit --help

# Usage:  docker commit [OPTIONS] CONTAINER [REPOSITORY[:TAG]]

# Create a new image from a container's changes

# Options:
#   -a, --author string    Author (e.g., "John Hannibal Smith <hannibal@a-team.com>")
#   -c, --change list      Apply Dockerfile instruction to the created image
#   -m, --message string   Commit message
#   -p, --pause            Pause container during commit (default true)
```

### tag

用于设置镜像标签，如：`docker tag eb574ad4e57c test/ubuntu:v3`。

参数说明：

- `eb574ad4e57c`：镜像ID
- `test/ubuntu`：镜像源名
- `v3`：标签名

设置完成后，使用`docker images`查看新镜像。

```shell
docker tag --help

# Usage:  docker tag SOURCE_IMAGE[:TAG] TARGET_IMAGE[:TAG]

# Create a tag TARGET_IMAGE that refers to SOURCE_IMAGE
```

### build

用于构建镜像，如：`docker build -t test/ubuntu:v4 .`。

参数说明：

- `t`：目标镜像名
  - `test/ubuntu`：镜像源名
  - `v4`：镜像tag
- `.`：dockerfile路径(可输入绝对路径)

```shell
docker build --help

# Usage:  docker build [OPTIONS] PATH | URL | -

# Build an image from a Dockerfile

# Options:
#       --add-host list           Add a custom host-to-IP mapping (host:ip)
#       --build-arg list          Set build-time variables
#       --cache-from strings      Images to consider as cache sources
#       --disable-content-trust   Skip image verification (default true)
#   -f, --file string             Name of the Dockerfile (Default is 'PATH/Dockerfile')
#       --iidfile string          Write the image ID to the file
#       --isolation string        Container isolation technology
#       --label list              Set metadata for an image
#       --network string          Set the networking mode for the RUN instructions during build (default "default")
#       --no-cache                Do not use cache when building the image
#   -o, --output stringArray      Output destination (format: type=local,dest=path)
#       --platform string         Set platform if server is multi-platform capable
#       --progress string         Set type of progress output (auto, plain, tty). Use plain to show container output (default "auto")
#       --pull                    Always attempt to pull a newer version of the image
#   -q, --quiet                   Suppress the build output and print image ID on success
#       --secret stringArray      Secret file to expose to the build (only if BuildKit enabled): id=mysecret,src=/local/secret
#       --ssh stringArray         SSH agent socket or keys to expose to the build (only if BuildKit enabled) (format: default|<id>[=<socket>|<key>[,<key>]])
#   -t, --tag list                Name and optionally a tag in the 'name:tag' format
#       --target string           Set the target build stage to build.
```

## Dockerfile

Dockerfile是一个用来构建镜像的文本文件。

### FROM

定制的镜像都是基于`FROM`的镜像开始操作，如：`FROM ubuntu`。

### RUN

用于执行后面跟着的命令行命令。

格式：

- `RUN <命令行命令>`
- `RUN ["可执行文件", "参数1", "参数2"]`

举例：

- `RUN apt update`
- `RUN ["./printArgs", "arg1", "arg2"]`

Dockerfile的指令每执行一次都会在docker上新建一层。

过多的层数，会造成镜像膨胀过大。

因此，多条`RUN`指令可以使用`&&`符号进行连接。

### COPY

复制指令，从上下文目录中复制文件或者目录到容器里指定路径。

格式：

- `COPY [--chown=<user>:<group>] <源路径1>...  <目标路径>`
- `COPY [--chown=<user>:<group>] ["<源路径1>",...  "<目标路径>"]`

参数说明：

- `[--chown=<user>:<group>]`：可选参数，用户改变复制到容器内文件的拥有者和属组
- `<源路径>`：源文件或者源目录，这里可以是通配符表达式
- `<目标路径>`：容器内的指定路径

### ADD

`ADD`指令和`COPY`的使用格类似，功能也类似，不同之处在于：

- `ADD`优点：可以自动复制并解压到目标路径，条件：
  - 源文件为tar压缩文件
  - 压缩格式为`gzip`、`bzip2`、`xz`时
- `ADD`缺点：在不解压的前提下，无法复制tar压缩文件

### CMD

类似于`RUN`指令，用于运行程序，区别:

- `CMD`：在`docker run`时运行
- `RUN`：在`docker build`时运行

作用：为启动的容器指定默认要运行的程序，程序运行结束，容器也就结束。

`CMD`指令指定的程序可被`docker run`命令行参数中指定要运行的程序覆盖。

注意：Dockerfile中存在多个`CMD`指令时，仅最后一个生效。

格式：

- `CMD <shell 命令>`
- `CMD ["<可执行文件或命令>","<param1>","<param2>",...]`
- `CMD ["<param1>","<param2>",...]  # 该写法是为 ENTRYPOINT 指令指定的程序提供默认参数`

### ENTRYPOINT

类似`CMD`指令，但不会被`docker run`的命令行参数指定的指令覆盖。

`docker run`的命令行参数会作为参数输入`ENTRYPOINT`指定的程序。

运行`docker run`时如果使用了`--entrypoint`选项，将覆盖`ENTRYPOINT`指令指定的程序。

注意：如果Dockerfile中如果存在多个`ENTRYPOINT`指令，仅最后一个生效。

格式： `ENTRYPOINT ["<executeable>","<param1>","<param2>",...]`

### ENV

设置环境变量，定义了环境变量，那么在后续的指令中，就可以使用这个环境变量。

格式：

- `ENV <key> <value>`
- `ENV <key1>=<value1> <key2>=<value2>...`

`$`符号可用于环境变量取值。

构建好的镜像内此环境变量依然可用。

### ARG

构建参数，与`ENV`作用一致。

`ARG`设置的环境变量仅对Dockerfile内有效，也就是说只有`docker build`的过程中有效。

`docker build`中可以被`--build-arg <参数名>=<值>`覆盖。

格式：`ARG <参数名>[=<默认值>]`

### VOLUME

定义匿名数据卷。

在启动容器时忘记挂载数据卷，会自动挂载到匿名卷。

作用：

- 避免重要的数据因容器重启而丢失
- 避免容器不断变大

格式：

- `VOLUME ["<路径1>", "<路径2>"...]`
- `VOLUME <路径>`

在执行`docker run`时，可以通过`-v`参数修改挂载点。

### EXPOSE

仅用于声明端口。

作用：

- 帮助镜像使用者理解镜像服务的守护端口，以方便配置映射
- 在`docker run`使用随机端口映射时，会自动随机映射`EXPOSE`的端口

格式：`EXPOSE <端口1> [<端口2>...]`

### WORKDIR

指定工作目录。

用`WORKDIR`指定的工作目录，会在构建镜像的每一层中都存在。

注意：必须提前创建好`WORKDIR`指定的工作目录。

`docker build`构建镜像的过程中，每一个`RUN`命令都是新建的一层。

只有通过`WORKDIR`创建的目录才会一直存在。

格式：`WORKDIR <工作目录路径>`

### USER

用于指定执行后续命令的用户和用户组。

注意：用户和用户组必须提前已经存在。

格式：`USER <用户名>[:<用户组>]`

### HEALTHCHECK

用于指定某个程序或者指令来监控容器服务的运行状态。

格式：

- `HEALTHCHECK [选项] CMD <命令>`：设置检查容器健康状况的命令
- `HEALTHCHECK NONE`：如果基础镜像有健康检查指令，使用这行可以屏蔽掉其健康检查指令

### ONBUILD

用于延迟构建命令的执行。

Dockerfile(File1)里用`ONBUILD`指定的命令，在本次构建镜像(镜像A)的过程中不会执行。

当有Dockerfile(File2)使用原镜像(镜像A)时，构建新镜像(镜像B)会执行原Dockerfile(File1)中指定的命令。

格式：`ONBUILD <其它指令>`

### LABEL

用于给镜像添加一些元数据，以键值对的形式，语法格式如下：

- `LABEL <key>=<value> <key>=<value> <key>=<value> ...`

如添加镜像的作者：`LABEL org.opencontainers.image.authors="shiyucun"`

查看`LABEL`使用命令：`docker image inspect d44cd90f49e4`

[annotation keys](https://github.com/opencontainers/image-spec/blob/main/annotations.md#pre-defined-annotation-keys)

## 示例

[notes.dockerfile](../../docker/notes.dockerfile)
