
# 获取目录
SOURCES_DIR := $(shell pwd)
BUILD_DIR   := $(SOURCES_DIR)/build

CROSS     :=

CC        := $(CROSS)gcc
CXX       :=
CFLAGS    := -g -Wall -O3 -fPIC -I $(SOURCES_DIR)
CXXFLAGS  :=
LDFLAGS   := -L$(SOURCES_DIR)/node1 -L$(SOURCES_DIR)/node2

AR        := ar -rc
CP        := cp -rf
RM        := rm -rf
MK        := mkdir -p

export SOURCES_DIR BUILD_DIR CC CXX CFLAGS CXXFLAGS LDFLAGS AR CP RM MK

# build 目录存放安装文件和可执行文件，不需要编译
# main 目录依赖 node1 和 node2，最后编译
exclude_dirs := build main
main_dir := main

# 通过 find 获取各个子目录
sub_dirs := $(shell find . -maxdepth 1 -type d)
# 去除目录名中的 "./"
sub_dirs := $(basename $(patsubst ./%, %, $(sub_dirs)))
# 剔除不需要编译的目录
sub_dirs := $(filter-out $(exclude_dirs), $(sub_dirs))

.PHONY: $(main_dir) $(sub_dirs) clean install uninstall distclean

# Makefile 编译的时候会进入目录2次，第1次解析 Makefile，第2次才是找目标进行编译

# 编译 main 目录
$(main_dir): $(sub_dirs)
# 打印调试信息
	@echo ++++++++ main_dir ++++++++:$(main_dir)
	@for dir in $(main_dir); do \
		$(MAKE) -C $$dir; \
	done

# 编译 main、build 以外的其它子目录
$(sub_dirs):
	@echo ++++++++ sub_dirs ++++++++: $(sub_dirs)
	@for dir in $(sub_dirs); do \
		$(MAKE) -C $$dir; \
	done

clean:
  # main 目录 clean
	@for dir in $(main_dir); do \
		$(MAKE) -C $$dir clean; \
	done

  # 其它子目录 clean
	@for dir in $(sub_dirs); do \
		$(MAKE) -C $$dir clean; \
	done

install:
  # 其它子目录 install
	@for dir in $(sub_dirs); do \
		$(MAKE) -C $$dir install; \
	done

  # main 目录 install
	@for dir in $(main_dir); do \
		$(MAKE) -C $$dir install; \
	done

uninstall:
  # main 目录 uninstall
	@for dir in $(main_dir); do \
		$(MAKE) -C $$dir uninstall; \
	done

  # 其它子目录 uninstall
	@for dir in $(sub_dirs); do \
		$(MAKE) -C $$dir uninstall; \
	done

distclean: clean
	$(RM) ${BUILD_DIR}

# 执行 main 程序，需要先把 libnode2.so 路径设置到 LD_LIBRARY_PATH 环境变量
