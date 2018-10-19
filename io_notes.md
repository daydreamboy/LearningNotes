## IO Notes

[TOC]

------

### 

## lO安装

IO官方主页，https://iolanguage.org/

MacOS上安装，可以使用brew，如下

```
$ brew install io
```



简单使用IO

* 执行io脚本，io HelloWorld.io
* 交互式环境，输入io进入交互式命令环境



## IO语法

IO的知识点，按照[官方Guide](https://iolanguage.org/guide/guide.html)来梳理归纳，最终以官方为准。

### 一、Syntax

#### 1. Expressions

IO没有关键字或者语句，表达式（Expression）都是消息实体。BNF范式（Backus-Naur Form，巴科斯-诺尔范式）的定义，如下

```
exp        ::= { message | terminator }
message    ::= symbol [arguments]
arguments  ::= "(" [exp [ { "," exp } ]] ")"
symbol     ::= identifier | number | string
terminator ::= "\n" | ";"
```



* exp，定义一个表达式，e.g. `c ::= 3; `或者`c ::= 3`。注意::=两边必须有空格。
* message，定义一个消息实体，TODO
* arguments,
* symbol，
* terminator，定义一个终止符，即换行符或者分号



#### 2. Messages

IO的消息（Message）相当于方法调用，所有语句都可以当成消息调用。

（1）for语句

for接收四个参数，计数变量、计数变量起始值、计数变量终止值以及循环的body部分

```
Io> for(i, 1, 3, i println)
1
2
3
==> 3
```



（2）if语句

if接收三个参数

```
Io> a := if (1 + 1 == 2, 1, 0)
==> 1
```



#### 3. Operators

TODO

#### 4. Assignment

TODO

#### 5. Numbers

TODO

#### 6. Strings

TODO

#### 7. Comments

注释可以采用//、/**/以及#

```
a := b // add a comment to a line

/* comment out a group
a := 1
b := 2
*/

#!/usr/local/bin/io
```



### 二、Objects





