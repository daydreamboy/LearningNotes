# iOS jailbreak

[TOC]



## 1、iOS 9.3.5 jailbreak[^1]

操作步骤

1. Safari打开m.pandahelp.vip/regular，安装描述文件“Panda Helper Lite”，然后继续安装Panda Helper.app
2. 打开Panda Helper.app，搜索Phoenix jailbreak tool，点击install，提示下载安装，完成后桌面多出Phoenix.app
3. 打开Phoenix.app，点击“Prepare For Jailbreak”，一路点下去，出现提示“Device Supported”，选择“Use Provided Offsets”，继续点，最后系统重启，桌面出现Cydia.app，说明越狱OK。



## 2、iOS 10.3.3 jailbreak[^11]

操作步骤

1. Safari打开https://cydia-app.com/panda-helper/，点击“Download Link 1”或者“Download Link 2”，安装描述文件“Panda Helper Lite”，然后继续安装Panda Helper.app
2. 打开Panda Helper.app，搜索h3lix，点击install，提示下载安装，完成后桌面多出h3lix.app
3. 打开h3lix.app，点击“Jailbreak”，系统重启，桌面出现Cydia.app，说明越狱OK。

说明

> 如果设备重启，会恢复到未越狱状态，Cydia等打开会闪退，需要重新打开h3lix.app再次越狱[^16]



## 3、添加源

这里有一些推荐的源[^2]，按需添加，避免添加过多，可能导致系统不稳定



我添加过的源，如下

```
http://apt.abcydia.com (雷锋源）
http://apt.itools.cn (用于安装iTools)
```









## 4、常用工具（通过Cydia安装）

