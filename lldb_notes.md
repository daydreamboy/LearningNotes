## lldb手册

TOC

1. print
2. po（print object）
3. print/<fmt>
4. expression
5. continue
6. thread
7. type（TODO）
8. finish
9. frame
10. breakpoint set -r
11. breakpoint list
12. breakpoint set
13. 执行简单的代码片段
14. 设置UIView的frame
15. TODO
16. lldb attach进程
17. lldb target
18. lldb查看命令帮助
19. lldb启动可执行文件
20. lldb常用快捷键
21. image
22. run

----------------------


### 1、print

格式：print <expression>    
简写：p     
说明：print是expression --的别名，后面不能加选项    
例子：    

```
(lldb) p @[@"foo", @"bar"]
(__NSArrayI *) $4 = 0x00000001028010f0 @"2 elements"
```

### 2、po（print object）

格式：po <expression>    
简写：po    
说明：po是expression -O --的别名，用于调用对象的debugDescription方法    
例子：

```
(lldb) e -O -- $4
<__NSArrayI 0x1028010f0>(
foo,
bar
)
```

### 3、print/\<fmt\>

格式：    

* p/x，以十六进制打印
* p/t，以二进制打印，t代表two
* p/d，以十进制打印
* 其他的有p/c，p/s等

例子：

```
(lldb) p 16
(int) $5 = 16
(lldb) p/x 16
(int) $6 = 0x00000010
(lldb) p/t 16
(int) $7 = 0b00000000000000000000000000010000
(lldb) p/t (char)16
(char) $8 = 0b00010000
```

### 4、expression
格式：expression <expression>    
简写：e    
说明：expression是比较复杂的命令，后面可以加选项。     
例子：

* 执行表达式

```
(lldb) e int $a = 2
(lldb) e $a
(int) $a = 2
(lldb) e $a * 19
(int) $0 = 38
(lldb) e NSArray *$array = @[ @"Saturday", @"Sunday", @"Monday" ]
(lldb) e $array
(__NSArrayI *) $array = 0x0000000100700ee0 @"3 elements"
(lldb) p $array
(__NSArrayI *) $array = 0x0000000100700ee0 @"3 elements"
(lldb) po $array
<__NSArrayI 0x100700ee0>(
Saturday,
Sunday,
Monday
)
```

* expression对方法的返回值严格检查，需要加上返回值类型

```
(lldb) e [[$array objectAtIndex:0] uppercaseString]
error: no known method '-uppercaseString'; cast the message send to the method's return type
(lldb) e (NSString *)[[$array objectAtIndex:0] uppercaseString]
(NSTaggedPointerString *) $1 = 0x005325e6621cbe85 @"SATURDAY"
```

* 执行简单的代码片段

```
(lldb) e char *$str = (char *)malloc(8)
(lldb) e $str
(char *) $str = 0x0000000100100020 <no value available>
(lldb) e (void)strcpy($str, "munkeys")
(lldb) e $str
(char *) $str = 0x0000000100100020 "munkeys"
(lldb) e $str[1] = 'o'
(char) $0 = 'o'
(lldb) e $str
(char *) $str = 0x0000000100100020 "monkeys"
(lldb) x/4c $str
error: reading memory as characters of size 4 is not supported
(lldb) x/c $str
0x100100020: monk
(lldb) x/1w `$str + 3`
0x100100023: keys
(lldb) e (void)free($str)
(lldb) e $str
(char *) $str = 0x0000000100100020 "monkeys"
```

* 设置UIView的frame

```
e [v setFrame:(CGRect){0, 0, 100, 100}] 
```

参考：   
https://stackoverflow.com/questions/27533709/how-to-set-the-frame-of-a-uiview-at-runtime-using-lldb-expr-debugging-console

* 执行方法，触发breakpoint

格式：expr -i 0 -- \<objC code\>    
说明：    
调试时lldb默认不会触发Xcode设置的breakpoint。

```
expr -i 0 -- [self areaNbr]
```

参考：    
https://stackoverflow.com/questions/35861198/xcode-not-stopping-on-breakpoint-in-method-called-from-lldb

### 5、continue

格式：continue    
简写：c     
continue不带参数，是process continue的别名。debug时，代表当前进程恢复执行

### 6、thread

##### (1) 当前线程单步执行

