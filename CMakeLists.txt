cmake_minimum_required(VERSION 3.10)
project(screen-tool)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(CMAKE_SOURCE_LANGUAGE OBJCXX)
    set(CMAKE_OBJCXX_EXTENSIONS OFF)
endif()

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/resources
    ${PROJECT_SOURCE_DIR}/lib
    $ENV{CMAKE_INCLUDE_PATH}
)

# 在 macOS 平台上查找 UIKit 框架
if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    find_library(APPKIT_LIBRARY AppKit)
endif()

# 在 linux 平台上查找 X11 库
if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    find_library(X11 REQUIRED)
    include_directories(/usr/include/X11)
    link_directories(/usr/lib/X11)
endif()

# 设置源文件目录
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# 添加源文件路径
if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    file(GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cpp" "${SRC_DIR}/**/*.cpp" "${SRC_DIR}/**/*.mm")
else()
    file(GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cpp" "${SRC_DIR}/**/*.cpp")
endif()

# 生成可执行文件
add_executable(${PROJECT_NAME} ${SRC_FILES})

# 链接 CoreGraphics 框架
if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    target_link_libraries(${PROJECT_NAME} ${APPKIT_LIBRARY})
endif()

# 链接到X11库
if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    target_link_libraries(${PROJECT_NAME} X11 ${X11_LIBRARIES} Xinerama)
endif()


# 拷贝资源文件
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})