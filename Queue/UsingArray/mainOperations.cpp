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
      printf("Index out of Queueed range!\n");
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