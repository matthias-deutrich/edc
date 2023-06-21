add_executable(edc edc.cpp)
target_include_directories(edc PRIVATE ..)
target_link_libraries(edc PRIVATE edc_lib gflags glog)

add_executable(edc_bench edc_bench.cpp)
target_include_directories(edc_bench PRIVATE ..)
target_link_libraries(edc_bench PRIVATE edc_lib gflags glog)

add_executable(edc_cut edc_cut.cpp)
target_include_directories(edc_cut PRIVATE ..)
target_link_libraries(edc_cut PRIVATE edc_lib gflags glog)