#include <iostream>
#include "linkedlist.h"

int main()
{
  int arr[3] = {2, 4, 5};

  LinkedList<int> linkedList;

  for (int i = 0; i < 3; i++)
  {
    printf("%d inserted at tail:\n", arr[i]);
    linkedList.insertAtTail(arr[i]);
    linkedList.print();
  }

  printf("4 inserted at head:\n");
  linkedList.insertAtHead(4);
  linkedList.print();

  linkedList.deleteAll();
  if (linkedList.insertAtIndex(0, 6))
  {
    printf("6 inserted at index 5:\n");
    linkedList.print();
  }
  else
  {
    printf("index out of range!\n");
  }

  printf("converting to array and printing:\n");
  int *arrayFromLinkedList;
  int size = linkedList.toArray(arrayFromLinkedList);
  printf("[ ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arrayFromLinkedList[i]);
  }
  printf("]\n\n");

  delete[] arrayFromLinkedList;

  printf("converting to array iteratively and printing:\n");
  size = linkedList.toArrayIterative(arrayFromLinkedList);
  printf("[ ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arrayFromLinkedList[i]);
  }
  printf("]\n\n");

  delete[] arrayFromLinkedList;

  int index;

  printf("Searching for 4:\n");
  index = linkedList.search(4);
  if (index == -1)
  {
    printf("not found\n\n");
  }
  else
  {
    printf("present at index %d\n\n", index);
  }

  printf("Deleting 4:\n");
  index = linkedList.deleteKey(4);
  if (index == -1)
  {
    printf("not found\n\n");
  }
  else
  {
    printf("deleted at index %d:\n", index);
  }
  linkedList.print();

  printf("deleted at head:\n");
  linkedList.deleteAtHead();
  linkedList.print();

  printf("deleted at tail:\n");
  linkedList.deleteAtTail();
  linkedList.print();

  printf("Deleting 4:\n");
  index = linkedList.deleteKey(4);
  if (index == -1)
  {
    printf("not found\n\n");
  }
  else
  {
    printf("deleted at index %d:\n", index);
  }
  linkedList.print();

  int deletedKey;
  do
  {
    deletedKey = linkedList.deleteAtHead();
  } while (deletedKey != NULL);

  return 0;
}