格式：thread step-over    
简写：n，next    
n不带参数。debug时，代表单步执行

##### (2) 当前线程单步进入函数

格式：thread step-in    
简写：s，step    
s不带参数。debug时，代表单步进入    
补充：   
1) 和thread step-in相反的操作，跳出函数，则是finish命令     
2) step -a0，忽略lldb设置，总是单步进入

##### (3) 当前线程中止后面的执行，提前返回到函数入口

格式：thread return <optional retVal>    
thread return带一个可选的返回值，如果执行，当前函数立即返回，剩下的代码不会执行。     
注意：和finish不一样，finish是执行完当前函数才返回。由于提前返回，有可能ARC相关内存问题

##### (4) 列出当前所有线程

格式：thread list

```
(lldb) thread list
Process 15767 stopped
* thread #1: tid = 0x5bf9ba, 0x000000010ff0cf10 Commons`__34+[UnixSignalHandler sharedHandler]_block_invoke((null)=0x0000000113cc8470) at UnixSignalHandler.m:68, queue = 'com.apple.main-thread', stop reason = breakpoint 1.1
  thread #2: tid = 0x5bfa09, 0x0000000115fa5562 libsystem_kernel.dylib`__workq_kernreturn + 10
  thread #3: tid = 0x5bfa0a, 0x0000000115fa5562 libsystem_kernel.dylib`__workq_kernreturn + 10
  thread #4: tid = 0x5bfa0b, 0x0000000115fdac40 libsystem_pthread.dylib`start_wqthread
  thread #5: tid = 0x5bfa0c, 0x0000000115fa5562 libsystem_kernel.dylib`__workq_kernreturn + 10
  thread #6: tid = 0x5bfa13, 0x0000000115f9b7c2 libsystem_kernel.dylib`mach_msg_trap + 10, name = 'com.apple.uikit.eventfetch-thread'
  thread #8: tid = 0x5bfa15, 0x0000000115fa5562 libsystem_kernel.dylib`__workq_kernreturn + 10
```

### 7、TODO

### 8、finish

格式：finish    
说明：debug时，代表执行完当前函数或者方法，然后跳到调用处    
参考资料：    
https://www.objc.io/issues/19-debugging/lldb-debugging/

### 9、frame

##### (1) 显示当前执行点的信息，例如对应源文件的行号等

格式：frame info    

```
(lldb) frame info
frame #0: 0x0000000100000ecf flow_control`main(argc=1, argv=0x00007fff5fbff7e0) + 63 at main.m:25
```

##### (2) 查看特定的frame。 

格式：frame select <frame No.>    
说明：frame info只显示第0个frame。这里的序号，对应thread backtrace输出的frame序号。

```
(lldb) frame select 1
frame #1: 0x0000000115b1533d libdispatch.dylib`_dispatch_client_callout + 8
libdispatch.dylib`_dispatch_client_callout:
    0x115b1533d <+8>:  addq   $0x8, %rsp
    0x115b15341 <+12>: popq   %rbx
    0x115b15342 <+13>: popq   %rbp
    0x115b15343 <+14>: retq 
```

##### (3) 查看当前frame的所有变量

格式：frame variable

```
(lldb) frame variable
(__block_literal_1 *)  = 0x0000000113cc8470
```

##### (4) 查看特定变量

格式：frame variable -F self

### 10、breakpoint set -r

格式：breakpoint set -r <reg exp>    
简写：rb <reg exp>    
说明：正则匹配符号，设置断点

* 匹配特定的符号

```
(lldb) rb SwiftTestClass.name.setter
(lldb) rb name\.setter
(lldb) rb '\-\[UIViewController\ '
```

* 匹配所有的符号

```
(lldb) rb .
```

* 匹配在特定module中所有的符号

```
(lldb) rb . -s UIKit
```

* 匹配在特定module中所有的符号，而且断点是一次性的

```
(lldb) rb . -s UIKit -o
```

### 11、breakpoint list

格式：breakpoint list    
简写：br li    
说明：显示当前所有文件的断点（包括多个target）    
例子：

```
(lldb) br li
Current breakpoints:
1: file = '/Users/arig/Desktop/DebuggerDance/DebuggerDance/main.m', line = 16, locations = 1, resolved = 1, hit count = 1

  1.1: where = DebuggerDance`main + 27 at main.m:16, address = 0x000000010a3f6cab, resolved, hit count = 1
