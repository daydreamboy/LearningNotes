## xcrun命令


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
| otool -s __TEXT __text a.out  | 查看__TEXT,__text的二进制内容 |
| otool -s __TEXT __cstring a.out  | 查看__TEXT,__cstring的二进制内容 |
| otool -s __TEXT __text -v a.out | 查看__TEXT,__text的汇编代码 |
| otool -v -h a.out | 查看Mach Header |
| otool -v -l a.out | 查看Load Commands |
| otool -v -L a.out | 查看链接的动态库 |

### 4. nm

| example | task |
|---------|------|
| nm -nm helloworld.o | 查看.o文件中符号 |
| nm -arch=arm64 -m DynamicLibrary \| grep dlsym | 查看二进制文件单个架构中的dlsym符号 |

* -n，使用numeric顺序排序
* -m，使用machO格式输出
* -arch，指定架构，例如arm64、armv7

### 5. strings

| example | task |
|---------|------|
| strings a.out | 查看可执行文件中可打印的字符串（例如__TEXT,__cstring中字符串） |

### 6. lipo

| example | task |
|---------|------|
| lipo -info a.out | 查看可执行文件的架构 |
| lipo -create -output libffi.a ./Debug-iphoneos/libffi.a ./Debug-iphonesimulator/libffi.a | 合并两个架构的二进制文件 |
| lipo -thin arm64 <xxx> -output xxx_arm64 | 二进制文件分拆单个架构 |

### 7. file

| example | task |
|---------|------|
| file \<file\> | 查看文件的MachO格式 |
| file -I \<file\> | 查看文件的mine类型 |

