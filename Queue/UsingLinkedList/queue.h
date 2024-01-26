#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "linkedlist.h"

class Queue
{
private:
  LinkedList linkedList;
  int queueSize;
  bool noLimit;
  int queuedSize = 0;

public:
  Queue(int queueSize) : queueSize(queueSize)
  {
    if (queueSize < 0)
    {
      noLimit = 1;
    }
  }

  void push(int val)
  {
    if (isFull())
    {
      printf("Queue overflow!\n");
      return;
    }
    queuedSize++;
    linkedList.insertAtHead(val);
  }

  int pop()
  {
    if (isEmpty())
    {
      printf("Queue underflow!\n");
      return NULL;
    }
    queuedSize--;
    return linkedList.deleteAtTail();
  }

  int peek(int position)
  {
    if (queuedSize < position)
    {
      printf("Index out of Queued range!\n");
      return NULL;
    }
    return linkedList.findAtIndex(position - 1);
  }

  bool isEmpty()
  {
    if (queuedSize)
    {
      return 0;
    }
    return 1;
  }

  bool isFull()
  {
    if (noLimit)
    {
      return 0;
    }
    if (queuedSize == queueSize)
    {
      return 1;
    }
    return 0;
  }

  int top()
  {
    if (isEmpty())
    {
      printf("Empty Queue!\n");
      return NULL;
    }
    return linkedList.findAtIndex(0);
  }

  int bottom()
  {
    if (isEmpty())
    {
      printf("Empty Queue!\n");
      return NULL;
    }
    return linkedList.findAtIndex(queuedSize - 1);
  }

  void print()
  {
    printf("Top\n");
    for (int i = 0; i < queuedSize; i++)
    {
      printf("%d\n", linkedList.findAtIndex(i));
    }
    printf("Bottom\n\n");
  }
};

#endif // QUEUE_H