```

### 12、breakpoint enable/disable \<breakpointID\>

格式：breakpoint enable/disable \<breakpointID\>    
说明：启用和禁用某个断点
例子：

```
(lldb) br dis 1
1 breakpoints disabled.
(lldb) br li
Current breakpoints:
1: file = '/Users/arig/Desktop/DebuggerDance/DebuggerDance/main.m', line = 16, locations = 1 Options: disabled

  1.1: where = DebuggerDance`main + 27 at main.m:16, address = 0x000000010a3f6cab, unresolved, hit count = 1
```

```
(lldb) br del 1
1 breakpoints deleted; 0 breakpoint locations disabled.
(lldb) br li
No breakpoints currently set.
```

### 13、breakpoint set

例子：

* 指定文件和行号，设置断点

```
(lldb) breakpoint set -f main.m -l 16
Breakpoint 1: where = DebuggerDance`main + 27 at main.m:16, address = 0x000000010a3f6cab

(lldb) b main.m:17
Breakpoint 2: where = DebuggerDance`main + 52 at main.m:17, address = 0x000000010a3f6cc4
```

* 指定C函数的符号，设置断点

```
(lldb) b isEven
Breakpoint 3: where = DebuggerDance`isEven + 16 at main.m:4, address = 0x000000010a3f6d00
(lldb) br s -F isEven
Breakpoint 4: where = DebuggerDance`isEven + 16 at main.m:4, address = 0x000000010a3f6d00
```

* 指定OC方法的符号，设置断点

```
(lldb) breakpoint set -F "-[NSArray objectAtIndex:]"
Breakpoint 5: where = CoreFoundation`-[NSArray objectAtIndex:], address = 0x000000010ac7a950
(lldb) b -[NSArray objectAtIndex:]
Breakpoint 6: where = CoreFoundation`-[NSArray objectAtIndex:], address = 0x000000010ac7a950
(lldb) breakpoint set -F "+[NSSet setWithObject:]"
Breakpoint 7: where = CoreFoundation`+[NSSet setWithObject:], address = 0x000000010abd3820
(lldb) b +[NSSet setWithObject:]
Breakpoint 8: where = CoreFoundation`+[NSSet setWithObject:], address = 0x000000010abd3820
```

注意：上面的命令方式，仅在当前debug session中生效，并没有同步到Xcode的breakpoint中

* 设置断点的action，以及触发条件

```
(lldb) breakpoint set -F isEven
Breakpoint 1: where = DebuggerDance`isEven + 16 at main.m:4, address = 0x00000001083b5d00
(lldb) breakpoint modify -c 'i == 99' 1
(lldb) breakpoint command add 1
Enter your debugger command(s).  Type 'DONE' to end.
> p i
> DONE
(lldb) br li 1
1: name = 'isEven', locations = 1, resolved = 1, hit count = 0
    Breakpoint commands:
      p i

Condition: i == 99

  1.1: where = DebuggerDance`isEven + 16 at main.m:4, address = 0x00000001083b5d00, resolved, hit count = 0 
```

* 设置断点，触发后继续执行

```
(lldb) breakpoint set -F isEven
Breakpoint 1: where = DebuggerDance`isEven + 16 at main.m:4, address = 0x00000001083b5d00
(lldb) breakpoint command add 1
Enter your debugger command(s).  Type 'DONE' to end.
> continue
> DONE
(lldb) br li 1
1: name = 'isEven', locations = 1, resolved = 1, hit count = 0
    Breakpoint commands:
      continue

  1.1: where = DebuggerDance`isEven + 16 at main.m:4, address = 0x00000001083b5d00, resolved, hit count = 0
```

* 删除断点

```
(lldb) br list
Current breakpoints:
1: name = '-[NSViewController viewDidLoad]', locations = 1, resolved = 1, hit count = 1

  1.1: where = AppKit`-[NSViewController viewDidLoad], address = 0x00007fff2d6e864a, resolved, hit count = 1 

