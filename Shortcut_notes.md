# Shortcuts Notes

[TOC]


## Mac OS X

### 锁屏

`^ + ⌘ + q`（High Sierra 10.13+）



## Terminal




## Visual Code

### 切换语言

`⌘ + k, m`（先按下⌘和k，然后按下m）



### 格式化代码

`⇧ + ⎇ + f`



### 打开命令提示 (Show All Commands)

`⌘ + ⇧ + p`



### 打开设置界面

` ⌘ + ,`



### 将选中文本压缩成一行

`^ + j`



### 配置Setting.json

`⌘ + ⇧ + p`，输入Settings.json，可以打开VSCode配置文件。



#### （1）设置文件后缀关联语法

```json
{
    "files.associations": {
        "*.podspec": "ruby",
        "*.we": "vue"
    }
}
```



### Prettier插件

#### （1）设置Vue语法格式化

默认VSCode禁用了Vue的语法格式化[^2]。`⌘ + ⇧ + p`，输入Settings.json，增加下面字段以及值

```json
{
    "prettier.disableLanguages": []
}
```



## Xcode

### 拷贝当前光标所在的符号名

`⌘ + ⇧ + ⎇ + ^ + c`



### Fix All Issues

`⌘ + ⎇ + ^ + f`



### 方法添加documentation

选中方法签名[^5]，`⌘ + ⎇ + /`





## Finder

### 显示隐藏文件[^3]

`⌘ + ⇧ + .`



### 拷贝当前选中文件夹/文件的绝对路径

`⌘ + ⎇ + c`



## WebStorm

### 定位当前文件所在位置

`⎇ + F1`，选择Project View





References
--
[^1]:https://mjtsai.com/blog/2016/08/16/xcodes-copy-qualified-symbol-name-command/
[^2]:https://stackoverflow.com/a/52595941

[^3]:https://apple.stackexchange.com/questions/340542/show-hidden-files-on-mac-os-x-mojave-using-terminal

[^4]:https://stackoverflow.com/questions/1086041/locate-current-file-in-intellij

[^5]:https://stackoverflow.com/a/38071980



