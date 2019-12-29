cmake_minimum_required(VERSION 3.15)

set(CMAKE_C_STANDARD 99)

set(CMAKE_INSTALL_RPATH ${PROJECT_SOURCE_DIR}/dev/lib)

set(DEVICE_SRC
        ./device/device.c
        )

set(INIT_SRC
        ./init/main.c
)

set(DATAPLANE_SRC
        ${DEVICE_SRC}
        ${INIT_SRC}
)

include_directories(
        ./include
        ${PROJECT_SOURCE_DIR}/dev/include
)

add_executable(dataplane ${DATAPLANE_SRC})
target_link_libraries(dataplane base)

install(TARGETS dataplane RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/dev/bin)