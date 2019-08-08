# Objective-C常见Tips

[TOC]

## 1、Xcode编译警告⚠️问题



### （1）Missing submodule ''

```
#import <AliDinamicX/AliDinamicXEngine.h> ⚠️Missing submodule 'AliDinamicX.AliDinamicXEngine'
```

* 原因分析

警告的头文件没有放入framework的umbrella header中[^1]



* 解决方案

a. 将警告的头文件没有放入framework的umbrella header中

b. 使用`GCC diagnostic ignored`忽略警告

```objective-c
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wincomplete-umbrella"
#import <AliDinamicX/AliDinamicXEngine.h>
#pragma GCC diagnostic pop
```





## 2、Xcode编译报错❌问题



## 2、Xcode链接报错问题



## 3、Xcode启动app报错问题





## References

[^1]:https://stackoverflow.com/a/26412191

