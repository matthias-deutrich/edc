#pragma once

#include <iostream>
#include <memory>
#include <set>
#include <string>

#include "lib/datastructures/undirected_graph.hpp"

std::unique_ptr<std::mt19937> configureRandomness(unsigned int seed) {
  std::random_device rd;
  const unsigned int s = seed == 0 ? int(rd()) : seed;

  std::srand(s);
  std::mt19937 randomGen(s);

  return std::make_unique<std::mt19937>(randomGen);
}

/**
   Read an undirected graph from standard input. If 'chaco_format' is true, read
   graph as specified in 'https://chriswalshaw.co.uk/jostle/jostle-exe.pdf'.
   Otherwise assume edges are given as 'm' vertex pairs. Duplicate edges are
   ignored.
 */
std::unique_ptr<Undirected::Graph> readGraph(std::istream &in_stream, bool chaco_format) {
  int n, m;
  in_stream >> n >> m;

  std::vector<Undirected::Edge> es;
  if (chaco_format) {
    in_stream.ignore();
    for (int u = 0; u < n; ++u) {
      std::string line;
      std::getline(in_stream, line);
      std::stringstream ss(line);

      int v;
      while (ss >> v)
        if (u < --v)
          es.emplace_back(u, v);
    }
  } else {
    std::set<std::pair<int, int>> seen;
    for (int i = 0; i < m; ++i) {
      int u, v;
      in_stream >> u >> v;
      if (u > v)
        std::swap(u, v);
      if (seen.find({u, v}) == seen.end()) {
        seen.insert({u, v});
        es.emplace_back(u, v);
      }
    }
  }

  return std::make_unique<Undirected::Graph>(n, es);
}
