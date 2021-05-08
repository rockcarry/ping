+--------------+
 ping 程序说明 
+--------------+

ping 是常用的一个网络连通性检测的工具

ping 的原理是通过 ICMP 协议发送“回显请求报文”，并获取对方主机的应答，来判断网络连通状态

在 windows 和 linux 的命令行或控制台，都可以直接使用 ping 命令
但是在 C 语言中要使用 ping 却没有现成的库函数或者 API

本程序通过 C 语言实现了 ping 的功能，代码可以在 VC++, msys2 gcc, linux gcc 下编译通过


接口说明
--------

typedef void (*PFN_PING_CALLBACK)(void *cbctx, char *ip, int bytes, int ttl, int time, int seq);
回调函数，接收到对方主机的 ping 应答后会调用此回调函数

void* ping_init(int interval, int timeout, PFN_PING_CALLBACK callback, void *cbctx);
初始化并返回一个 context 指针（以下的接口都需要传入这个指针，不赘述）
interval 指定 ping 发送报文的周期，以 ms 为单位
timeout  指定一个超时，如果在这个超时时间内没有收到应答，ping_isok 将返回 0 表示跟对方主机断开
callback 和 cbctx 为回调函数指针和回调的 context

void ping_exit(void *ctx); // 反初始化

void ping_run(void *ctx, char *ip, int start);
执行 ping 操作，ip 为要 ping 的主机 ip 地址，start 为 1 表示开始，0 表示停止 ping

int ping_isok(void *ctx);
判断跟对方主机是否连通


chenk@apical.com.cn
2021-5-6





