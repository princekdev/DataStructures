#include <iostream>
#include "linkedList.h"

class Stack
{
private:
  LinkedList linkedList;
  int stackBottom = -1;

public:
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
    if (stackBottom == 19)
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

int main()
{
  int arr[5] = {1, 3, 5, 7, 9};
  Stack stack;
  printf("Push operations:\n");
  for (int i = 0; i < 5; i++)
  {
    printf("%d pushed\n", arr[i]);
    stack.push(arr[i]);
  }
  stack.print();

  printf("Pop operation:\n");
  int popped = stack.pop();
  printf("%d popped\n", popped);
  stack.print();

  printf("Peek operation:\n");
  int position = 2;
  int element = stack.peek(position);
  printf("%d present at position %d from top\n", element, position);

  return 0;
}