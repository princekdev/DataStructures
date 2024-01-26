#include <iostream>
#include "queue.h"

int main()
{
  int arr[10] = {1, 3, 5, 7, 9, 4, 5, 7, 3, 2};
  Queue queue(20);
  printf("enqueue operations:\n");
  for (int i = 0; i < 10; i++)
  {
    printf("%d enqueued\n", arr[i]);
    queue.enqueue(arr[i]);
  }
  queue.print();

  printf("dequeue operation:\n");
  int dequeueped = queue.dequeue();
  printf("%d dequeueped\n", dequeueped);
  queue.print();

  printf("Peek operation:\n");
  int position = 2;
  int element = queue.peek(position);
  printf("%d present at position %d from top\n", element, position);

  printf("enqueue operation of 4:\n");
  queue.enqueue(4);

  printf("enqueue operation of 9:\n");
  queue.enqueue(9);

  return 0;
}