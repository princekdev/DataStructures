#include <iostream>
#include "graph.h"

int main()
{
  Graph graph(10);

  graph.insert(5);
  graph.insert(7);
  graph.link(5, 7);

  graph.insert(9);
  graph.link(5, 9);

  graph.insert(10);
  graph.link(9, 10);

  graph.breadthFirstSearch(5);
  graph.depthFirstSearch(5);
  return 0;
}