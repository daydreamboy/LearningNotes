## git手册

[TOC]



----------------------

### 1. stash

格式：git stash \<subcommand\>    
说明：管理本地stash，常用子命令有list

* git stash list，查看stash列表

```
$ git stash list --date=local
stash@{Mon Apr 16 15:09:01 2018}: On release/180427/master: temp2
stash@{Tue Apr 3 19:17:27 2018}: On release/180427/master: temp3
```

>
--date=local，显示存储的时间



### 2. git选项

* --exec-path，输出git-core目录

```
$ git --exec-path
/Applications/Xcode.app/Contents/Developer/usr/libexec/git-core
```





