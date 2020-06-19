# git手册

[TOC]

## 1、git选项

### `--exec-path`

作用：输出git-core目录

示例：

```shell
$ git --exec-path
/Applications/Xcode.app/Contents/Developer/usr/libexec/git-core
```





## 2、git子命令



一般情况下，git子命令都在git仓库中使用，但是不能`.git`文件夹下面使用，否则git子命令不能正常工作。

举个例子，如下

```shell
$ cd .git
➜  .git git:(master) git rev-parse --show-toplevel
➜  .git git:(master) git status
fatal: this operation must be run in a work tree
```



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

#### （1）查看当前分支对应的远程分支是否文件改动（A/D/R）[^3]

```shell
$ git fetch
$ git diff --diff-filter=ADR --name-only master origin/master
```

基于本地分支master，和远程master分支比较，查找出新增加文件（A）、删除文件（D）和重命名文件（R）

> 需要提前fetch一下，获取远程分支的信息



#### （2）查看Staged File列表[^7]

Staged File列表，是指准备要提交的文件列表。

使用下面命令，可以查看哪些要提交的文件

```shell
$ git diff --cached --name-status
M       README.md
A       WCMacroKit/test.h
```



#### diff选项

```shell
git diff --name-only
path/to/modified/file
path/to/renamed/file


# list the names and change statuses:
git diff --name-status
M       path/to/modified/file
R100    path/to/existing/file   path/to/renamed/file


# list a diffstat-like output (+ed lines, -ed lines, file name):
git diff --numstat
1       0       path/to/modified/file
0       0       path/to/{existing => renamed}/file
```



https://stackoverflow.com/a/21724628





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



#### （3）查看当前Git根目录路径[^8]

```shell
$ git rev-parse --show-toplevel
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



## 4、常用git alias

### 1. 配置.gitconfig文件

在`~/.gitconfig`文件中，找到下面section进行配置[^9]

```properties
[alias]
    <shortcut> = <actual command>
    st = status
    ci = commit -v
```

如果.gitconfig文件的格式有问题，执行git --version命名会报错，如下


```shell
$ git --version
fatal: bad config line 15 in file /Users/wesley_chen/.gitconfig
```



由于.gitconfig有特定格式，可以使用git config --global命令进行添加别名。举个例子，如下

```shell
$ git config --global alias.removeLocalOtherBranch 'branch -d `git branch | grep -v '*' | xargs`'
```







### 2. 常用git alias示例

```properties
[alias]
    remove_local_other_branch = branch -d `git branch | grep -v \* | xargs`
```



* remove_local_other_branch，删除非当前分支的其他本地分支[^10]





## 5、Git使用Tips

### 1. 修改MacOS默认git[^11]

MacOS自带git命令行工具，如下

```shell
$ git --version
git version 2.24.1 (Apple Git-126)
```



可以使用brew安装git，并将git命令重新链接到新git工具

```shell
$ brew install git
$ brew link --force git
Warning: Already linked: /usr/local/Cellar/git/2.26.1
To relink:
  brew unlink git && brew link git
```



重启terminal，检查git版本，如下

```shell
$ git --version
git version 2.26.1
```



### 2. 查找被删除的文件

​       Git仓库中有文件被其他人删除，但是自己需要找到这个文件。可以使用下面的命令[^12]来找到这个文件commit记录，一般来说，最近一个commit中，这个文件被删除掉了。

```shell
$ git log --full-history -- path/to/file
```

上面命令要求，输入准确的被删除文件的相对路径。但是时间久了，这个路径并不知道，只是知道文件名而已，因此这个命令不太管用。

可以使用下面命令[^13]来进行搜索，被删除文件的commit记录，如下

```shell
$ git log --full-history -- "**/deleted_file_name.*"
```

说明

> git log是否添加`--all`选项，SO评论[^13]中添加此选项，可以在其他分支进行搜索，但是实际上操作，发现搜索到的commit有些和删除的文件没有关系。而且最新的commit也不是删除文件的那个commit。





## References

[^1]: https://stackoverflow.com/questions/4259996/how-can-i-view-a-git-log-of-just-one-users-commits 
[^2]:https://stackoverflow.com/a/12142066
[^3]: https://stackoverflow.com/a/32540714

[^4]: https://stackoverflow.com/a/16682441

[^5]:https://githooks.com/
[^6]:https://stackoverflow.com/a/3443485

[^7]:https://stackoverflow.com/a/2413151
[^8]:https://stackoverflow.com/a/957978

[^9]:https://stackoverflow.com/questions/2553786/how-do-i-alias-commands-in-git
[^10]:https://stackoverflow.com/questions/10610327/delete-all-local-git-branches
[^11]:https://medium.com/@katopz/how-to-upgrade-git-ff00ea12be18

[^12]:https://stackoverflow.com/questions/6839398/find-when-a-file-was-deleted-in-git
[^13]:https://stackoverflow.com/a/7203551

