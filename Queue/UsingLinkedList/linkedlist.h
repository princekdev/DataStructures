#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename elementType>
class LinkedList
{
  class Node
  {
  public:
    elementType data;
    Node *next = NULL;
    Node(elementType val)
    {
      data = val;
    }
  };
  Node *head = NULL;

  int toArrayRecursion(Node *&traverser, elementType *&arr, int i = 0)
  {
    if (traverser == NULL)
    {
      arr = new elementType[i];
      return i;
    }
    int size = toArrayRecursion(traverser->next, arr, i + 1);
    arr[size - 1 - i] = traverser->data;
    return size;
  }

public:
  void insertAtHead(elementType val)
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

  void insertAtTail(elementType val)
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

  bool insertAtIndex(int index, elementType val)
  {
    if (index < 0)
    {
      return 0;
    }
    if (head == NULL)
    {
      if (index == 0)
      {
        insertAtHead(val);
        return 1;
      }
      return 0;
    }
    Node *traverser = head;
    for (int i = 0; i < index - 1; i++)
    {
      traverser = traverser->next;
      if (traverser == NULL)
      {
        return 0;
      }
    }
    Node *newNode = new Node(val);
    newNode->next = traverser->next;
    traverser->next = newNode;
    return 1;
  }

  elementType deleteAtHead()
  {
    if (head == NULL)
    {
      return NULL;
    }
    Node *secondNode = head->next;
    elementType headNodeVal = head->data;
    delete (head);
    head = secondNode;
    return headNodeVal;
  }

  elementType deleteAtTail()
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
    elementType tailNodeVal = traverser->next->data;
    delete (traverser->next);
    traverser->next = NULL;
    return tailNodeVal;
  }

  int deleteKey(elementType key)
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
    while (traverser->next != NULL)
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

  void deleteAll()
  {
    while (head != NULL)
    {
      deleteAtHead();
    }
  }

  int search(elementType key)
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

  elementType findAtIndex(int index)
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

  int toArray(elementType *&arr)
  {
    if (head == NULL)
    {
      arr = nullptr;
      return 0;
    }
    return toArrayRecursion(head, arr);
  }

  int toArrayIterative(elementType *&arr)
  {
    if (head == NULL)
    {
      arr = nullptr;
      return 0;
    }
    Node *traverser = head;
    int size = 0;
    while (traverser != NULL)
    {
      traverser = traverser->next;
      size++;
    }
    arr = new elementType[size];
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

  ~LinkedList()
  {
    deleteAll();
  }
};

#endif // LINKEDLIST_H