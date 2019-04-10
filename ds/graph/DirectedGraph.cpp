/*
  DirectedGraph.cpp
  Created by: baz
  Date: 2019-04-10 02:00
*/

#include "DirectedGraph.h"

DirectedGraph::GraphNode::GraphNode():val(), neighbors(NULL){}
DirectedGraph::GraphNode::GraphNode(int x):val(x), neighbors(NULL){}
DirectedGraph::GraphNode::~GraphNode(){}