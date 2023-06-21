cmake_minimum_required(VERSION 3.11)

project(edc)

set(CMAKE_BUILD_TYPE "DEBUG")
#set(CMAKE_BUILD_TYPE "RELEASE")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

cmake_policy(SET CMP0076 NEW)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

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
set(ABSL_PROPAGATE_CXX_STD ON)
FetchContent_MakeAvailable(googletest glog gflags abseil)

add_subdirectory(lib)
add_subdirectory(main)