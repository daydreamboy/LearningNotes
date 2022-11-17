# xcrun命令

[TOC]


## 1、clang

| example | task |
|---------|------|
| clang -v | 查看版本 |
| clang -E helloworld.c \| open -f | 生成预处理文件 |
| clang -S -o - helloworld.c \| open -f | 生成汇编文件 |
| clang helloworld.c -Wl,-sectcreate,\_\_TEXT,\_\_info\_plist,./Info.plist -o a_with_InfoPlist.out | 添加\_\_TEXT,\_\_info\_plist区 |
| clang -c Foo.m | 生成.o文件 |
| clang helloworld.o Foo.o -Wl,`xcrun --show-sdk-path`/System/Library/Frameworks/Foundation.framework/Foundation -o a_with_mutiple_files.out | 链接.o以及Foundation，生成可执行文件 |
| clang -rewrite-objc Block1.m | 生成对应的.cpp文件 |



## 2、size

| example | task |
|---------|------|
| size -x -l -m a.out | 查看segment以及section的结构 |



## 3、otool

### （1）常见示例

| example | task |
|---------|------|
| otool -s \_\_TEXT \_\_text a.out | 查看\_\_TEXT,\_\_text的二进制内容 |
| otool -t a.out  | -t和-s \_\_TEXT \_\_text等价 |
| otool -s \_\_TEXT \_\_cstring a.out | 查看\_\_TEXT,\_\_cstring的二进制内容 |
| otool -s \_\_TEXT \_\_cstring -V a.out | 查看\_\_TEXT,\_\_cstring的字符串内容 |
| otool -s \_\_TEXT \_\_text -v a.out | 查看\_\_TEXT,\_\_text的汇编代码 |
| otool -s \_\_TEXT \_\_text -V a.out<br/>otool -tV a.out | 查看\_\_TEXT,\_\_text的汇编代码，而且带注释 |
| otool -v -h a.out | 查看Mach Header |
| otool -v -l a.out | 查看Load Commands（用于查看链接的动态库等），但是也总是显示Mach Header |
| otool -v -L a.out | 查看链接的动态库 |
| otool -o a.out | 查看Objective-C相关的metadata，一般有`__DATA,__objc_classlist`、`__DATA,__objc_classrefs`等 |



### （2）常用选项

#### `-l`

打印Load command

```shell
$ otool -l DingTalk | grep -A11 Load\ command\ 0
Load command 0
      cmd LC_SEGMENT
  cmdsize 56
  segname __PAGEZERO
   vmaddr 0x00000000
   vmsize 0x00004000
  fileoff 0
 filesize 0
  maxprot 0x00000000
 initprot 0x00000000
   nsects 0
    flags 0x0
```



#### `-V`

一般配合其他选项使用。打印反汇编后operands。举个例子

```shell
$ otool -h DingTalk
Mach header
      magic cputype cpusubtype  caps    filetype ncmds sizeofcmds      flags
 0xfeedface      12          9  0x00           2    91       9012 0x00210085
$ otool -hV DingTalk
Mach header
      magic cputype cpusubtype  caps    filetype ncmds sizeofcmds      flags
   MH_MAGIC     ARM         V7  0x00     EXECUTE    91       9012   NOUNDEFS DYLDLINK TWOLEVEL BINDS_TO_WEAK PIE
```

> -V，结合-t，可以反汇编text segment





## 4、nm

### （1）常见示例

| example | task |
|---------|------|
| nm -nm helloworld.o | 查看.o文件中符号 |
| nm -arch=arm64 -m DynamicLibrary \| grep dlsym | 查看二进制文件单个架构中的dlsym符号 |
| nm -g a.out | 忽略所有本地符号（类型t），然后输出 |

* -n，使用numeric顺序排序
* -m，使用machO格式输出
* -arch，指定架构，例如arm64、armv7
* -j，只显示符号名，不显示地址和类型



```
0000000100001a90 t -[MyClass .cxx_destruct]
    00000001000018c0 t -[MyClass initWithName:number:]
    00000001000019c0 t -[MyClass name]
    0000000100001a40 t -[MyClass number]
    00000001000019f0 t -[MyClass setName:]
    0000000100001a60 t -[MyClass setNumber:]
    0000000100001ad0 T _MyFunction
                     U _NSLog
    0000000100002350 S _NXArgc
    0000000100002358 S _NXArgv
    0000000100002290 S _OBJC_CLASS_$_MyClass
                     U _OBJC_CLASS_$_NSObject
    00000001000022e0 S _OBJC_IVAR_$_MyClass._name
    00000001000022e8 S _OBJC_IVAR_$_MyClass._number
    00000001000022b8 S _OBJC_METACLASS_$_MyClass
                     U _OBJC_METACLASS_$_NSObject
                     U ___CFConstantStringClassReference
    0000000100002368 S ___progname
    0000000100000000 A __mh_execute_header
                     U __objc_empty_cache
                     U __objc_empty_vtable
    0000000100002360 S _environ
                     U _exit
    0000000100001b70 T _main
                     U _objc_autoreleasePoolPop
                     U _objc_autoreleasePoolPush
                     U _objc_autoreleaseReturnValue
                     U _objc_getProperty
                     U _objc_msgSend
                     U _objc_msgSendSuper2
                     U _objc_msgSend_fixup
                     U _objc_release
                     U _objc_retain
                     U _objc_retainAutoreleasedReturnValue
                     U _objc_setProperty
                     U _objc_storeStrong
    0000000100002000 s _pvars
                     U dyld_stub_binder
    0000000100001880 T start
```

