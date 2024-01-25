#include <iostream>
#include "linkedlist.h"
#include "queue.h"

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