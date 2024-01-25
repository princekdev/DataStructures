#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack
{
private:
  int stackSize;
  int *stackArray;
  int stackTop = -1;

public:
  Stack(int stackSize) : stackSize(stackSize), stackArray(new int[stackSize])
  {
  }

  void push(int val)
  {
    if (isFull())
    {
      printf("Stack overflow!\n");
      return;
    }
    stackArray[stackTop + 1] = val;
    stackTop++;
  }

  int pop()
  {
    if (isEmpty())
    {
      printf("Stack underflow!\n");
      return NULL;
    }
    stackTop--;
    return stackArray[stackTop + 1];
  }

  int peek(int position)
  {
    if (stackTop + 1 < position)
    {
      printf("Index out of stacked range!\n");
      return NULL;
    }
    return stackArray[stackTop + 1 - position];
  }

  bool isEmpty()
  {
    if (stackTop == -1)
    {
      return 1;
    }
    return 0;
  }

  bool isFull()
  {
    if (stackTop == stackSize - 1)
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
    return stackArray[stackTop];
  }

  int bottom()
  {
    if (isEmpty())
    {
      printf("Empty stack!\n");
      return NULL;
    }
    return stackArray[0];
  }

  void print()
  {
    printf("Top\n");
    for (int i = stackTop; i > -1; i--)
    {
      printf("%d\n", stackArray[i]);
    }
    printf("Bottom\n\n");
  }

  ~Stack()
  {
    printf("Stack Destructor: All deleted!");
    delete[] stackArray;
  }
};

#endif // STACK_H