第一列是符号的地址，第三列是符号的名称，第二列是符号的类型[^1]

* T，符号在text section
* t，符号在text section，但是对外不可见（not visible）
* U，符号未定义（undefined），该符号在其他library中



说明

> nm命令行的实现，Apple已经开源，地址是https://opensource.apple.com/source/clang/clang-703.0.31/src/tools/llvm-nm/





## 5、strings

| example | task |
|---------|------|
| strings a.out | 查看可执行文件中可打印的字符串（例如__TEXT,__cstring中字符串） |
| strings -o a.out | -o显示字符串的文件偏移量，默认是十进制 |



## 6、lipo

| example | task |
|---------|------|
| lipo -info a.out | 查看可执行文件的架构 |
| lipo -create -output libffi.a ./Debug-iphoneos/libffi.a ./Debug-iphonesimulator/libffi.a | 合并两个架构的二进制文件 |
| lipo -thin arm64 \<xxx\> -output xxx_arm64 | 二进制文件分拆单个架构 |
| lipo -archs MyUniversalFramework | 查看二进制的架构 |
| lipo -remove x86_64 -output <executable.new> \<executable\> | 从Universal架构中移除某个架构 |



## 7、file

| example | task |
|---------|------|
| file \<file\> | 查看文件的MachO格式 |
| file -I \<file\> | 查看文件的mine类型 |



## 8、simctl

| example | task |
|---------|------|
| simctl list | 查看所有模拟器 |
| simctl list \| grep booted | 查看当前启动的模拟器 |
| simctl delete unavailable | 删除当前无效的模拟器（可以节省磁盘空间） |



## 9、ld

| options | meaning | tips |
|---------|---------|------|
| -all_load | 装载静态库中所有内容 | 对应Xcode中的Other Linker Flags |
| -ObjC | 装载静态库中所有ObjC内容 | 同上 |
| -force_load \<path\_to\_archive\> | 装载指定静态库 | 同上 |
| -undefined dynamic_lookup | 链接时如果没有找到符号实现，则不报错符号找不到 | 同上 |
| -Wl,-U,symbol_name[^5] | 同上，但是指定找不到符号，而不是全部符号 | 同上 |

参考资料：man ld



## 10、strip

| example | task |
|---------|------|
| strip -x XXX.framework/XXX | 移除所有local符号，仅保留global符号 |

参考资料：man strip



## 11、dwarfdump

| example | task |
|---------|------|
| dwarfdump -u \<mach-o file\><br/>dwarfdump --uuid \<path_to_dSYM><br/>dwarfdump --uuid \<path_to_dSYM\>/Contents/Resources/DWARF/\<BinaryName\>[^4] | 查看MachO文件的UUID (实际对应LC_UUID字段[1]) |
| dwarfdump -u --arch=arm64 \<mach-o file\> | 查看MachO文件中特定架构的UUID |

参考资料：man dwarfdump



说明

> LC_UUID，指的是MachO中Load Command UUID





## 12、lldb

| example | task |
|---------|------|
| $ lldb -n \<process name\> | 调试某个进程 |



## 13、install\_name\_tool

| example | task |
|---------|------|
| $ install\_name\_tool DeleteMe -change /System/Library/Frameworks/Social.framework/Social /System/Library/Frameworks/NotificationCenter.framework/NotificationCenter | 替换MachO文件中依赖的动态库LC字段。otool -L查看修改后的依赖库 |



## 14、momc

| example                                                      | task |
| ------------------------------------------------------------ | ---- |
| $ xcrun momc <br/> usage: momc --sdkroot=<path> \[--appletvos-deployment-target\]\[--iphoneos-deployment-target\]\[--macosx-deployment-target\]\[--watchos-deployment-target\]\[--module \]\[--print-diagnostic-categories\]\[--no-warnings\]\[--no-inverse-relationship-warnings\]\[--no-max-property-count-warnings\]\[--no-delete-rule-warnings\]\[--dump-models\] source destination |      momc用法 |
| $ /Applications/Xcode.app/Contents/Developer/usr/bin/momc --sdkroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk --iphonesimulator-deployment-target 8.0 ~/path/to/XXX.xcdatamodeld ~/ |  编译xcdatamodeld文件    |



## 15、c++filt

