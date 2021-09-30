# Cmake最低版本要求
cmake_minimum_required(VERSION 3.19)
# 项目名
project(sillylang)
# 设置c++版本
set(CMAKE_CXX_STANDARD 17)
#set(ANTLR4_JAR_LOCATION ${PROJECT_SOURCE_DIR}/third_party/antlr-4.9-complete.jar)

find_package(LLVM 12 REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})
message(STATUS "Found llvm in ${LLVM_INCLUDE_DIRS}")
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")

file(GLOB_RECURSE DIR_SRC "src/*.cpp")
message(STATUS "ANTLR生成的Grammar文件已找到")
file(GLOB_RECURSE DIR_LIB_SRC "third_party/*.cpp" "dist/*.cpp" "ast/*.cpp")
message(STATUS "ANTLR Runtime已找到")

#aux_source_directory(dist/src GRAMMAR)

set(TARGET_FILE sil)

# 导入头文件
include_directories(dist/ src/)
include_directories(third_party/antlr4-runtime)
include_directories(ast/)
# 指定生成目标
add_executable(${TARGET_FILE}
        ${DIR_SRC} ${DIR_LIB_SRC}  )

target_link_libraries(${TARGET_FILE}
        LLVM)
