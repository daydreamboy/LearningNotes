# Charles使用手册

[TOC]

## 1、Charles抓取https

Charles抓取https，必要步骤，如下

* Keychain Access安装根证书，`Charles > Help > SSL Proxying > Install Charles Root Certificate`
  * 在Keychain Access中打开刚才安装的根证书Charles Proxy CA (XXX)，展开Trust一栏，将全部设置为Always Trust，输入当前用户密码，这时根证书不再显示红色X



* iOS真机设备安装根证书，`Charles > Help > SSL Proxying > Install Charles Root Certificate on a Mobile Device or Remote Browser`
  * 根据弹出提示框进行操作：配置代理、Safari访问chls.pro/ssl安装根证书
  * iOS 10.3系统及以上，`Settings > General > About > Certificate Trust Settings`，打开刚才根证书的信任[^1]。（如果不信任，浏览器访问https网站会给出是否继续的提示、Charles抓https接口会失败）



* iOS模拟器安装根证书，`Charles > Help > SSL Proxying > Install Charles Root Certificate in iOS Simulators`



* Charles设置SSL Proxying Settings，`Charles > Proxy > Proxy Settings...`
  * 勾选Enable SSL Proxying
  * 增加一个location，*:443，通配符匹配所有域名



> 以上步骤在Mac OS 10.14.6、Charles 4.0.2和iOS 11.4上验证通过





## References

[^1]:https://stackoverflow.com/a/48891484



