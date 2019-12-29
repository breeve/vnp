cmake_minimum_required(VERSION 3.15)

set(DHASH_SRC
        ./dhash/dhash.c
        )

set(BASE_SRC
        ${DHASH_SRC}
        )

include_directories(
        ./include
)

add_library(base SHARED ${BASE_SRC})

install(TARGETS base LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/dev/lib)

install(FILES include/base/dhash.h DESTINATION ${PROJECT_SOURCE_DIR}/dev/include/base)