2: name = '-[NSResponder mouseUp:]', locations = 1, resolved = 1, hit count = 1
  2.1: where = AppKit`-[NSResponder mouseUp:], address = 0x00007fff2d8d2f93, resolved, hit count = 1 

3: name = 'list', locations = 9, resolved = 9, hit count = 0
  3.1: where = Security`Security::ListElement::list(), address = 0x00007fff3bd30c68, resolved, hit count = 0 
  3.2: where = SharedFileList`-[SFLListObserver list], address = 0x00007fff318735e0, resolved, hit count = 0 
  3.3: where = CoreGraphics`std::__1::list<CG::Chunk, CG::Allocator<CG::Chunk> >::list(std::__1::list<CG::Chunk, CG::Allocator<CG::Chunk> > const&), address = 0x00007fff304ea24e, resolved, hit count = 0 
  3.4: where = SkyLight`std::__1::list<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, std::__1::allocator<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > > >::list(std::initializer_list<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > >), address = 0x00007fff51938f44, resolved, hit count = 0 
  3.5: where = SceneKit`daeURIResolverList::list(), address = 0x00007fff3b6937c4, resolved, hit count = 0 
  3.6: where = GeoServices`std::__1::list<GEOPDLocalTimeRange, std::__1::allocator<GEOPDLocalTimeRange> >::list(std::__1::list<GEOPDLocalTimeRange, std::__1::allocator<GEOPDLocalTimeRange> > const&), address = 0x00007fff4931b058, resolved, hit count = 0 
  3.7: where = QuartzComposer`+[GFList list], address = 0x00007fff3ab7cc88, resolved, hit count = 0 
  3.8: where = QuartzComposer`daeURIResolverList::list(), address = 0x00007fff3af464d6, resolved, hit count = 0 
  3.9: where = CorePDF`-[CPListItem list], address = 0x00007fff436fbe22, resolved, hit count = 0 

(lldb) br delete
About to delete all breakpoints, do you want to do that?: [Y/n] Y
All breakpoints removed. (3 breakpoints)
```


15、TODO


16、lldb attach进程

格式：lldb -n \<process name\>

```
$ lldb -n Finder
(lldb) process attach --name "Finder"
error: attach failed: cannot attach to process due to System Integrity Protection
```

一般不能debug经过Apple签名的程序，需要禁用System Integrity Protection。    
步骤如下：

* 重启macOS，屏幕变黑时，按住⌘+R直到出现Logo
* Utilities -> Terminal，输入`csrutil disable; reboot`

17、target

lldb中有target概念，指的是调试的目标，可以存在多个调试目标。直接输入lldb，进入lldb调试，没有任何target。

```
(lldb) target list
No targets.
```

target有几个子命令

* target create，指定到一个可执行文件，创建target。有别名file命令。

```
(lldb) target create -d /Applications/Xcode.app/Contents/MacOS/Xcode
Current executable set to '/Applications/Xcode.app/Contents/MacOS/Xcode' (x86_64).
```

或者

```
(lldb) file /Applications/Xcode.app/Contents/MacOS/Xcode
Current executable set to '/Applications/Xcode.app/Contents/MacOS/Xcode' (x86_64).
```

* target list，列出所有的target

```
(lldb) target list
Current targets:
  target #0: <none> ( platform=host )
  target #1: <none> ( platform=host )
* target #2: /Applications/Xcode.app/Contents/MacOS/Xcode ( arch=x86_64-apple-macosx, platform=host )
```

* target delete，删除某个target

```
(lldb) target delete 0
1 targets deleted.
```

* target select，设置当前target

```
(lldb) target select 1
Current targets:
  target #0: <none> ( platform=host )
