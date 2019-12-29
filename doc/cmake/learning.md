# cmake版本声明
`cmake_minimum_required(VERSION 3.15)`

# 项目声明
`project(sdn_clion C)`
`此处只需要在顶层目录声明即可，会影响到 PROJECT_SOURCE_DIR 变量`

# 声明c标准
`set(CMAKE_C_STANDARD 99)`

# 处理rpath
`set(CMAKE_INSTALL_RPATH ${PROJECT_SOURCE_DIR}/dev/lib)`
`在cmake中，会自作聪明的处理rpath，通过此命令，显式的指明rpath路径。需要添加在 bin 下面的 CMakeLists.txt`

# 添加子目录
`add_subdirectory(source/lib)`

# 安装

# 添加源文件
`set(MODE1_SRC`
	`./MODE1/device.c`
`)`

`set(MODE2_SRC`
    `./MODE1/device.c`
`)`

`set(SRC_LISTS`
	`${MODE1_SRC}
	${MODE2_SRC}`
`)`

# 头文件
`include_directories(`
        `./include`
        `${PROJECT_SOURCE_DIR}/dev/include`
`)`

# bin文件
`add_executable(dataplane ${DATAPLANE_SRC})`
`target_link_libraries(dataplane base)`

# 动态库
`add_library(base SHARED ${BASE_SRC})`

# 安装
## bin
`install(TARGETS dataplane RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/dev/bin)`

## lib

`install(TARGETS base LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/dev/lib)`

## 头文件
`install(FILES include/base/dhash.h DESTINATION ${PROJECT_SOURCE_DIR}/dev/include/base)`

























