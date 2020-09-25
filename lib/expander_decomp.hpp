#pragma once

#include <vector>

#include "unit_flow.hpp"
#include "ugraph.hpp"

namespace ExpanderDecomposition {

/**
   Construct a flow graph equivalent to 'g' with all edge capacities set to 0.
 */
std::unique_ptr<UnitFlow::Graph>
constructFlowGraph(const std::unique_ptr<Undirected::Graph> &g);

/**
   Construct a subdivision flow graph from 'g' with all edge capacities set to
   0.
 */
std::unique_ptr<UnitFlow::Graph>
constructSubdivisionFlowGraph(const std::unique_ptr<Undirected::Graph> &g);

/**
   Constructs and solves a expander decomposition problem.
 */
class Solver {
private:
  /**
     Two flow graphs are maintained. Let 'graph = (V,E)'. Then '{e.id + |V| | e
     \in E}' is the vertex ids of the split vertices in 'subdivisionFlowGraph'.
   */
  std::unique_ptr<UnitFlow::Graph> flowGraph, subdivisionFlowGraph;
  const double phi;

  /**
     Compute expander decomposition for subset of vertices 'xs'.
   */
  void compute(const std::vector<int> &xs, int partition);

public:
  /**
     Create a decomposition problem with n vertices.
   */
  Solver(std::unique_ptr<Undirected::Graph> g, const double phi);

  /**
     Return the computed partition as a vector of disjoint vertex vectors.
   */
  std::vector<std::vector<int>> getPartition() const;
};
} // namespace ExpanderDecomposition
