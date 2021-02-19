
cmake_minimum_required(VERSION 3.7)
project(nkernel-poc ASM_NASM CXX)

set(CMAKE_ASM_NASM_OBJECT_FORMAT elf32)
set(CMAKE_ASM_NASM_COMPILE_OBJECT "<CMAKE_ASM_NASM_COMPILER> -felf32 <INCLUDES> <SOURCE> -o <OBJECT>")
set(CMAKE_NASM_LINK_EXECUTABLE "clang <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")

file(GLOB_RECURSE sources_cpp "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE sources_asm "${CMAKE_CURRENT_SOURCE_DIR}/src/*.asm")

add_executable(nkernel-poc ${sources_asm} ${sources_cpp})
target_include_directories(nkernel-poc PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")

target_include_directories(nkernel-poc PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/etl/include/")

set_property(TARGET nkernel-poc PROPERTY LINKER_LANGUAGE NASM)
target_compile_options(nkernel-poc PUBLIC -target i686-elf -Wall -Wextra)
#set_property(TARGET nkernel-poc PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
set_property(TARGET nkernel-poc PROPERTY CXX_STANDARD 20)
set_property(TARGET nkernel-poc PROPERTY LINK_FLAGS "-target i686-elf -nostdlib -lgcc -T ${CMAKE_CURRENT_SOURCE_DIR}/src/linktable.ld")


