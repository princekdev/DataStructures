#include <iostream>
#include "linkedlist.h"

class Queue
{
private:
  int queueSize = 10;
  LinkedList linkedList;
  int queuedSize = 0;

public:
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
      printf("Index out of Queueed range!\n");
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

int main()
{
  int arr[10] = {1, 3, 5, 7, 9, 4, 5, 7, 3, 2};
  Queue queue;
  printf("Push operations:\n");
  for (int i = 0; i < 10; i++)
  {
    printf("%d pushed\n", arr[i]);
    queue.push(arr[i]);
  }
  queue.print();

  printf("Pop operation:\n");
  int popped = queue.pop();
  printf("%d popped\n", popped);
  queue.print();

  printf("Peek operation:\n");
  int position = 2;
  int element = queue.peek(position);
  printf("%d present at position %d from top\n", element, position);

  printf("push operation of 4:\n");
  queue.push(4);

  printf("push operation of 9:\n");
  queue.push(9);

  return 0;
}