* target #1: /Applications/Xcode.app/Contents/MacOS/Xcode ( arch=x86_64-apple-macosx, platform=host )
```

18、lldb查看命令帮助

* 查看命令帮助

```
(lldb) help <command>
```

* 查看子命令帮助

```
(lldb) help <command> <subcommand>
```

19、lldb启动可执行文件

```
(lldb) process launch -e /dev/ttys027 --
```

* 启动当前target，结合target命令使用
* -e，将stderr定向到/dev/ttys027文件

20、lldb常用快捷键

* Ctrl + c，暂停当前进程

21、image

格式：image <subcommand>    
例子：

* 列出所有module

```
(lldb) image list
[  0] 65E8199C-E9B4-3A6D-8800-84FFFFDE0C19 0x0000000104b8d000 /Users/wesley_chen/Library/Developer/Xcode/DerivedData/Signals-ezwjdgxtmgvixuaawmjotragooie/Build/Products/Debug-iphonesimulator/Signals.app/Signals 
[  1] 6695F30B-4E88-3C0B-9867-7D738C44A3E6 0x0000000108cab000 /usr/lib/dyld 
[  2] 0846E6B8-AF93-38F4-86B8-EE1548F71A43 0x0000000104bbc000 /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/Library/CoreSimulator/Profiles/Runtimes/iOS.simruntime/Contents/Resources/RuntimeRoot/usr/lib/dyld_sim 
```

* 查看特定的module

```
(lldb) image list Foundation
[  0] AFD58A66-011A-3575-8D12-AC868A4D0157 0x0000000104eb1000 /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/Library/CoreSimulator/Profiles/Runtimes/iOS.simruntime/Contents/Resources/RuntimeRoot/System/Library/Frameworks/Foundation.framework/Foundation 
```

说明：   
输出格式，如`<UUID> <load address> <binary file path>`

>
UUID，image的唯一标识符，用于查找对应的符号信息    
load address，在进程的内存空间中的加载地址    
binary file path，二进制文件的文件路径

* 查看特定module的符号信息

```
(lldb) image dump symtab UIKit -s address
```

说明：    
-s address，表示按照address排序

* 搜索特定的符号信息

格式：image lookup -n <string>

```
(lldb) image lookup -n "-[UIViewController viewDidLoad]"
1 match found in /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/Library/CoreSimulator/Profiles/Runtimes/iOS.simruntime/Contents/Resources/RuntimeRoot/System/Library/Frameworks/UIKit.framework/UIKit:
        Address: UIKit[0x00000000001d1df6] (UIKit.__TEXT.__text + 1900502)
        Summary: UIKit`-[UIViewController viewDidLoad]
```

* 正则匹配搜索特定的符号信息
格式：image lookup -rn <reg exp>

```
(lldb) image lookup -rn UIViewController
(lldb) image lookup -rn '\[UIViewController\ '
(lldb) image lookup -rn '\[UIViewController\(\w+)\ '
```

* 正则匹配搜索的block符号

格式：`image lookup -rn <function name>_block_invoke_<order number> <module name>`

>
\_block\_invoke，是block的符号    
function name，是block所在的函数    
order number，如果函数中有多个block，则number是序号，但是第一个block序号不是0或1，而直接是<function name>\_block\_invoke，第二个block则是<function name>\_block\_invoke\_2。注意是从2开始的。    
module name，指定特定module    

```
(lldb) image lookup -rn _block_invoke
(lldb) image lookup -rn _block_invoke Commons
6 matches found in /Users/wesley_chen/Library/Developer/Xcode/DerivedData/Signals-ezwjdgxtmgvixuaawmjotragooie/Build/Products/Debug-iphonesimulator/Signals.app/Frameworks/Commons.framework/Commons:
        Address: Commons[0x0000000000002340] (Commons.__TEXT.__text + 1216)
        Summary: Commons`__32-[UnixSignalHandler initPrivate]_block_invoke at UnixSignalHandler.m:78        Address: Commons[0x00000000000025b0] (Commons.__TEXT.__text + 1840)
        Summary: Commons`__32-[UnixSignalHandler initPrivate]_block_invoke.27 at UnixSignalHandler.m:105        Address: Commons[0x0000000000001f00] (Commons.__TEXT.__text + 128)
        Summary: Commons`__34+[UnixSignalHandler sharedHandler]_block_invoke at UnixSignalHandler.m:67        Address: Commons[0x0000000000002770] (Commons.__TEXT.__text + 2288)
        Summary: Commons`__38-[UnixSignalHandler appendSignal:sig:]_block_invoke at UnixSignalHandler.m:119        Address: Commons[0x00000000000027b0] (Commons.__TEXT.__text + 2352)
        Summary: Commons`__38-[UnixSignalHandler appendSignal:sig:]_block_invoke_2 at UnixSignalHandler.m:123        Address: Commons[0x0000000000002b30] (Commons.__TEXT.__text + 3248)
        Summary: Commons`__38-[UnixSignalHandler appendSignal:sig:]_block_invoke_3 at UnixSignalHandler.m:135
```

22、run

```
(lldb) run
```

说明：不编译app，直接重新启动app

