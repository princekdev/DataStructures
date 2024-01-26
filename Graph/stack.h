#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "linkedlist.h"

class Stack
{
private:
  LinkedList linkedList;
  int stackSize;
  bool noLimit;
  int stackBottom = -1;

public:
  Stack(int stackSize) : stackSize(stackSize)
  {
    if (stackSize < 0)
    {
      noLimit = 1;
    }
  }

  void push(int val)
  {
    if (isFull())
    {
      printf("Stack overflow!\n");
      return;
    }
    linkedList.insertAtHead(val);
    stackBottom++;
  }

  int pop()
  {
    if (isEmpty())
    {
      printf("Stack underflow!\n");
      return NULL;
    }
    int val = linkedList.findAtIndex(0);
    linkedList.deleteAtHead();
    stackBottom--;
    return val;
  }

  int peek(int position)
  {
    if (stackBottom + 1 < position)
    {
      printf("Index out of stacked range!\n");
      return NULL;
    }
    return linkedList.findAtIndex(position - 1);
  }

  bool isEmpty()
  {
    if (stackBottom == -1)
    {
      return 1;
    }
    return 0;
  }

  bool isFull()
  {
    if (noLimit)
    {
      return 0;
    }
    if (stackBottom == stackSize - 1)
    {
      return 1;
    }
    return 0;
  }

  int top()
  {
    if (isEmpty())
    {
      printf("Empty stack!\n");
      return NULL;
    }
    return linkedList.findAtIndex(0);
  }

  int bottom()
  {
    if (isEmpty())
    {
      printf("Empty stack!\n");
      return NULL;
    }
    return linkedList.findAtIndex(stackBottom);
  }

  void print()
  {
    printf("Top\n");
    for (int i = 0; i <= stackBottom; i++)
    {
      printf("%d\n", linkedList.findAtIndex(i));
    }
    printf("Bottom\n\n");
  }
};

#endif // STACK_H