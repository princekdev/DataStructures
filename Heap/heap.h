#ifndef HEAP_H
#define HEAP_H

#include <iostream>

void swap(int *arr, int i1, int i2);

class MaxHeap
{
protected:
  int size;
  int *heap;
  int top;

  void heapify(int i)
  {
    int i_max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left <= top && heap[left] > heap[i])
    {
      i_max = left;
    }
    if (right <= top && heap[right] > heap[i_max])
    {
      i_max = right;
    }
    if (i_max != i)
    {
      swap(heap, i, i_max);
      heapify(i_max);
    }
  }

public:
  MaxHeap(int size)
  {
    MaxHeap::size = size;
    heap = new int[size];
    top = -1;
  }

  void push(int val)
  {
    heap[++top] = val;

    int parent = (top - 1) / 2;
    while (parent > 0)
    {
      heapify(parent);
      parent = (parent - 1) / 2;
    }
    heapify(0);
  }

  int pop()
  {
    swap(heap, 0, top--);
    heapify(0);
    return heap[top + 1];
  }

  void print()
  {
    for (int i = 0; i <= top; i++)
    {
      std::cout << heap[i] << " ";
    }
    std::cout << '\n';
  }

  void deleteAll()
  {
    top = -1;
  }

  ~MaxHeap()
  {
    delete[] heap;
  }
};

class MinHeap : public MaxHeap
{
protected:
  void heapify(int i)
  {
    int i_min = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left <= top && heap[left] < heap[i])
    {
      i_min = left;
    }
    if (right <= top && heap[right] < heap[i_min])
    {
      i_min = right;
    }
    if (i_min != i)
    {
      swap(heap, i, i_min);
      heapify(i_min);
    }
  }

public:
  MinHeap(int size) : MaxHeap(size) {}

  void push(int val)
  {
    heap[++top] = val;

    int parent = (top - 1) / 2;
    while (parent > 0)
    {
      heapify(parent);
      parent = (parent - 1) / 2;
    }
    heapify(0);
  }

  int pop()
  {
    swap(heap, 0, top--);
    heapify(0);
    return heap[top + 1];
  }
};

void swap(int *arr, int i1, int i2)
{
  int temp = arr[i1];
  arr[i1] = arr[i2];
  arr[i2] = temp;
}

#endif // HEAP_H