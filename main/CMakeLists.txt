set(CMAKE_BUILD_TYPE "DEBUG")
#set(CMAKE_BUILD_TYPE "RELEASE")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG origin/main
)
FetchContent_Declare(
        glog
        GIT_REPOSITORY https://github.com/google/glog
)
FetchContent_Declare(
        gflags
        GIT_REPOSITORY https://github.com/gflags/gflags
)
FetchContent_Declare(
        abseil
        GIT_REPOSITORY https://github.com/abseil/abseil-cpp
)
FetchContent_MakeAvailable(googletest glog gflags abseil)

add_executable(edc edc.cpp)
target_sources(edc
        PRIVATE
        ../lib/cut_matching.cpp
        ../lib/expander_decomp.cpp
        ../lib/trimming.cpp
        ../lib/datastructures/unit_flow.cpp
        ../lib/datastructures/splay_tree.cpp
        ../lib/datastructures/linkcut.cpp)
target_include_directories(edc PRIVATE ..)
target_link_libraries(edc PRIVATE gflags::gflags glog::glog)
#target_include_directories(edc PRIVATE ${CMAKE_BINARY_DIR}/lib)