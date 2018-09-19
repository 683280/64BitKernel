#arch
====
    不同架构的初始化代码
#inc
===
    头文件

#libc
    C运行时库代码

#multiboot
    引导头文件，最先执行的代码

#run
    用于测试、运行代码的目录文件

#script
    脚本文件，存放用于辅助或者编译内核的脚本

#src
    内核代码

    #debug
        用于测试和调试内核代码

    #devices
        设备管理

    #io
        输入输出

    #itr
        内核错误处理

    #mm
        内存管理

    #paging
        分页管理

    #sched
        进程调度


最先执行multiboot目录下multiboot.asm文件，然后跳转到arch目录下arch.asm,然后执行不同架构下的初始化代码，当CPU初始化完毕开始执行src目录下的entry.asm文件，进入内核。。。
