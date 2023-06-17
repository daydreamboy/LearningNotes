# brew使用手册

[TOC]

## 1、常用命令

### (1) list

格式：**brew list** [formula]    
说明：列出当前版本的formula的安装位置    
例子：    

```shell
$ brew list chisel
/usr/local/Cellar/chisel/1.6.0/libexec/commands/ (14 files)
/usr/local/Cellar/chisel/1.6.0/libexec/ (7 files)
/usr/local/Cellar/chisel/1.6.0/PATENTS
```



### (2) info

格式：**brew info** [formula]    
说明：列出formula的本地信息（安装版本等）
例子：    

```shell
$ brew info chisel
chisel: stable 1.8.0 (bottled), HEAD
Collection of LLDB commands to assist debugging iOS apps
https://github.com/facebook/chisel
/usr/local/Cellar/chisel/1.5.0 (24 files, 122.2KB)
  Built from source on 2017-08-11 at 16:04:30
/usr/local/Cellar/chisel/1.6.0 (26 files, 163KB) *
  Built from source on 2017-12-28 at 17:40:33
/usr/local/Cellar/chisel/1.8.0 (31 files, 261.7KB)
  Poured from bottle on 2018-07-23 at 10:49:18
From: https://github.com/Homebrew/homebrew-core/blob/master/Formula/chisel.rb
==> Options
--HEAD
	Install HEAD version
==> Caveats
Add the following line to ~/.lldbinit to load chisel when Xcode launches:
  command script import /usr/local/opt/chisel/libexec/fblldb.py
```



### (3) switch

格式：**brew** **switch** \<formula\> \<version\>     
说明：切换formula的版本[^1]
例子：    

```shell
$ brew switch chisel 1.6.0
Cleaning /usr/local/Cellar/chisel/1.5.0
Cleaning /usr/local/Cellar/chisel/1.8.0
Cleaning /usr/local/Cellar/chisel/1.6.0
0 links created for /usr/local/Cellar/chisel/1.6.0
$ brew list chisel
/usr/local/Cellar/chisel/1.6.0/libexec/commands/ (14 files)
/usr/local/Cellar/chisel/1.6.0/libexec/ (7 files)
/usr/local/Cellar/chisel/1.6.0/PATENTS
```



### (4) upgrade

格式：**brew upgrade** \<formula\>

说明：升级formula的版本

例子：

```shell
$ brew upgrade io
```



### (5) install

格式：**brew install** \<formula1formula2 ...\>

说明：升级formula的版本

例子：

```shell
$ brew install wget tree jq
```



### (6) tap

