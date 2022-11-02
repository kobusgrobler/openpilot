cmake_minimum_required(VERSION 3.23)
project(openpilot)

set(OPENPILOT /volumes2/kobus/work/openpilot/)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(THREADS_PREFER_PTHREAD_FLAG ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Werror -Wshadow -Wno-unknown-warning-option \
-Wno-deprecated-register -Wno-register -Wno-inconsistent-missing-override -Wno-c99-designator \
-Wno-reorder-init-list")

add_compile_definitions(SWAGLOG="common/swaglog.h")

include_directories(${OPENPILOT}/third_party/linux/include)
include_directories(${OPENPILOT}/third_party/opencl/include)
include_directories(${OPENPILOT}/third_party/libyuv/include)
include_directories(${OPENPILOT}/third_party/snpe/include)
include_directories(${OPENPILOT}/third_party/json11)
include_directories(${OPENPILOT})
include_directories(${OPENPILOT}/cereal)

link_directories(${OPENPILOT}/third_party)
link_directories(${OPENPILOT}/third_party/libyuv/x64/lib)
link_directories(${OPENPILOT}/third_party/snpe/x86_64-linux-clang)
link_directories(${OPENPILOT}/cereal)
link_directories(${OPENPILOT}/common)
link_directories(${OPENPILOT}/common/transformations)

add_compile_definitions(USE_ONNX_MODEL)

add_subdirectory(system)
add_subdirectory(selfdrive)
add_subdirectory(tools)
