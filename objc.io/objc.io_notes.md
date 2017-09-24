## objc.io Notes

### 1. [The Build Process](https://www.objc.io/issues/6-build-tools/build-process/)

* 工程有多个Target，按照依赖顺序进行生成。在`Log Navigator`中看到基本信息，如下

```
Build target Pods-SSZipArchive
...
Build target Makefile-openssl
...
Build target Pods-AFNetworking
...
Build target crypto
...
Build target Pods
...
Build target ssl
...
Build target objcio
```
如果要看到所有编译日志，可以选择`All`和`All Messages`，然后点击`Save...`，也可以`Editor`→`Copy transcript for shown results (All, All Messages) as Text`

* 针对每个Target生成，有自己编译过程（Build Phases）
![Build Phases](images/Build Phases.png)
上面的每个Build Phase按照一定顺序执行的

* 每个Build Phase下面执行很多任务，但是每个任务的日志格式基本一致，如下

```
(1) ProcessPCH /.../Pods-SSZipArchive-prefix.pch.pch Pods-SSZipArchive-prefix.pch normal armv7 objective-c com.apple.compilers.llvm.clang.1_0.compiler
    (2) cd /.../Dev/objcio/Pods
        setenv LANG en_US.US-ASCII
        setenv PATH "..."
    (3) /.../Xcode.app/.../clang 
            (4) -x objective-c-header 
            (5) -arch armv7 
            ... configuration and warning flags ...
            (6) -DDEBUG=1 -DCOCOAPODS=1 
            ... include paths and more ...
            (7) -c 
            (8) /.../Pods-SSZipArchive-prefix.pch 
            (9) -o /.../Pods-SSZipArchive-prefix.pch.pch
```


1. 第一行都是描述任务，一般以特定任务名开头，例如`ProcessPCH `。该任务下面的操作，都采用缩进显示。
2. 一些准备操作，cd、设置环境变量等
3. 调用特定命令。例如clang、ibtool等。一般命令会带很多的选项。下面以clang简单说明下
4. -x，指定编译文件的类型
5. -arch，指定编译的架构
6. -DDEBUG=1，……，设置预编译宏
7. -c，指定clang运行哪些操作
8. 源文件路径
9. 目标文件的格式和输出路径

整理一些常见Build Phase中的Task，如下

| Task名称 | 作用 |
|---|---|
| CompileC | 编译源文件(.m等) |
| Ld | 链接.o文件等，生成.app中的executable文件 |
| CompileStoryboard | 编译.storyboard文件 |
| ProcessInfoPlistFile | 生成.app/Info.plist文件 |
| CompileAssetCatalog | 处理.xcassets文件 | 
| LinkStoryboards | 链接.storyboardc文件 |
| PhaseScriptExecution | 执行Run Script |
| Touch | 使用touch命令更新.app文件 |
| CodeSign | 对.app文件签名 |
| ProcessPCH | 处理.pch文件 |

* 对于某个特定类型的文件，需要用到`Build Rules`

>
> TODO list
>
1. 学习`Build Rules`的使用
2. 学习使用[ImageMagick](https://github.com/krzysztofzablocki/Bootstrap)给App Icon打水印


