# Cmake最低版本要求
cmake_minimum_required(VERSION 3.16)
# 项目名
project(nyarlathotep)
# 设置c++版本
set(CMAKE_CXX_STANDARD 17)
#set(ANTLR4_JAR_LOCATION ${PROJECT_SOURCE_DIR}/third_party/antlr-4.9-complete.jar)

find_package(LLVM 12 REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})
message(STATUS "Found llvm in ${LLVM_INCLUDE_DIRS}")
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")

aux_source_directory(. ROOT)
message(STATUS "root : ${ROOT}")
aux_source_directory(ast AST)
message(STATUS "ast : ${AST}")
aux_source_directory(dist DIST)
message(STATUS "dist : ${DIST}")
aux_source_directory(error ERROR)
message(STATUS "error : ${ERROR}")
aux_source_directory(codegen CODEGEN)
message(STATUS "codegen : ${CODEGEN}")
aux_source_directory(runtime RUNTIME)
message(STATUS "runtime : ${RUNTIME}")
file(GLOB_RECURSE ANTLR_RUNTIME "third_party/*.cpp")
message(STATUS "third_party : ${ANTLR_RUNTIME}")

#file(GLOB_RECURSE DIR_LIB_SRC "third_party/*.cpp" "dist/*.cpp" "ast/*.cpp" "codegen/*.cpp" "runtime/*.c" "runtime/*.cpp"
#        "error/*.cpp")
#message(STATUS "other files已找到")

#aux_source_directory(dist/src GRAMMAR)

set(TARGET_FILE nyarlathotep)

# 导入头文件
include_directories(dist/)
include_directories(third_party/antlr4-runtime)
include_directories(ast/ codegen/ runtime/ error/)
# 指定生成目标
#add_executable(${TARGET_FILE}
#        ${ROOT} ${DIR_LIB_SRC})
add_executable(
        ${TARGET_FILE}
        ${ROOT}
        ${AST}
        ${DIST}
        ${ERROR}
        ${CODEGEN}
        ${ANTLR_RUNTIME}
        ${RUNTIME}
)

target_link_libraries(${TARGET_FILE}
        LLVM)
