#include <iostream>
#include "heap.h"

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  MaxHeap maxHeap(10);
  for (auto i : arr)
  {
    maxHeap.push(i);
  }

  std::cout << "MaxHeap formed:" << '\n';
  maxHeap.print();

  std::cout << "Deleting root:" << '\n';
  int deleted = maxHeap.pop();

  std::cout << deleted << " deleted" << '\n';
  maxHeap.print();

  int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  MinHeap minHeap(10);
  for (auto i : arr2)
  {
    minHeap.push(i);
  }

  std::cout << "MinHeap formed:" << '\n';
  minHeap.print();

  std::cout << "Deleting root:" << '\n';
  deleted = minHeap.pop();

  std::cout << deleted << " deleted" << '\n';
  minHeap.print();
}