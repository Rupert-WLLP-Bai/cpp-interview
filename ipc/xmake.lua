-- cpp-interview/ipc/xmake.lua
target("ipc")
    set_kind("binary") -- 创建一个可执行文件
    add_files("src/*.cpp") -- 添加源码文件
    add_includedirs("include") -- 添加头文件搜索路径
