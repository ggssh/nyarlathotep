project(silly_pl0)

set(CMAKE_CXX_STANDARD 14)

include_directories(dist/src)
include_directories(third_party/antlr4-runtime)

add_executable(silly_pl0
                dist/src
                third_party/antlr4-runtime
                src/main.cpp)