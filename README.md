本项目是一个在linux平台上的高并发http服务器。

服务器结构见xmind文件。

**usage:**

```shell
./server [threadNum]
```

测试Cpu是amd5900hx（分配给虚拟机一半的cpu）运行内存分配了4g

**压力测试：**

*短链接：*

![image](https://github.com/hollowcode1/Webserver-Reactor/assets/122421971/9207dace-253a-47fa-ae8e-2011b1903bdb)


*长连接：*

![image](https://github.com/hollowcode1/Webserver-Reactor/assets/122421971/bb33497c-565c-4383-b806-1e5c81dbf0a6)

***实现描述：***



本项目使用channel类来封装每个客户端事件，将事件里面的联合体的指针指向channel，然后使用EventLoop类来作为事件分发器（baseloop），建立EPollPoller与channel的联系，其中分发事件采用的算法是轮询算法（在线程池中具体实现），没有使用经典的生产者消费者模型，而是创建wakeupfd，向所要唤醒的线程中随意写一个数据就会触发线程处理读事件，进而唤醒线程执行回调。在服务器中每一个TcpConnection对应一个channel，TcpConnection负责给channel设置回调，并且提供外界设置业务逻辑处理的接口，该接口由TcpServer来设置回调，TcpServer管理所有的TcpConnection，并提供给外界协议的业务逻辑处理的设置回调的接口。HttpServer是基于TcpServer的主要功能就是将业务逻辑处理的回调设置给TcpServer，并且将解析HTTP报文的类和响应HTTP报文的类结合起来处理业务逻辑。其中解析http报文就是将http报文提取出来，一行一行地进行解析，通过其中的特殊字符来分辨解析的部分比如回车换行或者分号等。
