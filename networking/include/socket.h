#pragma once

/*
    1. 判断字节序
    大端: 0x1234 -> 0x12 0x34 整数的高位字节存放在内存的低地址处
    小端: 0x1234 -> 0x34 0x12 整数的高位字节存放在内存的高地址处
    对于内存来说, 从左到右是低地址到高地址
    对于整数来说, 从左到右是高位到低位

    网络字节序是大端字节序
    大部份的CPU是小端字节序
*/
bool checkCPUendian();
void checkCPUendianTest();

/*
    2. 字节序转换函数
    BSD Socket API提供了一组字节序转换函数
    htons: host to network short
    htonl: host to network long
    ntohs: network to host short
    ntohl: network to host long
    端口是16位, IP地址是32位
    转换端口时使用htons和ntohs
    转换IP地址时使用htonl和ntohl

    模拟一个场景:
    本地主机和远程主机通信, 本地主机是小端字节序, 远程主机是大端字节序
    本地主机发送数据时, 需要将数据转换为网络字节序
    远程主机接收数据时, 需要将数据转换为本地字节序
*/
void convertByteOrder();

/*
    3. socket地址结构

    3.1 sockaddr
    struct sockaddr {
        __uint8_t       sa_len;         // 结构体的长度
        sa_family_t     sa_family;      // 地址族
        char            sa_data[14];    // 地址数据
    }
    其中sa_family是地址族, 有AF_INET, AF_INET6, AF_UNIX等

    3.2 sockaddr_storage
    由于14字节的sa_data无法容纳IPv6地址, 所以BSD Socket
   API提供了一个更大的结构体 struct sockaddr_storage {
        __uint8_t       ss_len;         // 结构体的长度
        sa_family_t     ss_family;      // 地址族
        char            __ss_pad1[_SS_PAD1SIZE]; // 保留字段
        __int64_t       __ss_align;     // 对齐字段
        char            __ss_pad2[_SS_PAD2SIZE]; // 保留字段
    }

    3.3 sockaddr_in 和 sockaddr_in6
    struct sockaddr_in {
        __uint8_t       sin_len;        // 结构体的长度
        sa_family_t     sin_family;     // 地址族
        in_port_t       sin_port;       // 端口号
        struct in_addr  sin_addr;       // IP地址
        char            sin_zero[8];    // 保留字段
    }

    struct sockaddr_in6 {
        __uint8_t       sin6_len;       // 结构体的长度
        sa_family_t     sin6_family;    // 地址族
        in_port_t       sin6_port;      // 端口号
        __uint32_t      sin6_flowinfo;  // 流信息
        struct in6_addr sin6_addr;      // IPv6地址
        __uint32_t      sin6_scope_id;  // 作用域ID
    }
*/
void socketAddressStructureTest();

/*
    4. IP地址转换函数
    inet_pton: presentation to numeric
    inet_ntop: numeric to presentation
*/
void ipAddressConversionTest();