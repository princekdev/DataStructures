#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

class Queue
{
private:
  int queueSize;
  int *queueArray = (int *)malloc(sizeof(int) * queueSize);
  int queueTop = -1;
  int queueBottom = 0;
  int queuedSize = 0;

public:
  Queue(int queueSize) : queueSize(queueSize), queueArray(new int[queueSize])
  {
  }

  void push(int val)
  {
    if (isFull())
    {
      printf("Queue overflow!\n");
      return;
    }
    queueTop = (queueTop + 1) % queueSize;
    queueArray[queueTop] = val;
    queuedSize++;
  }

  int pop()
  {
    if (isEmpty())
    {
      printf("Queue underflow!\n");
      return NULL;
    }
    int bottomVal = queueArray[queueBottom];
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
    return queueArray[(queueBottom + queuedSize - position) % queueSize];
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
    return queueArray[queueTop];
  }

  int bottom()
  {
    if (isEmpty())
    {
      printf("Empty Queue!\n");
      return NULL;
    }
    return queueArray[queueBottom];
  }

  void print()
  {
    printf("Top\n");
    int i = queueTop;
    while (i != queueBottom)
    {
      printf("%d\n", queueArray[i]);
      i--;
      if (i == -1)
      {
        i = queueSize - 1;
      }
    }
    printf("%d\n", queueArray[queueBottom]);
    printf("Bottom\n\n");
  }

  ~Queue()
  {
    printf("Queue Destructor: All deleted!");
    delete[] queueArray;
  }
};

#endif // QUEUE_H