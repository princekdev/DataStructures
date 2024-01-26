#include <iostream>
#include "linkedList.h"
#include "stack.h"

int main()
{
  int arr[5] = {1, 3, 5, 7, 9};
  Stack<int> stack(10);
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