- Cydia Substrate
- MobileTerminal（废弃，改用iOSTerminal）
- OpenSSH
- Vi IMProved
- IPA Installer
- iOS Terminal
- LocationFaker（需要购买，http://www.gottabemobile.com/2015/10/23/how-to-fake-your-location-on-iphone/）
- [Flexible](http://cydia.saurik.com/package/com.shmoopillc.flexible/) (不推荐使用，换成Flipboard FLEX Loader)

* [Flipboard FLEX Loader](https://github.com/XueshiQiao/FLEXLoader)
* [Reveal Loader](https://github.com/heardrwt/RevealLoader)
* [Filza File Manager](http://cydia.saurik.com/package/com.tigisoftware.filza/)
* Filza File 文件管理器
* [Cycript](https://cydia.saurik.com/package/cycript/)
* Apple File Conduit 2



### （1）Cydia Substrate



### （2）Cycript

Cycript是一个命令工具，支持在Console中执行Objective-C++和JavaScript语法的代码，其主页是http://www.cycript.org/



#### 常见用法

##### 注入进程

```shell
bash# cycript -p SpringBoard
cy# <type your Objective-C++/JavaScript code>
```



### （3）Apple File Conduit 2

Apple File Conduit 2解除系统文件夹的一些限制[^15]，安装后，iExplorer、iFunBox、爱思助手等Mac端软件，都可以访问系统根目录。





## 5、iOS Terminal.app常用命令

### （1）killall

让设备重启

```shell
$ killall SpringBoard
```



### （2）ipconfig

获取WiFi的ip地址

```shell
$ ipconfig getifaddr en0
```





## 6、桌面Terminal常用命令

### （1）ssh

#### a. 检查sshd进程是否在运行

```shell
$ ps -A | grep ssh
4558 ??      0:00.00 (sshd)
5547 ttys001 0:00.01 grep ssh
```



#### b. ssh登录

```shell
$ ssh root@192.168.0.107
```



#### c. 开启ssh的verbose模式

```shell
$ ssh -vv root@192.168.0.107
```

可以有多个`-v`，最大支持3个，即`-vvv`，方便显示调试信息，用于诊断连接过程

iOS 



### （2）scp

#### a. 拷贝文件到iOS设备

打开MacOS的Terminal，输入scp命令



* 拷贝文件到远端位置

```shell
$ scp ~/file root@192.168.0.102:/var/mobile/somefolder
```



* 拷贝文件夹到远端位置

```shell
$ scp -r ~/folder root@192.168.0.102:/var/mobile/somefolder
```



#### b. 拷贝iOS设备的文件到本地

System Preferences > Sharing > 勾选Remote Login，然后ssh远程登录到iOS设备，然后输入scp命令

```shell
# scp DingTalk wesley_chen@192.168.0.102:~/Downloads
Password:
DingTalk        100%  103MB   2.2MB/s   00:47
```



### （3）iproxy[^17]

iproxy是usbmuxd工具自带的命令行工具。安装usbmuxd后，就可以使用iproxy

```shell
$ brew install usbmuxd
```

iproxy命令行工具，相当于在本地建立一个iOS设备的代理，好处是：iOS设备和Mac不需要用WiFi通信，即使iOS设备是飞行模式，也可以访问iOS设备。当然iOS设备也需要安装OpenSSH。

建立USB连接的代理，如下

```shell
$ iproxy 5678 22
waiting for connection
```

将iOS设备22端口映射成本地的5678端口。

然后再用ssh登录本地的5678端口，如下

```shell
$ ssh -p 5678 root@127.0.0.1
root@127.0.0.1's password:
```



## 7、通过SSH安装ipa文件[^3][^4]

1. 工具（通过Cydia安装，可能需要翻墙）

- OpenSSH
- IPA Installer

2. 拷贝.ipa文件到/var/mobile/Downloads文件夹下，如下

```shell
$ scp ~/Downloads/Ark\ VPN\ 1.2.1.ipa root@192.168.1.112:/var/mobile/Downloads root@192.168.1.112's password: 
Ark VPN 1.2.1.ipa                      100% 963KB 962.9KB/s  00:00
```

3. IPA Installer在/var/mobile/Downloads打开.ipa文件，将安装.ipa文件



## 8、iOS文件系统[^5]

不同版本的iOS系统，它的文件系统位置可能不一样。



### （1）iOS 9.3.5文件系统

用户app bundle位置是，`/var/containers/Bundle/Application`

```shell
# pwd
/var/containers/Bundle/Application
# ls ./*
./2E886E2E-F617-4530-ABF2-20F633194357:
Phoenix.app/  iTunesArtwork  iTunesMetadata.plist
...
```





### （1）系统app的bundle所在位置

/Applications下的app是系统预装的，不属于沙盒环境



### （2）用户app的bundle所在位置

/var/mobile/Applications下的app是从AppStore上下载安装的，属于沙盒环境



### （3）用户app的沙盒

/var/mobile/Containers/Bundle/Application是应用程序所在的位置，如下图

<img src="iOS_jailbreak_images/用户app的沙盒.png" style="zoom:50%;" />



## 9、使用RevealApp[^7][^8][^9]

1、下载RevealApp客户端（适用于Mac），http://revealapp.com/

2、打开RevealApp，Help->Show Reveal Library in Finder，如下图，找到libReveal.dylib和Reveal.framework两个文件

<img src="iOS_jailbreak_images/RevealApp Help.png" style="zoom:50%;" />



3、iOS越狱设备，使用Cydia安装Substrate，如下图，确保 /Library/MobileSubstrate/目录存在

<img src="iOS_jailbreak_images/Cydia Substrate.png" style="zoom:50%;" />



3、准备libReveal.plist文件，填写要监视App的bundle identifier（同步推等工具可以查看App的bundle identifier）

```
{
Filter = {
Bundles = (
"com.apple.AppStore"
);
};
}
```



4、拷贝注入文件（SSH、同步推等工具）

- libReveal.plist -> /Library/MobileSubstrate/DynamicLibraries
- libReveal.dylib -> /Library/MobileSubstrate/DynamicLibraries
- Reveal.framework -> /System/Library/Frameworks

使用scp命令拷贝文件和文件夹

```shell
$ scp -r Reveal.framework root@x.x.x.x:/System/Library/Frameworks
$ scp libReveal.dylib root@x.x.x.x:/Library/MobileSubstrate/DynamicLibraries
```



5、重启iOS设备，确保RevealApp客户端和iOS设备的所在网络是同一个WiFi局域网，选择监视的App，如下图

<img src="iOS_jailbreak_images/使用RevealApp.png" style="zoom:50%;" />





## 10、iPod Touch显示电池百分比[^10]

iPod Touch系统本身没有显示电池百分比的开关，越狱后可以将百分比显示出来。步骤如下：

1、使用PP助手，找到/var/mobile/Library/Preferences/目录，找到com.apple.springboard.plist文件，将其导出到本地

<img src="iOS_jailbreak_images/com.apple.springboard.plist文件.png" style="zoom:50%;" />



2、添加键值SBShowBatteryLevel=YES，如下

<img src="iOS_jailbreak_images/SBShowBatteryLevel=YES.png" style="zoom:50%;" />

3、重新启动设备，就可以看到电池百分比

<img src="iOS_jailbreak_images/电池百分比.png" style="zoom:50%;" />









## 11、分析Keychain

Keychain是一个sqlite3数据库，位于/private/var/Keychains/keychain-2.db

In iOS, keychain items are classified into 5 classes – generic passwords (kSecClassGenericPassword), internet passwords (kSecClassInternetPassword), certificates (kSecClassCertificate), keys (kSecClassKey) and digital identities (kSecClassIdentity, identity=certificate + key)

Note: On iPhone, Keychain rights depend on the provisioning profile used to sign your application. Be sure to consistently use the same provisioning profile across different versions of your application.[^6]





## 12、iOS越狱设备的补充知识

### （1）iOS系统的用户

两个用户root和mobile，越狱后密码默认是alpine



### （2）app砸壳[^12]

​         从App store下载到ipa文件都是经过Apple加密的，是没有办法重签名的。如果把这个加密去掉，则称为app砸壳。砸壳使用的工具是[dumpdecrypted](https://link.jianshu.com?t=https://github.com/stefanesser/dumpdecrypted)，原理就是让app预先加载一个dumpdecrypted.dylib，然后在程序运行时，将代码动态解密，最后在内存中dump出来整个程序。当然砸壳是需要在越狱环境下进行的[^13]。



#### a. 检查是否已经砸壳

以DingTalk 5.0.16.ipa为例，可以通过App Configurator2下载ipa文件。

```shell
$ file DingTalk
DingTalk: Mach-O universal binary with 2 architectures: [arm_v7:Mach-O executable arm_v7] [arm64]
DingTalk (for architecture armv7):	Mach-O executable arm_v7
DingTalk (for architecture arm64):	Mach-O 64-bit executable arm64
$ otool -l DingTalk | grep -B 2 cryptid
     cryptoff 16384
    cryptsize 73580544
      cryptid 1
--
     cryptoff 16384
    cryptsize 78233600
      cryptid 1
```

cryptid值是1，说明两个架构都没有去掉加密。如果cryptid值是0，则说明已经砸壳过了。





#### b. 编译dumpdecrypted源码

[dumpdecryted工具](https://github.com/stefanesser/dumpdecrypted)，使用源码编译，生成dumpdecrypted.dylib文件。编译如下

```shell
$ make   
`xcrun --sdk iphoneos --find gcc` -Os  -Wimplicit -isysroot `xcrun --sdk iphoneos --show-sdk-path` -F`xcrun --sdk iphoneos --show-sdk-path`/System/Library/Frameworks -F`xcrun --sdk iphoneos --show-sdk-path`/System/Library/PrivateFrameworks -arch armv7 -arch armv7s -arch arm64 -c -o dumpdecrypted.o dumpdecrypted.c 
`xcrun --sdk iphoneos --find gcc` -Os  -Wimplicit -isysroot `xcrun --sdk iphoneos --show-sdk-path` -F`xcrun --sdk iphoneos --show-sdk-path`/System/Library/Frameworks -F`xcrun --sdk iphoneos --show-sdk-path`/System/Library/PrivateFrameworks -arch armv7 -arch armv7s -arch arm64 -dynamiclib -o dumpdecrypted.dylib dumpdecrypted.o
ld: warning: directory not found for option '-F/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS13.4.sdk/System/Library/PrivateFrameworks'
ld: warning: directory not found for option '-F/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS13.4.sdk/System/Library/PrivateFrameworks'
ld: warning: directory not found for option '-F/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS13.4.sdk/System/Library/PrivateFrameworks'
$ file dumpdecrypted.dylib 
dumpdecrypted.dylib: Mach-O universal binary with 3 architectures: [arm_v7:Mach-O dynamically linked shared library arm_v7] [arm_v7s:Mach-O dynamically linked shared library arm_v7s] [arm64:Mach-O 64-bit dynamically linked shared library arm64]
dumpdecrypted.dylib (for architecture armv7):	Mach-O dynamically linked shared library arm_v7
dumpdecrypted.dylib (for architecture armv7s):	Mach-O dynamically linked shared library arm_v7s
dumpdecrypted.dylib (for architecture arm64):	Mach-O 64-bit dynamically linked shared library arm64
```



#### c. 对dumpdecrypted.dylib签名

```shell
$ security find-identity -v -p codesigning
...
$ codesign --force --verify --verbose --sign "iPhone Developer: xxx@yy.com (ZZZ)" dumpdecrypted.dylib
dumpdecrypted.dylib: signed Mach-O universal (armv7 armv7s arm64) [dumpdecrypted]
```



#### d.使用dumpdecrypted.dylib

* 查找目标app的沙盒目录

启动目标app，然后执行ps命令，找到目标app的进程ID，如下

```shell
# ps -e | grep -i dingtalk
 4535 ??         0:22.91 /var/containers/Bundle/Application/E002E76D-66F6-4E37-BB26-37E568DEC8F4/DingTalk.app/DingTalk
 4591 ttys000    0:00.01 grep -i dingtalk
# cycript -p 4790
cy# [[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask][0]
#"file:///var/mobile/Containers/Data/Application/B4D9A9BF-DA64-4355-B005-EDBB0F6602F0/Documents/"
Ctrl+d
```

这里使用到cycript命令行工具（可以使用Cydia安装Cycript），它允许注入某个app进程，然后交互式执行Objective-C代码。通过执行OC代码，可以拿到进程的Documents目录。



* 拷贝dumpdecrypted.dylib到目标app的沙盒Document

```shell
$ scp dumpdecrypted.dylib root@192.168.0.107:/var/mobile/Containers/Data/Application/B4D9A9BF-DA64-4355-B005-EDBB0F6602F0/Documents
root@192.168.0.107's password: 
dumpdecrypted.dylib      100%  260KB 821.2KB/s   00:00
```



* 执行目标app

```shell
# ls -l dumpdecrypted.dylib 
-rwxr-xr-x 1 root mobile 266272 May  4 23:43 dumpdecrypted.dylib
# su mobile
$ cd /var/mobile/Containers/Data/Application/B4D9A9BF-DA64-4355-B005-EDBB0F6602F0/Documents/
$ DYLD_INSERT_LIBRARIES=dumpdecrypted.dylib /var/containers/Bundle/Application/E002E76D-66F6-4E37-BB26-37E568DEC8F4/DingTalk.app/DingTalk
objc[4931]: Class XXX is implemented in both /private/var/containers/Bundle/Application/E002E76D-66F6-4E37-BB26-37E568DEC8F4/DingTalk.app/Frameworks/DTExtBasicFramework.framework/DTExtBasicFramework and /var/containers/Bundle/Application/E002E76D-66F6-4E37-BB26-37E568DEC8F4/DingTalk.app/DingTalk. One of the two will be used. Which one is undefined.
...
mach-o decryption dumper

DISCLAIMER: This tool is only meant for security research purposes, not for application crackers.

[+] detected 32bit ARM binary in memory.
[+] offset to cryptid found: @0x13c60(from 0x13000) = c60
[+] Found encrypted data at address 00004000 of length 73580544 bytes - type 1.
[+] Opening /private/var/containers/Bundle/Application/E002E76D-66F6-4E37-BB26-37E568DEC8F4/DingTalk.app/DingTalk for reading.
[+] Reading header
[+] Detecting header type
[+] Executable is a plain MACH-O image
[+] Opening DingTalk.decrypted for writing.
[+] Copying the not encrypted start of the file
[+] Dumping the decrypted data into the file
[+] Copying the not encrypted remainder of the file
[+] Setting the LC_ENCRYPTION_INFO->cryptid to 0 at offset c60
[+] Closing original file
[+] Closing dump file
```

注意：一定要mobile用户执行app，使用root总是执行失败提示“Killed: 9”



* 检查目标app.decrypted文件

```shell
$ ls -l DingTalk.decrypted
-rw-r--r-- 1 mobile mobile 107507856 May  4 23:53 DingTalk.decrypted
```



#### e.使用dumpdecrypted.dylib通用方法[^14]

上面这种方法，比较繁琐，而且实际上有些步骤不需要。这里介绍比较通用的方法。

* 将dumpdecrypted.dylib拷贝到/usr/lib

```shell
$ scp dumpdecrypted.dylib root@192.168.0.107:/usr/lib
```

* 检查dumpdecrypted.dylib的可执行权限

```shell
# cd /usr/lib
# ls -l dumpdecrypted.dylib 
-rwxr-xr-x 1 root wheel 266272 May  4 23:50 dumpdecrypted.dylib
```

* 用户换成mobile

```shell
# su mobile
```

* cd到mobile用户的Documents目录

```shell
$ cd /var/mobile/Documents
```

> 实际上可以cd到mobile用户有写权限的任意目录。

* 使用绝对路径执行app

```shell
$ DYLD_INSERT_LIBRARIES=/usr/lib/dumpdecrypted.dylib /var/containers/Bundle/Application/59CEB222-4C4D-4A34-BC0F-8D38B9E3853D/MyApp.app/MyApp
```

* 当前目录确认MyApp.decrypted文件，以及cryptid值

```shell
$ otool -l DingTalk.decrypted | grep cryptid
      cryptid 0
```



## 13、使用class-dump

[class-dump](https://github.com/nygard/class-dump)，是用于把Mach-O文件dump出对应的头文件。需要注意的是，加密过ipa包中Mach-O文件，class-dump是用不了的。经过砸壳后Mach-O文件，可以使用class-dump导出对应的头文件[^18]。

```shell
$ class-dump -H -o headers DingTalk.decrypted
```



对于Swift和OC混编的Mach-O文件，需要使用改进版的[class-dump](https://github.com/BlueCocoa/class-dump)。



## 附录

### 1、常用助手网站

爱思助手：https://www.i4.cn/









## References

[^1]:https://www.youtube.com/watch?v=OB6tqa_yYYg
[^2]:https://www.jianshu.com/p/f957d99ab1fb

[^3]:http://iphonecydiaios.com/ipa-installer-install-ipa-files-directly-on-iphone-ipad/
[^4]:http://zhidao.baidu.com/link?url=mlQOAzFhD7bWvuAvwprq2l6T_mOG9eRXrxXpQ6hYcK-5DcryQol2EQjOkG2DfJFIHYrtuCCxaEcG9BFe6HshjKWKXkM0LumhNX3WLDPRtUm
[^5]:https://www.reddit.com/r/jailbreak/comments/2lgxsh/why_cant_i_see_varmobileapplications_in_ifile/
[^6]:http://stackoverflow.com/questions/18911434/will-items-in-ios-keychain-survive-app-uninstall-and-reinstall
[^7]:http://www.zdziarski.com/blog/?p=2361
[^8]:http://c.blog.sina.com.cn/profile.php?blogid=cb8a22ea89000gtw
[^9]:http://blog.csdn.net/yiyaaixuexi/article/details/18220875
[^10]:http://iphone.91.com/tutorial/syjc/140113/21645934.html

[^11]:https://cydia-app.com/ios-10/
[^12]:[http://www.veryitman.com/2018/06/07/iOS-%E9%80%86%E5%90%91-dumpdecrypted-%E7%A0%B8%E5%A3%B3%E8%AE%B0/](http://www.veryitman.com/2018/06/07/iOS-逆向-dumpdecrypted-砸壳记/)
[^13]:https://www.jianshu.com/p/5d353d6db145
[^14]:https://github.com/stefanesser/dumpdecrypted/issues/19#issuecomment-239705313
[^15]:[http://www.veryitman.com/2018/05/13/iOS-%E9%80%86%E5%90%91-%E6%9F%A5%E7%9C%8B%E7%B3%BB%E7%BB%9F%E6%96%87%E4%BB%B6%E7%9B%AE%E5%BD%95%E5%92%8C%E7%BB%93%E6%9E%84/](http://www.veryitman.com/2018/05/13/iOS-逆向-查看系统文件目录和结构/)

[^16]:https://zhuanlan.zhihu.com/p/35900648
[^17]:[http://www.veryitman.com/2018/05/12/iOS-%E9%80%86%E5%90%91-%E8%B6%8A%E7%8B%B1%E4%BD%BF%E7%94%A8-SSH/](http://www.veryitman.com/2018/05/12/iOS-逆向-越狱使用-SSH/)
[^18]:[http://www.veryitman.com/2019/04/07/dumpdecrypted-%E7%A0%B8%E5%A3%B3%EF%BC%9A%E5%AF%BC%E5%87%BA%E5%A4%B4%E6%96%87%E4%BB%B6/](http://www.veryitman.com/2019/04/07/dumpdecrypted-砸壳：导出头文件/)















