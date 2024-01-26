#ifndef LINKEDLISTEXTENDED_H
#define LINKEDLISTEXTENDED_H

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

  Node *reverseRecursion(Node *&traverser)
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
    printf("Head | ");
    while (traverser != NULL)
    {
      printf("%d -> ", traverser->data);
      traverser = traverser->next;
    }
    printf("NULL | Tail\n\n");
  }

  void reverseIterative()
  {
    Node *previousNode = NULL, *currentNode = head, *nextNode = head->next;
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

  void reverseRecursive()
  {
    head = reverseRecursion(head);
  }

  ~LinkedList()
  {
    while (head != NULL)
    {
      deleteAtHead();
    }
  }
};

#endif // LINKEDLISTEXTENDED_H