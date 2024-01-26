#ifndef GRAPH_H
#define GRAPH_H

#include "queue.h"
#include "stack.h"
#include "linkedlist.h"

class Graph
{
private:
  int graphSize;
  int *graphArray;
  int graphArrayTop = -1;
  bool **graphLinkageArray;

  int getNode(int data)
  {
    for (int i = 0; i <= graphArrayTop; i++)
    {
      if (graphArray[i] == data)
      {
        return i;
      }
    }
    return -1;
  }

public:
  Graph(int graphSize) : graphSize(graphSize), graphArray(new int[graphSize]), graphLinkageArray(new bool *[graphSize])
  {
    for (int i = 0; i < graphSize; i++)
    {
      graphLinkageArray[i] = new bool[graphSize];
      for (int j = 0; j < graphSize; j++)
      {
        graphLinkageArray[i][j] = 0;
      }
    }
  }

  bool insert(int data)
  {
    graphArray[++graphArrayTop] = data;
  }

  bool link(int data1, int data2)
  {
    int node1 = getNode(data1), node2 = getNode(data2);
    if (node1 == -1 || node2 == -1)
    {
      printf("Not present:\n");
      for (int i = 0; i < graphArrayTop; i++)
      {
        printf("%d ", graphArray[i]);
      }
      printf("\n");
      return 0;
    }
    if (graphLinkageArray[node1][node2] == 1)
    {
      return 0;
    }
    return graphLinkageArray[node1][node2] = 1;
  }

  LinkedList getLinks(int node)
  {
    LinkedList nodeLinks;
    for (int i = 0; i <= graphArrayTop; i++)
    {
      if (graphLinkageArray[node][i] == 1)
      {
        nodeLinks.insertAtTail(i);
      }
    }
    return nodeLinks;
  }

  void breadthFirstSearch(int data)
  {
    int startNode = getNode(data);
    if (startNode == -1)
    {
      return;
    }
    if (graphArrayTop == -1)
    {
      return;
    }
    LinkedList visited;
    Queue explorationQueue(-1);

    explorationQueue.push(startNode);
    while (!explorationQueue.isEmpty())
    {
      int visitingNode = explorationQueue.pop();
      visited.insertAtTail(visitingNode);

      LinkedList links = getLinks(visitingNode);
      int linkedNode = links.deleteAtHead();
      while (linkedNode != NULL)
      {
        if (visited.search(linkedNode) == -1)
        {
          explorationQueue.push(linkedNode);
        }
        linkedNode = links.deleteAtHead();
      }
    }

    int *nodes;
    int n = visited.toArray(nodes);
    for (int i = n - 1; i > -1; i--)
    {
      printf("%d ", graphArray[nodes[i]]);
    }
    printf("\n");
  }

  void depthFirstSearch(int data)
  {
    int startNode = getNode(data);
    if (startNode == -1)
    {
      return;
    }
    if (graphArrayTop == -1)
    {
      return;
    }
    LinkedList visited;
    Stack explorationStack(-1);

    explorationStack.push(startNode);
    while (!explorationStack.isEmpty())
    {
      int visitingNode = explorationStack.pop();
      visited.insertAtTail(visitingNode);

      LinkedList links = getLinks(visitingNode);
      int linkedNode = links.deleteAtHead();
      while (linkedNode != NULL)
      {
        if (visited.search(linkedNode) == -1)
        {
          explorationStack.push(linkedNode);
        }
        linkedNode = links.deleteAtHead();
      }
    }

    int *nodes;
    int n = visited.toArray(nodes);
    for (int i = n - 1; i > -1; i--)
    {
      printf("%d ", graphArray[nodes[i]]);
    }
    printf("\n");
  }

  ~Graph()
  {
    printf("Graph Destructor: All deleted!");
    delete[] graphArray;
    for (int i = 0; i < graphSize; i++)
    {
      delete[] graphLinkageArray[i];
    }
    delete[] graphLinkageArray;
  }
};

#endif // GRAPH_H