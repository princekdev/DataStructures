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
  int queuedSize = 0;

public:
  void push(int val)
  {
    if (isFull())
    {
      printf("Queue overflow!\n");
      return;
    }
    queueTop = (queueTop + 1) % queueSize;
    arr[queueTop] = val;
    queuedSize++;
  }

  int pop()
  {
    if (isEmpty())
    {
      printf("Queue underflow!\n");
      return NULL;
    }
    int bottomVal = arr[queueBottom];
    queueBottom = (queueBottom + 1) % queueSize;
    printf("queueBottom = %d\n", queueBottom);
    queuedSize--;
    return bottomVal;
  }

  int peek(int position)
  {
    if (queuedSize < position)
    {
      printf("Index out of Queued range!\n");
      return NULL;
    }
    return arr[(queueBottom + queuedSize - position) % queueSize];
  }

  bool isEmpty()
  {
    if (queuedSize == 0)
    {
      return 1;
    }
    return 0;
  }

  bool isFull()
  {
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
    int i = queueTop;
    while (i != queueBottom)
    {
      printf("%d\n", arr[i]);
      i--;
      if (i == -1)
      {
        i = queueSize - 1;
      }
    }
    printf("%d\n", arr[queueBottom]);
    printf("Bottom\n\n");
  }
};

#endif // QUEUE_H