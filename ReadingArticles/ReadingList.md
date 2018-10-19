# ReadingList

[TOC]

---

#### 1、mikeash.com/ Tales From The Crash Mines/ Issue #1[^1]

比较详细地解释如何分析crash问题。



#### 2. Exploring iOS Crash Reports[^2]

如何看懂iOS Crash Report



#### 3. Universal links in iOS[^3]

一篇介绍Universal Link比较全面的文章。

* Universal Link，在iOS 9+支持
* Universal Link支持链接直接跳转到app
* Deep Link指的借用于Safari，通过JS脚本判断当前平台，并打开native app的方式或者webpage。和Universal Link相比有几点不足
  * fallback不够优雅，需要自己在JS判断app是否安装。如果没有安装app（这个判断需要尝试openURL，以及加超时定时器），则加载webpage。
  * 安全性，本质上还是在Info.plist注册URI scheme，然后让Safari openURL，达到打开native app。这样任何app可以注册其他app的URI scheme，这个通过Deep Link无法限制。



[^1]: <https://www.mikeash.com/pyblog/tales-from-the-crash-mines-issue-1.html>
[^2]: https://www.plausible.coop/blog/?p=176 
[^3]: https://medium.com/@abhimuralidharan/universal-links-in-ios-79c4ee038272 







