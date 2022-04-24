cmake_minimum_required(VERSION 3.10) 

# set the project name 
project(ysh VERSION 1.0) 

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 动态链接库
LINK_DIRECTORIES(/usr/include)

# 调试信息
set(CMAKE_CXX_FLAGS "-g")
# set(CMAKE_CXX_FLAGS "-lreadline")
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_BUILD_TYPE "Debug")
#SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
#SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
# 输出目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# options
option(DEBUG "Debug Option" ON)
#configure file 
configure_file(YshConfig.h.in YshConfig.h)

# add the libs
add_subdirectory(MyShell)

# add the executable 
add_executable(Ysh ysh.c)


target_link_libraries(Ysh PUBLIC MyShell readline)

#include
target_include_directories(Ysh PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/MyShell" )

