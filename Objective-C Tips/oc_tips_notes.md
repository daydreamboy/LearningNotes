# Objective-C常见Tips

[TOC]

## 1、lldb调试问题

### （1）error: instance method '' has incompatible result types in different translation units instance method '' also declared here



问题：lldb在某个时刻开始，使用lldb命令报错`error: instance method '' has incompatible result types in different translation units instance method '' also declared here`

```
error: instance method 'YW_lyk_size' has incompatible result types in different translation units ('void' vs. 'CGSize')
instance method 'YW_lyk_size' also declared here
```



分析：二进制文件中存在两个签名相同的分类方法[^1]



解决方法：搜索工程Pods文件下所有二进制文件以及源码，是否存在相同的分类方法





## 2、Xcode编译报错问题



## 3、Xcode链接报错问题



## 4、Xcode启动app报错问题





## References

[^1]: https://www.jianshu.com/p/a488de9cd535

