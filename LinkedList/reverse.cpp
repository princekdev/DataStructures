#include <iostream>
#include "linkedlist.h"

void LinkedList::reverseIterative()
{
  LinkedList::Node *previousNode = NULL, *currentNode = head, *nextNode = head->next;
  int i = 0;
  while (true)
  {
    currentNode->next = previousNode;
    if (nextNode == NULL)
    {
      break;
    }
    previousNode = currentNode;
    currentNode = nextNode;
    nextNode = nextNode->next;
    i++;
  }
  head = currentNode;
}

LinkedList::Node *LinkedList::reverseRecursion(Node *&traverser)
{
  if (traverser->next == NULL)
  {
    return traverser;
  }
  Node *newHead = reverseRecursion(traverser->next);
  traverser->next->next = traverser;
  if (traverser == head)
  {
    traverser->next = NULL;
  }
  return newHead;
}

void LinkedList::reverseRecursive()
{
  head = reverseRecursion(head);
}

int main()
{
  int arr[3] = {2, 4, 5};

  LinkedList linkedList;

  for (int i = 0; i < 3; i++)
  {
    printf("%d inserted at tail:\n", arr[i]);
    linkedList.insertAtTail(arr[i]);
  }

  printf("Linked List: \n");
  linkedList.print();

  printf("After Iterative Reverse: \n");
  linkedList.reverseIterative();
  linkedList.print();

  printf("Now, After Recursive Reverse: \n");
  linkedList.reverseRecursive();
  linkedList.print();

  return 0;
}