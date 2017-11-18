# CococaPods手册
--

### 1. pod命令 

* `pod init`    
在.xcodeproj所在目录下创建一个Podfile文件

* `pod spec create [pod name]`    
在当前目录下创建一个podspec文件

* `pod ipc spec [xxx.podspec]`    
将.podspec文件转换成json格式，默认输出stdout[^1]

### 2. Static Library vs. Framework

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Podfile中支持使用`use_frameworks!`，指定Pod库的代码采用framework集成，否则默认采用静态库集成。



### 3. podspec语法

##### (1) `s.source_files`    
在Build Phases的Compile Sources中添加源文件（.m/.mm/.cpp等）

```
s.source_files = [
	'AwesomeSDK/Classes/**/*',
	'../SourceFiles/*.{h,cpp}', # Error: won't include SourceFiles folder
]
```

source_files的路径是以podspec所在文件夹为root的相对路径，但是指定的路径不超过root之外的路径[^2]，例如'../SourceFiles/*.{h,cpp}'，将不会加入Pods.xcodeproj中。

Tips: 
> 
1. 文件名匹配，*.{a,b,c,..,z}之间的逗号不能有空格，否则会忽略后面的匹配

##### (2)`s.`

References
--
[^1]: https://github.com/CocoaPods/CocoaPods/issues/2313
[^2]: https://github.com/CocoaPods/CocoaPods/issues/1259
