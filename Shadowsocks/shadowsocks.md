# 关于Shadowsocks[^3] (SS)

[TOC]

## （1）基于Python版本的SS

原始教程：https://shadowsocks.be/9.html（目前已经不可访问）

网上找到一篇类似的[教程](https://wistbean.github.io/banwagong-ss.html)，但是基于Python版本的SS不再维护，推荐使用C语言的[shadowsocks-libev]([https://github.com/shadowsocks/shadowsocks-libev](https://pincong.rocks/url/link/aHR0cHM6Ly9naXRodWIuY29tL3NoYWRvd3NvY2tzL3NoYWRvd3NvY2tzLWxpYmV2))

这里仅记录基于Python版本的SS安装后的笔记，如下

* SS的配置文件：`/etc/shadowsocks.json`

* 检查SS服务是否启动：`ps -ef | grep shadowsocks`

  ```shell
  [root /]# ps -ef | grep shadowsocks
  root      1553     1  0 04:27 ?        00:00:00 python /usr/local/shadowsocks/server.py -c /etc/shadowsocks.json -d start
  root      1656  1654  0 04:32 ?        00:00:00 grep shadowsocks
  ```

  上面表示SS服务已启动

* CentOS版本

  ```shell
  [root@host ~]# uname -a
  Linux host.localdomain 4.10.5-1.el6.elrepo.x86_64 #1 SMP Wed Mar 22 14:55:33 EDT 2017 x86_64 x86_64 x86_64 GNU/Linux
  [root@host ~]# uname -r
  4.10.5-1.el6.elrepo.x86_64
  ```

  





## （2）基于shadowsocks-libev版本的SS

教程地址：https://www.24kplus.com/linux/264.html

教程地址：https://www.howru.cc/articles/350.html



## （3）排查SS不能FQ

按照下面步骤排查

1. ping主机地址，不能ping通，主机可能宕机了

2. telnet主机地址和SS端口，如果超时或不通，可能端口被封了。如果出现下面提示，应该也是通的

   ```shell
   $ telnet <ip address> <port>
   Trying <ip address>...
   telnet: connect to address <ip address>: Connection refused
   telnet: Unable to connect to remote host
   ```

3. 上面都不行，登录VPS主机，确认SS服务是否启动

* Python版本的SS，使用`ps -ef | grep shadowsocks`
* shadowsocks-libev版本的SS，使用`ps -ef | grep ss-server`[^2]

4. 如果Python版本的SS服务在启动，那么需要换成shadowsocks-libev版本的SS，并且使用aes-256-gcm加密方式。对应SS客户端的加密方式也需要使用aes-256-gcm。

说明

> 最新SS客户端（Mac），可以在[这里](https://github.com/shadowsocks/ShadowsocksX-NG)下载源码编译app



## References

[^1]:https://pincong.rocks/article/12173
[^2]:https://www.howru.cc/articles/350.html
[^3]:https://shadowsocks.org/en/index.html









