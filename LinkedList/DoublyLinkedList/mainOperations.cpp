#include <iostream>
#include "doublylinkedlist.h"

int main()
{
  int arr[3] = {2, 4, 5};

  DoublyLinkedList doublyLinkedList;

  for (int i = 0; i < 3; i++)
  {
    printf("%d inserted at tail:\n", arr[i]);
    doublyLinkedList.insertAtTail(arr[i]);
    doublyLinkedList.print();
  }

  printf("4 inserted at head:\n");
  doublyLinkedList.insertAtHead(4);
  doublyLinkedList.print();

  int index;

  printf("Searching for 4:\n");
  index = doublyLinkedList.search(4);
  if (index == -1)
  {
    printf("not found\n\n");
  }
  else
  {
    printf("present at index %d\n\n", index);
  }

  printf("Deleting 4:\n");
  index = doublyLinkedList.deleteKey(4);
  if (index == -1)
  {
    printf("not found\n\n");
  }
  else
  {
    printf("deleted at index %d:\n", index);
  }
  doublyLinkedList.print();

  printf("Deleting 5:\n");
  index = doublyLinkedList.deleteKey(5);
  if (index == -1)
  {
    printf("not found\n\n");
  }
  else
  {
    printf("deleted at index %d:\n", index);
  }
  doublyLinkedList.print();

  printf("deleted at head:\n");
  printf("%d deleted\n", doublyLinkedList.deleteAtHead());
  doublyLinkedList.print();

  printf("deleted at tail:\n");
  printf("%d deleted\n", doublyLinkedList.deleteAtTail());
  doublyLinkedList.print();

  return 0;
}