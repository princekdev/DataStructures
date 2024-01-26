#include <iostream>
#include "linkedlistextended.h"

int main()
{
  int arr[3] = {2, 4, 5};

  LinkedList<int> linkedList;

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