# Charles使用手册

[TOC]

## 1、前言

本文介绍MacOS的Charles的使用。



## 2、 Charles抓取https

Charles默认情况下，可以抓取http，但是不支持https。

说明

> 不配置情况下，Charles可以查看https请求以及url的host，但是无法查看https报文，以及具体请求url的path。



Charles抓取https有下面几个步骤，如下

* 设置网络代理

* 在目标系统上安装Charles的Root证书
* Charles设置SSL Proxying Settings
* Charles查看特定请求的报文



### (1) 安装Charles的Root证书

针对不同系统，Charles > Help提供几种方式安装证书



#### a. MacOS浏览器

Keychain Access安装根证书，Charles > Help > SSL Proxying > Install Charles Root Certificate。在Keychain Access中打开刚才安装的根证书Charles Proxy CA (XXX)，展开Trust一栏，将全部设置为Always Trust，输入当前用户密码，这时根证书不再显示红色X

> 以上步骤在Mac OS 10.14.6、Charles 4.0.2和iOS 11.4上验证通过



#### b. iOS真机设备

iOS真机设备安装根证书，Charles > Help > SSL Proxying > Install Charles Root Certificate on a Mobile Device or Remote Browser

* 根据弹出提示框进行操作：配置代理、Safari访问chls.pro/ssl安装根证书
* iOS 10.3系统及以上，Settings > General > About > Certificate Trust Settings，打开刚才根证书的信任[^1]。
  * 如果不信任，浏览器访问https网站会给出是否继续的提示、Charles抓https接口会失败

说明

> 如果访问不了chls.pro/ssl，可以采用手动安装证书的方式。参考[这篇文章](https://blog.csdn.net/qq_43485197/article/details/132272661)，Charles > Help > SSL Proxying > Save Charles Root Certificate...，将证书保存到电脑本地，然后把这个文件发送到iOS设备的文件app中，但是要在Downloads文件夹下，然后在文件app中打开这个证书文件，会有一个提示框，提示前往设置，在设置有Downloaded Profile一栏，进入安装即可。



#### c. iOS模拟器

iOS模拟器安装根证书，Charles > Help > SSL Proxying > Install Charles Root Certificate in iOS Simulators



### (2) 设置SSL Proxying Settings

Charles设置SSL Proxying Settings，Charles > Proxy > Proxy Settings...
* 勾选Enable SSL Proxying
* 增加一个location，*:443，通配符匹配所有域名





## References

[^1]:https://stackoverflow.com/a/48891484