格式：**brew** **tap** [options] [user**/**repo] [URL]

作用：git clone一个formula仓库

举个例子

```shell
$ brew tap <your repository name>/taps http://path/to/brew/taps.git
```

说明

> 如果URL是github上的地址，可以按照这个格式**brew tap** user**/**repo **https://github.com/**user**/homebrew-**repo来命名user和repo。





## 2、首次安装Homebrew

Homebrew是Mac OS X的命令行包管理工具，类似Ubuntu下apt、CentOS下的yum。

官方网址：<http://brew.sh/>，提供的安装命令（可能会有变化，以官方为准），如下 

```shell
$ ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```



卸载命令，如下 

```shell
$ ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/uninstall)"
```



## 3、Homebrew基本概念

官方文档上，给下面术语的归纳[^2]，如下

| Term            | Description                                                  | Example                                                      |
| --------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **Formula**     | The package definition                                       | `/usr/local/Homebrew/Library/Taps/homebrew/homebrew-core/Formula/foo.rb` |
| **Keg**         | The installation prefix of a **Formula**                     | `/usr/local/Cellar/foo/0.1`                                  |
| **opt prefix**  | A symlink to the active version of a **Keg**                 | `/usr/local/opt/foo`                                         |
| **Cellar**      | All **Kegs** are installed here                              | `/usr/local/Cellar`                                          |
| **Tap**         | A Git repository of **Formulae** and/or commands             | `/usr/local/Homebrew/Library/Taps/homebrew/homebrew-core`    |
| **Bottle**      | Pre-built **Keg** used instead of building from source       | `qt-4.8.4.mavericks.bottle.tar.gz`                           |
| **Cask**        | An [extension of Homebrew](https://github.com/Homebrew/homebrew-cask) to install macOS native apps | `/Applications/MacDown.app/Contents/SharedSupport/bin/macdown` |
| **Brew Bundle** | An [extension of Homebrew](https://github.com/Homebrew/homebrew-bundle) to describe dependencies | `brew 'myservice', restart_service: true`                    |





## 4、安装结构

Homebrew安装位置：/usr/local/Homebrew

Cellar安装位置：/usr/local/Cellar

当前版本的软连接文件夹位置：/usr/local/opt

命令行工具的软连接文件夹位置：/usr/local/bin



## 5、常用安装包

### trash

将文件或文件夹移到废纸篓中 

```shell
$ trash <file/folder>
```



删除当前目录下所有文件或目录

```shell
$ trash *
```



### wget

下载工具 



### java

jdk安装

```shell
$ brew cask install java
$ brew cask install java8
```



不能安装Java8[^7]

```shell
$ brew cask install adoptopenjdk/openjdk/adoptopenjdk8
```





### jenv

```shell
$ brew install jenv
```



 ~/.zshrc文件，添加下面配置

```shell
export PATH="$HOME/.jenv/bin:$PATH"
eval "$(jenv init -)"
```





### tree

树形显示目录结构 

使用示例

```shell
$ tree . -L 2 -I node_modules
.
├── assets
│   └── js
├── dist
├── index.html
├── package-lock.json
├── package.json
└── webpack.config.js
```

* -L，指定显示的层级
* -I，忽略特定的文件夹
* -a，显示所有文件，包括隐藏文件和隐藏文件夹



### jq

[jq](https://stedolan.github.io/jq/)，JSON解析命令行工具。使用教程 <https://stedolan.github.io/jq/tutorial/>



### go2shell

go2shell，在当前选中文件夹打开Terminal。安装方法：`brew cask install go2shell`



### npm

npm，开发Node.js



### p7zip

p7zip，7z格式压缩工具[^3]

使用示例

```shell
$ 7z a "iOS 13.4.simruntime".7z iOS\ 13.4.simruntime
```





### Asset Catalog Tinkerer

Asset Catalog Tinkerer[^4]，查看Assets.car文件中的图片。安装方法：`brew cask install asset-catalog-tinkerer`



### Hex Fiend

Hex Fiend，二进制查看工具。安装方法：`brew cask install hex-fiend`



### ascii

ascii命令行工具[^5]，用于查看ASCII表



### graphviz[^6]

命令行绘图工具。安装方法：`brew install graphviz`



### iina

视频播放工具，可以显示毫秒的进度[^8]。安装方法：`brew install --cask iina`



### jtool[^9]

安装方法：`brew install --cask jtool`



### ninja

安装方法[^10]：`brew install ninja`



### binutils

安装方法：`brew install binutils`

binutils的官方文档是：https://sourceware.org/binutils/

默认安装后，不会添加任何命令行到$PATH中。

参考安装成功后的提示，如下

```shell
If you need to have binutils first in your PATH, run:
  echo 'export PATH="/usr/local/opt/binutils/bin:$PATH"' >> ~/.zshrc
```

由于binutils/bin下面有些命令和系统命令冲突，可以按需添加命令行工具的软链接。

举个例子，只使用addr2line命令行工具，如下

```shell
$ ln -s /usr/local/Cellar/binutils/2.40/bin/addr2line /usr/local/bin/addr2line
$ which addr2line                                                             
/usr/local/bin/addr2line
```



### tokei

安装方法：brew install tokei

tokei的git地址是：https://github.com/XAMPPRocky/tokei，参考这个SO[^11]的推荐

使用方法，如下

```shell
$ tokei <path/to/folder or file>
```





## 参考资料

[^1]: https://stackoverflow.com/a/17103753
[^2]:https://docs.brew.sh/Formula-Cookbook
[^3]:https://superuser.com/a/667076

[^4]:https://github.com/insidegui/AssetCatalogTinkerer

[^5]:http://macappstore.org/ascii/

[^6]:https://graphviz.org/

[^7]:https://stackoverflow.com/questions/55834845/unable-to-install-java8-with-homebrew

[^8]:https://apple.stackexchange.com/questions/410865/are-there-video-players-that-display-milliseconds-on-mac

[^9]:https://formulae.brew.sh/cask/jtool

[^10]:https://blog.simplypatrick.com/posts/2012/08-18-ninja-a-small-build-system/

[^11]:https://stackoverflow.com/a/60976012





