#ifndef GRAPH_H
#define GRAPH_H

#include "queue.h"
#include "stack.h"
#include "linkedlist.h"

template <typename elementType>
class Graph
{
private:
  int graphSize;
  elementType *graphArray;
  int graphArrayTop = -1;
  bool **graphLinkageArray;

  int getNode(elementType data)
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
  Graph(int graphSize) : graphSize(graphSize), graphArray(new elementType[graphSize]), graphLinkageArray(new bool *[graphSize])
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

  bool insert(elementType data)
  {
    for (int i = 0; i <= graphArrayTop; i++)
    {
      if (graphArray[i] == data)
      {
        printf("Already present!\n");
        return 0;
      }
    }
    graphArray[++graphArrayTop] = data;
    return 1;
  }

  bool link(elementType data1, elementType data2)
  {
    int node1 = getNode(data1), node2 = getNode(data2);
    if (node1 == -1 || node2 == -1)
    {
      printf("Not present!\n");
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

  LinkedList<int> getLinks(int node)
  {
    LinkedList<int> nodeLinks;
    for (int i = 0; i <= graphArrayTop; i++)
    {
      if (graphLinkageArray[node][i] == 1)
      {
        nodeLinks.insertAtTail(i);
      }
    }
    return nodeLinks;
  }

  int breadthFirstSearch(elementType data, elementType *&returnArr)
  {
    int startNode = getNode(data);
    if (startNode == -1)
    {
      printf("Not present!\n");
      return 0;
    }
    if (graphArrayTop == -1)
    {
      return 0;
    }
    LinkedList<int> visited;
    Queue<int> explorationQueue(-1);

    explorationQueue.enqueue(startNode);
    while (!explorationQueue.isEmpty())
    {
      int visitingNode = explorationQueue.dequeue();
      visited.insertAtTail(visitingNode);

      LinkedList<int> links = getLinks(visitingNode);
      int linkedNode = links.deleteAtHead();
      while (linkedNode != NULL)
      {
        if (visited.search(linkedNode) == -1)
        {
          explorationQueue.enqueue(linkedNode);
        }
        linkedNode = links.deleteAtHead();
      }
    }

    int *returnNodes;
    int returnNodesSize = visited.toArray(returnNodes);
    returnArr = new elementType[returnNodesSize];
    for (int i = 0; i < returnNodesSize; i++)
    {
      returnArr[i] = graphArray[returnNodes[returnNodesSize - 1 - i]];
    }
    delete[] returnNodes;
    return returnNodesSize;
  }

  int depthFirstSearch(int data, elementType *&returnArr)
  {
    int startNode = getNode(data);
    if (startNode == -1)
    {
      return 0;
    }
    if (graphArrayTop == -1)
    {
      return 0;
    }
    LinkedList<int> visited;
    Stack<int> explorationStack(-1);

    explorationStack.push(startNode);
    while (!explorationStack.isEmpty())
    {
      int visitingNode = explorationStack.pop();
      visited.insertAtTail(visitingNode);

      LinkedList<int> links = getLinks(visitingNode);
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

    int *returnNodes;
    int returnNodesSize = visited.toArray(returnNodes);
    returnArr = new elementType[returnNodesSize];
    for (int i = 0; i < returnNodesSize; i++)
    {
      returnArr[i] = graphArray[returnNodes[returnNodesSize - 1 - i]];
    }
    delete[] returnNodes;
    return returnNodesSize;
  }

  ~Graph()
  {
    delete[] graphArray;
    for (int i = 0; i < graphSize; i++)
    {
      delete[] graphLinkageArray[i];
    }
    delete[] graphLinkageArray;
  }
};

#endif // GRAPH_H