| Example                                                      | Task                                               |
| ------------------------------------------------------------ | -------------------------------------------------- |
| $ c++filt __ZNSs6assignEPKcm <br/>std::string::assign(char const*, unsigned long) | demangle C++的符号                                 |
| $ xcrun c++filt -_ __ZNK7alibaba3ark17AIMRpcServiceImpl12GetUserAgentEv<br/>alibaba::ark::AIMRpcServiceImpl::GetUserAgent() const | 某些情况下，需要指定`-_`选项过滤符号中的下划线[^3] |

说明

> 1. 有时候可以配合nm使用，例如`nm -m <your c++ library> | c++filt > symbols.txt `



## 16、assetutil

作用：查看Assets.car文件

| Example                             | Task                               |
| ----------------------------------- | ---------------------------------- |
| $ xcrun assetutil --info Assets.car | 查看Assets.car的描述(JSON格式)[^2] |



## 17、mdfind

作用：mdfind是MacOS Spotlight的命令行工具。但是它能比较方便查询UUID对应的dSYM文件路径。

| Example                                                      | Task                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| $ mdfind "com_apple_xcode_dsym_uuids == DD698BD4-71CE-3439-8BDF-BA96C0320562" | 查询UUID对应的dSYM文件路径[^4]。注意：UUID必须都是大写，而且满足8-4-4-4-12格式 |



## 18、swift-demangle

作用：demangle swift的符号

举个例子，如下

```shell
$ xcrun swift-demangle _TFC9TestSwift15TestASwiftClass21testReturnVoidWithaIdfS0_FCSo6UIViewT_
_TFC9TestSwift15TestASwiftClass21testReturnVoidWithaIdfS0_FCSo6UIViewT_ ---> TestSwift.TestASwiftClass.testReturnVoidWithaId(TestSwift.TestASwiftClass) -> (__C.UIView) -> ()
```



## 19、dyldinfo

作用：显示在一个可执行文件中dyld所使用的信息

man文档描述，如下

> **dyldinfo** – Displays information used by dyld in an executable



| Example                             | Task                               |
| ----------------------------------- | ---------------------------------- |
| $ xcrun assetutil --info Assets.car | 查看Assets.car的描述(JSON格式)[^2] |



## 20、leaks

作用：搜索一个进程泄漏的内存

| Example                                                      | Task                   |
| ------------------------------------------------------------ | ---------------------- |
| `$ leaks $(pgrep someProcessName) --ouputGraph Process-$(date +%F-%H:%M:%S).memgraph` | dump某个进程的内存分布 |

说明

> 1. `$(date +%F-%H:%M:%S)`，用于显示时间戳，例如`echo $(date +%F-%H:%M:%S)`
> 2. `$(pgrep someProcessName)`，用于查找特定进程的pid。如果知道pid，也可以直接填入pid
> 3. `.memgraph`文件，可以用Xcode打开



## 21、heap

作用：分析堆内存

| Example                               | Task                         |
| ------------------------------------- | ---------------------------- |
| $ heap -z -address=all <xxx.memgraph> | 分析某个memgraph文件的堆对象 |



## 22、malloc_history

作用：分析某个进程的对象malloc堆栈

| Example                                              | Task                         |
| ---------------------------------------------------- | ---------------------------- |
| $ malloc_history <ProcessName> -fullStacks <address> | 分析某个进程的对象malloc堆栈 |

说明

> 使用malloc_history需要满足下面条件，才能看到正确的堆栈
>
> 1. 这里ProcessName是正在运行的进程，为了能看到符号，需要运行Debug版本的Mac App
>
> 2. address是某个对象的地址。这个地址可以从dump的memgraph文件中来获取。简单来说，如果存在大内存增长，则可以dump两次内存，即增长前和增长后，然后diff出多出哪些对象。最后根据这些对象地址，使用malloc_history来dump出堆栈，从而知道代码哪里出了问题
>
> 3. malloc_history需要配置app环境变量，开启Malloc Logging功能
>
>    ```shell
>    export MallocStackLogging=1
>    export MallocStackLoggingNoCompact=1
>    export MallocScribble=1
>    // optional
>    export MallocPreScribble=1
>    export MallocCheckHeapStart=1000
>    export MallocCheckHeapEach=100
>          
>    /path/to/xxx.app/Contents/MacOS/xxx
>    ```
>
>    











## References

[^1]: https://www.mikeash.com/pyblog/friday-qa-2011-12-02-object-file-inspection-tools.html 

[^2]:https://stackoverflow.com/a/44597439

[^3]:https://stackoverflow.com/questions/42341626/my-cfilt-doesnt-seem-to-work-properly-no-output-changes

[^4]:https://developer.apple.com/documentation/xcode/diagnosing_issues_using_crash_reports_and_device_logs/adding_identifiable_symbol_names_to_a_crash_report

[^5]:https://stackoverflow.com/questions/17281901/ignoring-an-undefined-symbol-in-a-dynamic-library-from-xcode





