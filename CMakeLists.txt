cmake_minimum_required(VERSION 3.10)
project(64BitKernel C)
set(CMAKE_C_STANDARD 99)

ENABLE_LANGUAGE(ASM)

set(CMAKE_C_FLAGS -nostdinc)

include_directories(inc)
FILE(GLOB C_SRCS *.c */*.c */*/*.c  */*/*/*.c)
FILE(GLOB H_SRCS *.h */*.h */*/*.h  */*/*/*.h)

add_executable(64BitKernel ${C_SRCS} ${H_SRCS})