# git手册

[TOC]

## 1、git选项

### `--exec-path`

作用：输出git-core目录

示例：

```
$ git --exec-path
/Applications/Xcode.app/Contents/Developer/usr/libexec/git-core
```





## 2、git命令

### 1. stash

格式：`git stash \<subcommand\>`

说明：管理本地stash，常用子命令有list

用例：

#### （1）查看stash列表

- git stash list，查看stash列表

```shell
$ git stash list --date=local
stash@{Mon Apr 16 15:09:01 2018}: On release/180427/master: temp2
stash@{Tue Apr 3 19:17:27 2018}: On release/180427/master: temp3
```

> --date=local，显示存储的时间



### 2. log

格式：`git log \<subcommand\>`

说明：查看log

用例：

#### （1）查看某个用户的log[^1]

```shell
$ git log --author='<username>'
```



### 3. diff

格式：

```shell
git diff [<options>] [<commit>] [--] [<path>...]
git diff [<options>] --cached [<commit>] [--] [<path>...]
git diff [<options>] <commit> <commit> [--] [<path>...]
git diff [<options>] <blob> <blob>
git diff [<options>] --no-index [--] <path> <path>
```

说明：Show changes between commits, commit and working tree, etc

用例：

#### （1）查当前分支对应的远程分支是否文件改动（A/D/R）[^3]

```shell
$ git fetch
$ git diff --diff-filter=ADR --name-only master origin/master
```

基于本地分支master，和远程master分支比较，查找出新增加文件（A）、删除文件（D）和重命名文件（R）

> 需要提前fetch一下，获取远程分支的信息



### 4. rev-parse

格式：`git rev-parse [<options>] <args>...`

说明：Pick out and massage parameters

用例：

#### （1）查看当前分支[^2]

```shell
$ git rev-parse --abbrev-ref HEAD
```



### 5. config





## References

[^1]: https://stackoverflow.com/questions/4259996/how-can-i-view-a-git-log-of-just-one-users-commits 
[^2]:https://stackoverflow.com/a/12142066
[^3]: https://stackoverflow.com/a/32540714

