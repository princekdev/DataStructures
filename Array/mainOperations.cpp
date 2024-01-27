#include <iostream>
#include "array.h"

int main()
{
  Array<int> array(5);
  array.insert(5);
  array.insert(7);
  array.insert(3);
  array.insert(6);

  if (array.insert(9))
  {
    printf("9 inserted\n");
  }
  else
  {
    printf("array filled completely\n");
  }

  if (array.insert(7))
  {
    printf("7 inserted\n");
  }
  else
  {
    printf("array filled completely\n");
  }

  for (int i = 0; i < array.getSize(); i++)
  {
    printf("%d ", array.get(i));
  }
  printf("\n");

  if (array.set(1, 8))
  {
    printf("set 8 at index 1\n");
  }
  else
  {
    printf("index out of range\n");
  }

  for (int i = 0; i < array.getSize(); i++)
  {
    printf("%d ", array.get(i));
  }
  printf("\n");

  array.resize(-10);

  if (array.insert(10))
  {
    printf("10 inserted\n");
  }
  else
  {
    printf("array filled completely\n");
  }

  for (int i = 0; i < array.getSize(); i++)
  {
    printf("%d ", array.get(i));
  }
  printf("\n");

  printf("searching for 3: ");
  int res = array.search(3);
  if (res > -1)
  {
    printf("found at index %d\n", res);
  }
  else
  {
    printf("not found\n");
  }

  return 0;
}