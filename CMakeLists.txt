cmake_minimum_required(VERSION 3.11)

project(edc)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED True)
#include(FetchContent)
#FetchContent_Declare(
#        googletest
#        GIT_REPOSITORY https://github.com/google/googletest
#        GIT_TAG origin/main
#)
#FetchContent_Declare(
#        glog
#        GIT_REPOSITORY https://github.com/google/glog
#)
#FetchContent_Declare(
#        gflags
#        GIT_REPOSITORY https://github.com/gflags/gflags
#)
#FetchContent_Declare(
#        abseil
#        GIT_REPOSITORY https://github.com/abseil/abseil-cpp
#)
#FetchContent_MakeAvailable(googletest glog gflags abseil)

add_subdirectory(main)