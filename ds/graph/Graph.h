/*
  DirectedGraph.h
  Created by: baz
  Date: 2019-04-10 01:55
*/

#include <vector>

namespace Graph {

struct GraphNode {
  int val;
  std::vector<GraphNode> neighbors;

  GraphNode();
  GraphNode(int x);
  ~GraphNode();
};

} // namespace DirectedGraph
