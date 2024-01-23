#include <iostream>

class Stack
{
private:
  int stackSize = 10;
  int arr[10];
  int stackTop = -1;

public:
  void push(int val)
  {
    if (isFull())
    {
      printf("Stack overflow!\n");
      return;
    }
    arr[stackTop + 1] = val;
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
    return arr[stackTop + 1];
  }

  int peek(int position)
  {
    if (stackTop + 1 < position)
    {
      printf("Index out of stacked range!\n");
      return NULL;
    }
    return arr[stackTop + 1 - position];
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
    return arr[stackTop];
  }

  int bottom()
  {
    if (isEmpty())
    {
      printf("Empty stack!\n");
      return NULL;
    }
    return arr[0];
  }

  void print()
  {
    printf("Top\n");
    for (int i = stackTop; i > -1; i--)
    {
      printf("%d\n", arr[i]);
    }
    printf("Bottom\n\n");
  }
};

int main()
{
  int arr[10] = {1, 3, 5, 7, 9, 4, 5, 7, 3, 2};
  Stack stack;
  printf("Push operations:\n");
  for (int i = 0; i < 10; i++)
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

  printf("push operation of 4:\n");
  stack.push(4);

  printf("push operation of 9:\n");
  stack.push(9);

  return 0;
}