#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

template <typename elementType>
class DoublyLinkedList
{
  class Node
  {
  public:
    elementType data;
    Node *previous = NULL, *next = NULL;
    Node(elementType val)
    {
      data = val;
    }
  };
  Node *head = NULL, *tail = NULL;

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
      tail = newNode;
      return;
    }
    head->previous = newNode;
    newNode->next = head;
    head = newNode;
  }

  void insertAtTail(elementType val)
  {
    Node *newNode = new Node(val);
    if (head == NULL)
    {
      head = newNode;
      tail = newNode;
      return;
    }
    tail->next = newNode;
    newNode->previous = tail;
    tail = newNode;
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
    if (secondNode == NULL)
    {
      tail = NULL;
    }
    else
    {
      secondNode->previous = NULL;
    }
    return headNodeVal;
  }

  elementType deleteAtTail()
  {
    if (head == NULL)
    {
      return NULL;
    }
    Node *secondLastNode = tail->previous;
    elementType tailNodeVal = tail->data;
    delete (tail);
    tail = secondLastNode;
    if (secondLastNode == NULL)
    {
      head = NULL;
    }
    else
    {
      secondLastNode->next = NULL;
    }
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
      return 0;
    }
    return toArrayRecursion(head, arr);
  }

  int toArrayIterative(elementType *&arr)
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
    printf("Head | NULL <- ");
    while (traverser != NULL)
    {
      printf("%d <-> ", traverser->data);
      traverser = traverser->next;
    }
    printf("\b\b\b\b-> NULL | Tail\n\n");
  }

  ~DoublyLinkedList()
  {
    while (head != NULL)
    {
      deleteAtHead();
    }
  }
};

#endif // DOUBLYLINKEDLIST_H