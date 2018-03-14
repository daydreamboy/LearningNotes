# MacOS Command Notes
--

### 1. grep

格式：`grep [options] <pattern> <path/to/folder or file>`

* `-r`，递归查找子文件夹。默认只在指定文件夹下查找，而不在它的所有子文件夹下查找
* `-n`，输出匹配位置所在文件中的行号
* `-i`，忽略查找字符串的大写敏感
* `-l`，输出匹配文件的相对路径，相对于指定路径
* `-C<number>`[^3]，显示上下文line的个数
* `-A<number>`[^3]，显示上文line的个数
* `-B<number>`[^3]，显示下文line的个数

示例

* 在文件中搜索指定文本

```
grep -r 'pjson' /usr/local/Cellar/chisel/1.5.0/libexec/commands 
```

输出

/usr/local/Cellar/chisel/1.5.0/libexec/commands/FBPrintCommands.py:    return 'pjson'

* 当前目录下递归搜索delete文件夹并删除它 [^1] [^2]

```
find . -d -name "delete" -exec rm -r "{}" \;
```

* 递归搜索某个文件夹下所有文件包含特定字符串   
 
```
grep -rni "string" *
```
>
r，递归查找子文件夹    
n，输出行号    
i，大小写不敏感    

* 在某个目录下，对所有文件的内容进行字符串替换

```
grep -rl matchstring somedir/ | xargs sed -i 's/string1/string2/g'
```

### 2. pgrep

释义：process grep    
说明：在当前系统进程表中进行grep搜索   
示例：

```
$ pgrep debugserver
34486
```

* pgrep -x，准确匹配进程名（不包含子字符串）

* pgrep -fl，匹配进程名，并显示进程的启动参数

```
$ pgrep -fl lldb
38439 /Applications/Xcode-beta.app/Contents/Developer/usr/bin/lldb
93787 /Applications/Xcode.app/Contents/SharedFrameworks/LLDBRPC.framework/Resources/lldb-rpc-server --unix-fd 65 --fd-passing-socket 67
98211 sudo lldb -n helloptrace -w
98212 /Applications/Xcode-beta.app/Contents/Developer/usr/bin/lldb -n helloptrace -w
```

### 3. ps

释义：process status    
说明：输出进程的状态    
示例：

* ps，输出当前用户的所有进程信息

* ps -a，输出所有用户的所有进程信息，但是忽略哪些没有controlling terminal的进程

* ps -A，输出所有用户的所有进程信息，包括哪些没有controlling terminal的进程

* ps -f，显示各个字段的信息（UID、PID、PPID等）

* ps -p \<PID\>，输出匹配特定PID进程的信息

* 查找某个进程的启动参数

```
$ ps -fp `pgrep -x debugserver`
  UID   PID  PPID   C STIME   TTY           TIME CMD
  501 34934 34933   0  9:12PM ttys053    0:00.20 /Applications/Xcode-beta.app/Contents/SharedFrameworks/LLDB.framework/Resources/debugserver --native-regs --setsid --reverse-connect 127.0.0.1:61096
``` 

* ps -o field= \<PID\>，输出特定PID进程的某个指定field

```
$ ps -o ppid= $(pgrep -x debugserver)
36552
$ ps -fp `pgrep -x debugserver`      
  UID   PID  PPID   C STIME   TTY           TIME CMD
  501 36553 36552   0 10:21AM ttys053    0:00.21 /Applications/Xcode-beta.app/Contents/SharedFrameworks/LLDB.framework/Resources/debugserver --native-regs --setsid --reverse-connect 127.0.0.1:62479
```


References
--

[^1]: [grep - How can I recursively search for directory names with a particular string where the string is only part of the directory name - Ask Ubuntu](https://askubuntu.com/questions/153144/how-can-i-recursively-search-for-directory-names-with-a-particular-string-where)

[^2]: [rm - How to delete directories based on `find` output? - Unix & Linux Stack Exchange](https://unix.stackexchange.com/questions/89925/how-to-delete-directories-based-on-find-output)

[^3]: https://unix.stackexchange.com/questions/66196/how-to-run-grep-and-show-x-number-of-lines-before-and-after-the-match