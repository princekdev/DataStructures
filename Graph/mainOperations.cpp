#include <iostream>
#include "graph.h"

int main()
{
  Graph<int> graph(10);

  graph.insert(5);
  graph.insert(7);
  graph.link(5, 7);

  graph.insert(9);
  graph.link(5, 9);

  graph.insert(10);
  graph.link(9, 10);

  printf("Breadth First Search:\n");
  int *arrFromSearch;
  int size = graph.breadthFirstSearch(5, arrFromSearch);
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arrFromSearch[i]);
  }
  printf("\n");
  delete[] arrFromSearch;

  printf("Depth First Search:\n");
  size = graph.depthFirstSearch(5, arrFromSearch);
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arrFromSearch[i]);
  }
  printf("\n");
  delete[] arrFromSearch;

  return 0;
}