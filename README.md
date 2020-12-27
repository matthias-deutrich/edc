# Expander Decomposition & Clustering (EDC)

This is an implementation of [Expander decomposition and pruning: Faster,
stronger, and simpler.](https://arxiv.org/pdf/1812.08958.pdf) by Thatchaphol
Saranurak and Di Wang.

## Building

The project is built using the [Bazel](https://bazel.build) build system. Using
the 'build' command a binary will be built and moved to
'bazel-bin/main/expander-decomp':

``` shell
# Build optimized configuration
bazel build -c opt //main:expander-decomp

# Build debug configuration
bazel build -c dbg //main:expander-decomp

# Build with better debug information and sanitizers
bazel build --config debug --compilation_mode dbg --sandbox_debug //main:expander-decomp
```

## Testing

Tests are run using Bazel and [Google Test](https://github.com/google/googletest):

``` shell
bazel test --test_output=all --compilation_mode dbg //test:cluster_util_test --sandbox_debug
# or
./test.sh
```

## Running

The following will compute an expander decomposition of a dumbbell graph with 4
cliques each of size 20:

``` shell
./experiment/gen_graph.py dumbbell -n=20 -k=4 | ./bazel-bin/main/expander-decomp
```

This will output the number of edges cut and the number of partitions, followed
by one line per partition giving the size and the conductance of the cut with
respect to the entire graph.

To also output the vertices of each partition, use the option '-partitions':

``` shell
./experiment/gen_graph.py dumbbell -n=20 -k=4 | ./bazel-bin/main/expander-decomp -partitions
```

To view the progress of the program during execution logging can be enabled:

``` shell
./experiment/gen_graph.py dumbbell -n=20 -k=4 | ./bazel-bin/main/expander-decomp --logtostderr -v=2
```

The most useful verbosity level is '-v=2' but if one wants to see the progress
of each cut-matching step '-v=3' can be used instead.

The target conductance can be changed using the '-phi' option:

``` shell
./experiment/gen_graph.py dumbbell -n=20 -k=4 | ./bazel-bin/main/expander-decomp -phi=0.001
```

All available options can be seen using the help command:

``` shell
./bazel-bin/main/expander-decomp --help
```

## Graph formats

The 'expander-decomp' executable reads graphs from standard input. There are two
graph formats supported:
1. A line with two integers N, M specifying the number of vertices and edges
   respectively. This is followed by M lines each with two integers U,V
   specifying an edge between 0-indexed vertices U and V.
2. The [Chaco](https://chriswalshaw.co.uk/jostle/jostle-exe.pdf) file format
   enabled with the option '-chaco'.
