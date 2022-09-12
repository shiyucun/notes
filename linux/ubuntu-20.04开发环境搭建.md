# 开发环境搭建

- [开发环境搭建](#开发环境搭建)
  - [配置终端](#配置终端)
  - [C/C++](#cc)
  - [Golang](#golang)
  - [Rust](#rust)
  - [Lua](#lua)

## 配置终端

参考链接：<https://zhuanlan.zhihu.com/p/265525597>

```shell
# 1. 查看当前 shell 环境
# 1.1 查看当前使用的 shell
echo $SHELL
# 1.2 查看当前系统是否已安装 zsh
cat /etc/shells

# 2. 步骤 1 中查看没有安装 zsh 时，安装并修改默认 zsh
# 2.1 安装 zsh
sudo apt-get install zsh
# 2.2 默认 shell 修改为 zsh
chsh -s /bin/zsh    # mac 下内置 zsh，直接执行修改默认 shell

# 默认 shell 的修改需要重新登录才能生效

# 3. 安装 oh-my-zsh
# 3.1 curl 方式
sudo apt-get install curl
sh -c "$(curl -fsSL https://gitee.com/shmhlsy/oh-my-zsh-install.sh/raw/master/install.sh)"
# 3.2 wget 方式
# sh -c "$(wget -O- https://gitee.com/shmhlsy/oh-my-zsh-install.sh/raw/master/install.sh)"
# 3.3 mac 下安装
# brew install curl sh -c "$(curl -fsSL https://gitee.com/shmhlsy/oh-my-zsh-install.sh/raw/master/install.sh)"
# cp ~/.oh-my-zsh/templates/zshrc.zsh-template ~/.zshrc

# oh-my-zsh 的修改需要重新打开终端生效

# 4. autojump
# 4.1 安装
sudo apt-get install autojump
# brew install autojump    # mac 下使用 brew 安装
# 4.2 配置环境变量
echo "" >> ~/.zshrc
echo '. /usr/share/autojump/autojump.sh' >> ~/.zshrc
# mac 下需要 vim ~/.zshrc 将
# plugins=(git)
# 修改为
# plugins=(git autojump)
# [[ -s $(brew --prefix)/etc/profile.d/autojump.sh ]] && . $(brew --prefix)/etc/profile.d/autojump.sh

# 5. 配置 powerlevel10k
# 5.1 获取 powerlevel10k
git clone --depth=1 https://gitee.com/romkatv/powerlevel10k.git ${ZSH_CUSTOM:-$HOME/.oh-my-zsh/custom}/themes/powerlevel10k
# 5.2 编辑 ~/.zshrc，修改主题
ZSH_THEME="powerlevel10k/powerlevel10k"

# 6. 安装字体
mkdir -p ~/tools && cd ~/tools
git clone git@github.com:ryanoasis/nerd-fonts.git
cd nerd-fonts && ./install.sh
# mac 下安装字体
# brew tap homebrew/cask-fonts
# brew install --cask font-hack-nerd-font

# 7. 配置 powerlevel10k
# sources 目录提供了 Dream_01.zshrc 和 Dream_02.zshrc 两个配置示例
# 将示例文件中的内容 copy 到 .zshrc 文件的最后
# mac 下需要在 iTerm2 -> Preferences -> Profiles -> Text -> font 中修改 Font
# ubuntu 下需要需要在 Termial -> Prefereces -> Profiles 中修改 Custom font
# 字体使用 Hack Nerd Font

# 8. 终端 ubuntu 下可以使用 terminator，macbook 可以下载 iterm2
sudo apt-get install terminator -y    # ubuntu 安装 terminator

# 9. 使配置生效
source ~/.zshrc

# 10. 终端可以设置透明色，不显示桌面图标的设置
gsettings set org.gnome.shell.extensions.desktop-icons show-home false
gsettings set org.gnome.shell.extensions.desktop-icons show-trash false
# gsettings set org.gnome.shell.extensions.desktop-icons show-home true
# gsettings set org.gnome.shell.extensions.desktop-icons show-trash true

# 11. 配置终端语法高亮和补全插件
git clone https://github.com/zsh-users/zsh-autosuggestions ~/.oh-my-zsh/custom/plugins/zsh-autosuggestions
git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ~/.oh-my-zsh/custom/plugins/zsh-syntax-highlighting
# 修改 ~/.zshrc，添加以下内容
plugins=(git autojump zsh-autosuggestions zsh-syntax-highlighting)
source ~/.oh-my-zsh/custom/plugins/zsh-autosuggestions/zsh-autosuggestions.zsh
source ~/.oh-my-zsh/custom/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh

# 12. 配置 vim
vim /etc/vim/vimrc
# 在文件尾部添加以下内容：
set number        "显示行号"
syntax on         "语法高亮"
set autoindent    "自动对齐，把对齐格式应用到下一行"
set smartindent   "依据上一行的对齐格式，智能选择对齐方式"
set tabstop=4     "tab转换为4个空格"
set shiftwidth=4  "行间交错时使用4个空格"
set showmatch     "显示匹配的括号"
```

## C/C++

`sudo apt-get install g++ gcc make cmake git vim`

## Golang

首先下载压缩包：[官网](https://golang.google.cn)、[Mirrors](https://gomirrors.org)。

我当前下载的版本是：**go1.18.2.linux-amd64.tar.gz**。

执行命令解压文件：`sudo tar -zxvf go1.18.2.linux-amd64.tar.gz --directory=/usr/local`。

配置环境变量：`export PATH=$PATH:/usr/local/go/bin`。

## Rust

浏览器访问[官网](https://www.rust-lang.org/)，点击[Install](https://www.rust-lang.org/tools/install)。

提示的安装命令：

```shell
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

执行后，需要做下选择，回车默认即可，如下：

```text
Current installation options:


   default host triple: x86_64-unknown-linux-gnu
     default toolchain: stable (default)
               profile: default
  modify PATH variable: yes

1) Proceed with installation (default)
2) Customize installation
3) Cancel installation
>
```

安装完成后，如果在本终端中使用，需要设置环境变量，或者重启终端，如下：

```text
Rust is installed now. Great!

To get started you may need to restart your current shell.
This would reload your PATH environment variable to include
Cargo's bin directory ($HOME/.cargo/bin).

To configure your current shell, run:
source $HOME/.cargo/env
```

以上是通过 rustup 在线安装 Rust，除此之外还有[其它安装方式](https://forge.rust-lang.org/infra/other-installation-methods.html)，可以按照操作说明进行安装。

## Lua

首先访问[官网下载](http://www.lua.org/download.html)发布包。

我下载的版本是：`lua-5.4.4.tar.gz`。

解压：`tar -xzvf lua-5.4.4.tar.gz`。

编译安装：`cd lua-5.4.4 && make linux && sudo make install`。
