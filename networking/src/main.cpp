#include "../include/socket.h"
#include <iostream>

int main() {
    checkCPUendianTest();         // 测试CPU字节序
    convertByteOrder();           // 测试字节序转换函数
    socketAddressStructureTest(); // 测试socket地址结构
    ipAddressConversionTest();    // 测试IP地址转换函数
    return 0;
}
