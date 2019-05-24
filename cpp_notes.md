# CPP Notes

[TOC]

## 常见CPP语法



### （1）= delete[^1]

语法：function_declaration = delegate;

作用：禁止某个函数使用

示例：my_class(my_class const &) = delete;

说明：C++11语法

举个例子

```c++
class X {
    // ...
    X& operator=(const X&) = delete;  // Disallow copying
    X(const X&) = delete;
};
```





## References

[^1]:<https://stackoverflow.com/questions/5513881/meaning-of-delete-after-function-declaration>



