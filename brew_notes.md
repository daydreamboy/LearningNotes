## brew使用手册

TOC

[TOC]

## 常用命令

### 1、list

格式：**brew list** [formula]    
说明：列出当前版本的formula的安装位置    
例子：    

```
$ brew list chisel
/usr/local/Cellar/chisel/1.6.0/libexec/commands/ (14 files)
/usr/local/Cellar/chisel/1.6.0/libexec/ (7 files)
/usr/local/Cellar/chisel/1.6.0/PATENTS
```



### 2、info

格式：**brew info** [formula]    
说明：列出formula的本地信息（安装版本等）
例子：    

```
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



### 3、swtich

格式：**brew** **switch** \<formula\> \<version\>     
说明：切换formula的版本[^1]
例子：    

```
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





## 首次安装

Homebrew是Mac OS X的命令行包管理工具，类似Ubuntu下apt、CentOS下的yum。

官方网址：<http://brew.sh/>，提供的安装命令（可能会有变化，以官方为准），如下 

```
$ ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```



卸载命令，如下 

```
ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/uninstall)"
```



## 基本概念





## 安装结构

Homebrew安装位置：/usr/local/Homebrew

Cellar安装位置：/usr/local/Cellar

当前版本的软连接文件夹位置：/usr/local/opt

命令行工具的软连接文件夹位置：/usr/local/bin



## 常用安装包

- trash，将文件或文件夹移到废纸篓中 
- wget，下载工具 
- jdk安装，brew cask install java 
- tree，树形显示目录结构 
- [jq](https://stedolan.github.io/jq/)，JSON解析命令行工具。使用教程 <https://stedolan.github.io/jq/tutorial/>



## 参考资料

[^1]: https://stackoverflow.com/a/17103753