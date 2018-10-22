## iOS Dev Tools

[TOC]

---

### 1、class-dump

下载地址：http://stevenygard.com/projects/class-dump/

安装方法：

* 解压class-dump-3.5.tar.gz，将class-dump放到`/usr/local/bin`[^1]

用法：

```
$ class-dump a.out
```



### 2、otx

安装方法：

* brew cask install otx

用法：

* GUI方式，使用otx.app
* 命令行方式
  * otx -b a.out，-b在每个方法块之间加上空行



[^1]: https://stackoverflow.com/a/44063320 

