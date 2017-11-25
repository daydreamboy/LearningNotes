# grep Notes
--

### 1. grep选项

格式：`grep [options] <pattern> <path/to/folder or file>`

* `-r`，递归查找子文件夹。默认只在指定文件夹下查找，而不在它的所有子文件夹下查找
* `-n`，输出匹配位置所在文件中的行号
* `-i`，忽略查找字符串的大写敏感
* `-l`，输出匹配文件的相对路径，相对于指定路径

### 2. grep示例

##### 2.1 在文件中搜索指定文本

```
grep -r 'pjson' /usr/local/Cellar/chisel/1.5.0/libexec/commands 
```

输出

/usr/local/Cellar/chisel/1.5.0/libexec/commands/FBPrintCommands.py:    return 'pjson'

##### 2.2 当前目录下递归搜索delete文件夹并删除它 [^1] [^2]

```
find . -d -name "delete" -exec rm -r "{}" \;
```

##### 2.3 递归搜索某个文件夹下所有文件包含特定字符串   
 
```
grep -rni "string" *
```
>
r，递归查找子文件夹    
n，输出行号    
i，大小写不敏感    

4、

```
grep -rl matchstring somedir/ | xargs sed -i 's/string1/string2/g'
```

References
--

[^1]: [grep - How can I recursively search for directory names with a particular string where the string is only part of the directory name - Ask Ubuntu](https://askubuntu.com/questions/153144/how-can-i-recursively-search-for-directory-names-with-a-particular-string-where)

[^2]: [rm - How to delete directories based on `find` output? - Unix & Linux Stack Exchange](https://unix.stackexchange.com/questions/89925/how-to-delete-directories-based-on-find-output)