## xcrun命令

1. clang
2. size
3. otool
4. nm
5. strings
6. lipo
7. file
8. simctl
9. ld
10. strip
11. dwarfdump
12. lldb
13. install\_name\_tool


### 1. clang

| example | task |
|---------|------|
| clang -v | 查看版本 |
| clang -E helloworld.c \| open -f | 生成预处理文件 |
| clang -S -o - helloworld.c \| open -f | 生成汇编文件 |
| clang helloworld.c -Wl,-sectcreate,__TEXT,__info_plist,./Info.plist -o a_with_InfoPlist.out | 添加__TEXT,__info_plist区 |
| clang -c Foo.m | 生成.o文件 |
| clang helloworld.o Foo.o -Wl,`xcrun --show-sdk-path`/System/Library/Frameworks/Foundation.framework/Foundation -o a_with_mutiple_files.out | 链接.o以及Foundation，生成可执行文件 |
| clang -rewrite-objc Block1.m | 生成对应的.cpp文件 |


### 2. size

| example | task |
|---------|------|
| size -x -l -m a.out | 查看segment以及section的结构 |

### 3. otool

| example | task |
|---------|------|
| otool -s __TEXT __text a.out  | 查看\_\_TEXT,\_\_text的二进制内容 |
| otool -s __TEXT __cstring a.out  | 查看\_\_TEXT,\_\_cstring的二进制内容 |
| otool -s __TEXT __text -v a.out | 查看\_\_TEXT,\_\_text的汇编代码 |
| otool -v -h a.out | 查看Mach Header |
| otool -v -l a.out | 查看Load Commands（用于查看链接的动态库等） |
| otool -v -L a.out | 查看链接的动态库 |

### 4. nm

| example | task |
|---------|------|
| nm -nm helloworld.o | 查看.o文件中符号 |
| nm -arch=arm64 -m DynamicLibrary \| grep dlsym | 查看二进制文件单个架构中的dlsym符号 |

* -n，使用numeric顺序排序
* -m，使用machO格式输出
* -arch，指定架构，例如arm64、armv7
* -j，只显示符号名，不显示地址和类型

### 5. strings

| example | task |
|---------|------|
| strings a.out | 查看可执行文件中可打印的字符串（例如__TEXT,__cstring中字符串） |
| string -o a.out | -o显示字符串的文件偏移量，默认是十进制 |

### 6. lipo

| example | task |
|---------|------|
| lipo -info a.out | 查看可执行文件的架构 |
| lipo -create -output libffi.a ./Debug-iphoneos/libffi.a ./Debug-iphonesimulator/libffi.a | 合并两个架构的二进制文件 |
| lipo -thin arm64 \<xxx\> -output xxx_arm64 | 二进制文件分拆单个架构 |

### 7. file

| example | task |
|---------|------|
| file \<file\> | 查看文件的MachO格式 |
| file -I \<file\> | 查看文件的mine类型 |

### 8. simctl

| example | task |
|---------|------|
| simctl list | 查看所有模拟器 |
| simctl list \| grep booted | 查看当前启动的模拟器 |
| simctl delete unavailable | 删除当前无效的模拟器（可以节省磁盘空间） |

### 9. ld

| options | meaning | tips |
|---------|---------|------|
| -all_load | 装载静态库中所有内容 | 对应Xcode中的Other Linker Flags | 
| -ObjC | 装载静态库中所有ObjC内容 | 对应Xcode中的Other Linker Flags | 
| -force_load \<path\_to\_archive\> | 装载指定静态库 | 对应Xcode中的Other Linker Flags | 

参考资料：man ld

### 10. strip

| example | task |
|---------|------|
| strip -x XXX.framework/XXX | 移除所有local符号，仅保留global符号 |

参考资料：man strip

### 11. dwarfdump

| example | task |
|---------|------|
| dwarfdump -u \<mach-o file\> | 查看MachO文件的UUID (实际对应LC_UUID字段[1]) |
| dwarfdump -u --arch=arm64 \<mach-o file\> | 查看MachO文件中特定架构的UUID |

参考资料：man dwarfdump

### 12. lldb

| example | task |
|---------|------|
| lldb -n \<process name\> | 调试某个进程 |

### 13. install\_name\_tool

| example | task |
|---------|------|
| install\_name\_tool DeleteMe -change /System/Library/Frameworks/Social.framework/Social /System/Library/Frameworks/NotificationCenter.framework/NotificationCenter | 替换MachO文件中依赖的动态库LC字段。otool -L查看修改后的依赖库 |

--
注解：

[1] LC_UUID，指的是MachO中Load Command UUID



