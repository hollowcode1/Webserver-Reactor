# WebBench
增加了一个新的选项-k,用来支持对HTTP长连接的测试。用法与原来的没什么区别。
默认不加k为短连接，加k的时候请与-2(http11)配合使用。

## 使用：

	sudo make && sudo make install PREFIX=your_path_to_webbench
  
## 命令行选项：



| 短参        | 长参数           | 作用   |
| ------------- |:-------------:| -----:|
|-f     |--force                |不需要等待服务器响应               | 
|-r     |--reload               |发送重新加载请求                   |
|-t     |--time <sec>           |运行多长时间，单位：秒"            |
|-p     |--proxy <server:port>  |使用代理服务器来发送请求	    |
|-c     |--clients <n>          |创建多少个客户端，默认1个"         |
|-9     |--http09               |使用 HTTP/0.9                      |
|-1     |--http10               |使用 HTTP/1.0 协议                 |
|-2     |--http11               |使用 HTTP/1.1 协议                 |
|-k     |	                |使用 Keep-Alive长连接进行测试|
|       |--get                  |使用 GET请求方法                   |
|       |--head                 |使用 HEAD请求方法                    |
|       |--options              |使用 OPTIONS请求方法               |
|       |--trace                |使用 TRACE请求方法                 |
|-?/-h  |--help                 |打印帮助信息                       |
|-V     |--version              |显示版本号                         |
