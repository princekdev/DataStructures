#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

class Queue
{
private:
  int queueSize = 10;
  int arr[10];
  int queueTop = -1;
  int queueBottom = 0;

public:
  void push(int val)
  {
    if (isFull())
    {
      printf("Queue overflow!\n");
      return;
    }
    queueTop++;
    arr[queueTop] = val;
  }

  int pop()
  {
    if (isEmpty())
    {
      printf("Queue underflow!\n");
      return NULL;
    }
    queueBottom++;
    return arr[queueBottom - 1];
  }

  int peek(int position)
  {
    if (queueTop + 1 - queueBottom < position)
    {
      printf("Index out of Queued range!\n");
      return NULL;
    }
    return arr[queueTop + 1 - position];
  }

  bool isEmpty()
  {
    if (queueTop < queueBottom)
    {
      return 1;
    }
    return 0;
  }

  bool isFull()
  {
    if (queueTop == queueSize - 1)
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
    return arr[queueTop];
  }

  int bottom()
  {
    if (isEmpty())
    {
      printf("Empty Queue!\n");
      return NULL;
    }
    return arr[queueBottom];
  }

  void print()
  {
    printf("Top\n");
    for (int i = queueTop; i >= queueBottom; i--)
    {
      printf("%d\n", arr[i]);
    }
    printf("Bottom\n\n");
  }
};

#endif // QUEUE_H