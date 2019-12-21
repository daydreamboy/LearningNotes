# Shortcuts Notes

[TOC]


## Mac OS X

1. 锁屏：`^ + ⌘ + q`（High Sierra 10.13+）



## Terminal




## Visual Code

1. 切换语言：`⌘ + k, m`（先按下⌘和k，然后按下m）
2. 格式化代码：`⇧ + ⎇ + f`
3. 打开命令提示 (Show All Commands)：`⌘ + ⇧ + p`
4. 打开设置界面：` ⌘ + ,`
5. 将选中文本压缩成一行：`^ + j`



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

1. 拷贝当前光标所在的符号名：`⌘ + ⇧ + ⎇ + ^ + c`
2. Fix All Issues：`⌘ + ⎇ + ^ + f`



## Finder

1. 显示隐藏文件[^3]：`⌘ + ⇧ + .`
2. 拷贝当前选中文件夹/文件的绝对路径：`⌘ + ⎇ + c`





References
--
[^1]:https://mjtsai.com/blog/2016/08/16/xcodes-copy-qualified-symbol-name-command/
[^2]:https://stackoverflow.com/a/52595941

[^3]:https://apple.stackexchange.com/questions/340542/show-hidden-files-on-mac-os-x-mojave-using-terminal

