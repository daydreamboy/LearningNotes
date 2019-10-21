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

格式：`git log [<options>] [<revision range>] [[--] <path>...]`

说明：查看log

用例：

#### （1）查看某个或多个用户的log[^1]

```shell
$ git log --author='<username>'
$ git log --author='<username1>' --author='<username2>'
$ git log --author='<email.username@company.com>'
```



> --author参数，除了可以指定用户名，还可以指定用户的email





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



#### （2）查看当前commit[^6]

```shell
$ git rev-parse HEAD
```







### 5. config

格式：`git config [<options>]`

说明：用于设置和查询git的配置

git的config，分为下面三个级别[^4]

* project，配置存放在git仓库`.git/config`文件中，配置仅对当前git仓库有效
* global，配置存放在git仓库`~/.gitconfig`文件中，配置对当前用户的所有git仓库有效
* system，配置存放在git仓库`/etc/gitconfig`文件中，配置对所有用户的所有git仓库有效



访问project级别的config配置

```shell
$ cd <git repo>; git config user.name "John Doe" 
或者
$ git config --file path/to/<git repo>/.git/config user.name "John Doe" 
```



访问global级别的config配置

```shell
$ git config --global user.name "John Doe"
```



访问system级别的config配置

```shell
$ git config --system user.name "John Doe"
```



### 6. clone



如果git仓库包含submodule，clone时可以增加`--recursive`选项，将submodule同时clone下来。例如

```shell
$ git clone --recursive https://github.com/DeVaukz/MachO-Explorer
```



## 3、使用git hook

​       git hook是在git执行特定命令或者过程中，允许执行用户的脚本。git hook的脚本，位于`.git/hooks`目录下面，一般会有`.sample`后缀的示例脚本。

​       git hook的脚本，有特定的文件名，用于hook那个过程，同时脚本需要可执行权限。常用的hook名[^5]，如下

| 脚本名                                                       | 作用 |
| ------------------------------------------------------------ | ---- |
| [applypatch-msg](https://github.com/git/git/blob/master/templates/hooks--applypatch-msg.sample) |      |
| [pre-applypatch](https://github.com/git/git/blob/master/templates/hooks--pre-applypatch.sample) |      |
| [post-applypatch](https://www.git-scm.com/docs/githooks#_post_applypatch) |      |
| [pre-commit](https://github.com/git/git/blob/master/templates/hooks--pre-commit.sample) |      |
| [prepare-commit-msg](https://github.com/git/git/blob/master/templates/hooks--prepare-commit-msg.sample) |      |
| [commit-msg](https://github.com/git/git/blob/master/templates/hooks--commit-msg.sample) |      |
| [post-commit](https://www.git-scm.com/docs/githooks#_post_commit) |      |
| [pre-rebase](https://github.com/git/git/blob/master/templates/hooks--pre-rebase.sample) |      |
| [post-checkout](https://www.git-scm.com/docs/githooks#_post_checkout) |      |
| [post-merge](https://www.git-scm.com/docs/githooks#_post_merge) |      |
| [pre-receive](https://www.git-scm.com/docs/githooks#pre-receive) |      |
| [update](https://github.com/git/git/blob/master/templates/hooks--update.sample) |      |
| [post-receive](https://www.git-scm.com/docs/githooks#post-receive) |      |
| [post-update](https://github.com/git/git/blob/master/templates/hooks--post-update.sample) |      |
| [pre-auto-gc](https://www.git-scm.com/docs/githooks#_pre_auto_gc) |      |
| [post-rewrite](https://www.git-scm.com/docs/githooks#_post_rewrite) |      |
| [pre-push](https://www.git-scm.com/docs/githooks#_pre_push)  |      |



// TODO

https://stackoverflow.com/questions/3442874/in-git-how-can-i-write-the-current-commit-hash-to-a-file-in-the-same-commit



## References

[^1]: https://stackoverflow.com/questions/4259996/how-can-i-view-a-git-log-of-just-one-users-commits 
[^2]:https://stackoverflow.com/a/12142066
[^3]: https://stackoverflow.com/a/32540714

[^4]: https://stackoverflow.com/a/16682441

[^5]:https://githooks.com/
[^6]:https://stackoverflow.com/a/3443485





