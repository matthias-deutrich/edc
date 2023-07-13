add_library(edc_lib SHARED)

target_sources(edc_lib
        PUBLIC
        cut_matching.hpp
        expander_decomp.hpp
        datastructures/undirected_graph.hpp
        PRIVATE
        datastructures/linkcut.cpp
        datastructures/linkcut.hpp
        datastructures/splay_tree.cpp
        datastructures/splay_tree.hpp
        datastructures/subset_graph.hpp
        datastructures/unit_flow.cpp
        datastructures/unit_flow.hpp
        datastructures/graph/graph_interface.hpp
        cut_matching.cpp
        expander_decomp.cpp
        trimming.cpp
        trimming.hpp
        util.hpp)

target_link_libraries(edc_lib PRIVATE glog)