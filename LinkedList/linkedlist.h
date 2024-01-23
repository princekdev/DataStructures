#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class LinkedList
{
  class Node
  {
  public:
    int data;
    Node *next = NULL;
    Node(int val)
    {
      data = val;
    }
  };
  Node *head = NULL;

  int toArrayRecursion(Node *&traverser, int *&arr, int i = 0)
  {
    if (traverser == NULL)
    {
      arr = (int *)malloc(sizeof(int) * i);
      return i;
    }
    int size = toArrayRecursion(traverser->next, arr, i + 1);
    arr[size - 1 - i] = traverser->data;
    return size;
  }

  Node *reverseRecursion(Node *&traverser);

public:
  ~LinkedList()
  {
    while (head != NULL)
    {
      deleteAtHead();
    }
    printf("LinkedList Destructor: All deleted!");
  }

  void insertAtHead(int val)
  {
    Node *newNode = new Node(val);
    if (head == NULL)
    {
      head = newNode;
      return;
    }
    newNode->next = head;
    head = newNode;
  }

  void insertAtTail(int val)
  {
    Node *newNode = new Node(val);
    if (head == NULL)
    {
      head = newNode;
      return;
    }
    Node *traverser = head;
    while (traverser->next != NULL)
    {
      traverser = traverser->next;
    }
    traverser->next = newNode;
  }

  int deleteAtHead()
  {
    if (head == NULL)
    {
      return NULL;
    }
    Node *secondNode = head->next;
    int headNodeVal = head->data;
    delete (head);
    head = secondNode;
    return headNodeVal;
  }

  int deleteAtTail()
  {
    if (head == NULL)
    {
      return NULL;
    }
    if (head->next == NULL)
    {
      return deleteAtHead();
    }
    Node *traverser = head;
    while (traverser->next->next != NULL)
    {
      traverser = traverser->next;
    }
    int tailNodeVal = traverser->next->data;
    delete (traverser->next);
    traverser->next = NULL;
    return tailNodeVal;
  }

  int deleteKey(int key)
  {
    if (head == NULL)
    {
      return -1;
    }
    if (head->data == key)
    {
      deleteAtHead();
      return 0;
    }
    Node *traverser = head;
    int i = 0;
    while (traverser != NULL)
    {
      if (traverser->next->data == key)
      {
        if (traverser->next->next == NULL)
        {
          deleteAtTail();
          return i + 1;
        }
        Node *keyNode = traverser->next;
        traverser->next = traverser->next->next;
        delete (keyNode);
        return i + 1;
      }
      traverser = traverser->next;
      i++;
    }
    return -1;
  }

  int search(int key)
  {
    Node *traverser = head;
    int i = 0;
    while (traverser != NULL)
    {
      if (traverser->data == key)
      {
        return i;
      }
      traverser = traverser->next;
      i++;
    }
    return -1;
  }

  int findAtIndex(int index)
  {
    Node *traverser = head;
    for (int i = 0; i < index; i++)
    {
      if (traverser == NULL)
      {
        printf("Index out of range!\n");
        return NULL;
      }
      traverser = traverser->next;
    }
    return traverser->data;
  }

  int toArray(int *&arr)
  {
    if (head == NULL)
    {
      return 0;
    }
    return toArrayRecursion(head, arr);
  }

  int toArrayIterative(int *&arr)
  {
    if (head == NULL)
    {
      return 0;
    }
    Node *traverser = head;
    int size = 0;
    while (traverser != NULL)
    {
      traverser = traverser->next;
      size++;
    }
    arr = new int[size];
    int i = size - 1;
    traverser = head;
    while (traverser != NULL)
    {
      arr[i] = traverser->data;
      traverser = traverser->next;
      i--;
    }
    return size;
  }

  void print()
  {
    if (head == NULL)
    {
      printf("Head | NULL | Tail\n");
      return;
    }
    Node *traverser = head;
    printf("Head | ");
    while (traverser != NULL)
    {
      printf("%d -> ", traverser->data);
      traverser = traverser->next;
    }
    printf("NULL | Tail\n\n");
  }

  void reverseIterative();
  void reverseRecursive();
};

#endif // LINKEDLIST_H