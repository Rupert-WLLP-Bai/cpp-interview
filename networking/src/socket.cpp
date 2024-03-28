#include "../include/socket.h"
#include <arpa/inet.h>
#include <iostream>
#include <sys/socket.h>

/**
 * @brief
 *
 * @return true 大端
 * @return false 小端
 */
bool checkCPUendian() {
    // 利用联合体的特性判断CPU的字节序
    // 联合体的所有成员共享一块内存, 且所有成员的地址都是相同的
    // 联合体的大小等于最大的成员的大小
    union {
        int a;
        char s[sizeof(int)];
    } u;
    u.a = 0x12345678;
    return (0x12 == u.s[0]);
}

void checkCPUendianTest() {
    if (checkCPUendian()) {
        std::cout << "大端字节序" << std::endl;
    } else {
        std::cout << "小端字节序" << std::endl;
    }
}

/**
 * @brief 测试字节序转换函数
 *
 */
void convertByteOrder() {
    // 192.168.1.100:8080
    const unsigned char ip[4] = {192, 168, 1, 100}; // 32位IP地址
    const unsigned short port = 8080;               // 16位端口
    std::cout << "转换前: " << (int)ip[0] << "." << (int)ip[1] << "."
              << (int)ip[2] << "." << (int)ip[3] << ":" << port << std::endl;
    // 将IP地址和端口转换为网络字节序
    // 使用htonl和htons函数
    unsigned int ipNet;
    unsigned char resNet[4];
    memcpy(&ipNet, ip, 4); // 第三个参数是字节数
    ipNet = htonl(ipNet);
    unsigned short portNet = htons(port);
    memcpy(resNet, &ipNet, 4);
    std::cout << "转换为网络字节序: " << (int)resNet[0] << "." << (int)resNet[1]
              << "." << (int)resNet[2] << "." << (int)resNet[3] << ":"
              << portNet << std::endl;
    // 将IP地址和端口转换为本地字节序
    // 使用ntohl和ntohs函数
    unsigned int ipHost;
    unsigned char resHost[4];
    memcpy(&ipHost, resNet, 4);
    ipHost = ntohl(ipHost);
    unsigned short portHost = ntohs(portNet);
    memcpy(resHost, &ipHost, 4);
    std::cout << "转换为本地字节序: " << (int)resHost[0] << "."
              << (int)resHost[1] << "." << (int)resHost[2] << "."
              << (int)resHost[3] << ":" << portHost << std::endl;
}

/**
 * @brief socket地址结构测试
 *
 */
void socketAddressStructureTest() {
    sockaddr sa;                 // 通用socket地址结构
    sockaddr_storage sa_storage; // 更大的socket地址结构
    sockaddr_in sa_in;           // IPv4 socket地址结构
    sockaddr_in6 sa_in6;         // IPv6 socket地址结构
}

/**
 * @brief IP地址转换测试
 *
 */
void ipAddressConversionTest() {
    // 将点分十进制IP地址转换为整数
    const char *ipStr = "192.168.1.100";
    unsigned int ipInt = inet_addr(ipStr);
    std::cout << "点分十进制IP地址转换为整数: " << ipInt << std::endl;
    // 将整数IP地址转换为点分十进制
    ipInt += 1;
    char res[16];
    // 地址族, 整数IP地址, 目标字符串, 字符串长度
    inet_ntop(AF_INET, &ipInt, res, 16);
    std::cout << "整数IP地址转换为点分十进制: " << res << std::endl;
}