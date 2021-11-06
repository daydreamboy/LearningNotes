# IO使用指南

[TOC]

## 安装

IO官方主页，https://iolanguage.org/

MacOS上安装，可以使用brew，如下

```shell
$ brew install io
```



简单使用IO

* 执行io脚本，io HelloWorld.io
* 交互式环境，输入io进入交互式命令环境



## 语法

IO的知识点，按照[官方Guide](https://iolanguage.org/guide/guide.html)来梳理归纳，最终以官方为准。

### 基础语法（Syntax）

#### 1、表达式（Expressions）

IO没有关键字或者语句，表达式（Expression）都是消息（Message）。BNF范式（Backus-Naur Form，巴科斯-诺尔范式）的定义，如下

```properties
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
* terminator，定义终止符，即换行符或者分号



#### 2、消息（Messages）

IO的消息（Message）相当于方法调用，所有语句都可以当成消息调用。

（1）for语句

for接收四个参数，计数变量、计数变量起始值、计数变量终止值以及循环的body部分

```shell
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



合法数字的示例

```c
123
123.456
0.456
.456
123e-4
123e4
123.456e-7
123.456e2
// 十六进制数
0x0
0x0F
0XeE
```





#### 6、字符串（Strings）

字符串由一对双引号`"`包围，如果字符串中存在`"`，则使用`\`转义或者使用三个引号`"""`方式。

举个例子

```python
s := "this is a \"test\".\nThis is only a test."

// Triple quotes
s := """this is a "test".
This is only a test."""
```



#### 7、注释（Comments）

注释可以采用`//`、`/* */`以及`#`三种方式。

举个例子

```python
a := b // add a comment to a line

/* comment out a group
a := 1
b := 2
*/

#!/usr/local/bin/io
```



### 对象（Objects）



#### 1、原型（Prototypes）



#### 2、继承（Inheritance）

所有对象都继承自Object，类定义约定类名首字母是大写

举个例子

```shell
Io> message(Dog := Object clone)
==> setSlotWithType("Dog", Object clone)
Io> message(dog := Object clone)
==> setSlot("dog", Object clone)
```

说明

> message是一个内置方法，用于执行和转换括号中的表达式



#### 3、方法（Methods）

内置*method*方法，用于定义方法

格式：*method(<arg name 0>, <arg name 1>, ..., \<do message\>)*

说明：参数是可选的

举个例子

```shell
// 1. 不带参数
Io> Dog bark := method("woof!" print)
==> method(
    "woof!" print
)
Io> Dog bark
woof!==> woof!
// 2. 带2个参数
Io> add := method(a, b, a + b)
==> method(a, b, 
    a + b
)
Io> add(1,2)
==> 3
```



## References



