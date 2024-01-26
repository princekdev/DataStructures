#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

class Queue
{
private:
  int queueSize;
  int *queueArray;
  int queueTop = -1;
  int queueBottom = 0;

public:
  Queue(int queueSize) : queueSize(queueSize), queueArray(new int[queueSize])
  {
  }

  void enqueue(int val)
  {
    if (isFull())
    {
      printf("Queue overflow!\n");
      return;
    }
    queueTop++;
    queueArray[queueTop] = val;
  }

  int dequeue()
  {
    if (isEmpty())
    {
      printf("Queue underflow!\n");
      return NULL;
    }
    queueBottom++;
    return queueArray[queueBottom - 1];
  }

  int peek(int position)
  {
    if (queueTop + 1 - queueBottom < position)
    {
      printf("Index out of Queued range!\n");
      return NULL;
    }
    return queueArray[queueTop + 1 - position];
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
    for (int i = queueTop; i >= queueBottom; i--)
    {
      printf("%d\n", queueArray[i]);
    }
    printf("Bottom\n\n");
  }

  ~Queue()
  {
    delete[] queueArray;
  }
};

#endif // QUEUE_H