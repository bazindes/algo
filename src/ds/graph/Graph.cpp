/*
  DirectedGraph.cpp
  Created by: baz
  Date: 2019-04-10 02:00
*/

#include "Graph.h"

Graph::GraphNode::GraphNode():val(), neighbors(nullptr){}
Graph::GraphNode::GraphNode(int x):val(x), neighbors(nullptr){}
Graph::GraphNode::~GraphNode(){}