#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <typename elementType>
class Array
{
private:
  int arraySize;
  elementType *array;
  int usedSize = 0;

public:
  Array(int arraySize) : arraySize(arraySize), array(new elementType[arraySize])
  {
  }

  bool insert(elementType val)
  {
    if (usedSize == arraySize)
    {
      return 0;
    }
    array[usedSize++] = val;
    return 1;
  }

  bool set(int index, elementType val)
  {
    if (index >= usedSize || index < 0)
    {
      return 0;
    }
    array[index] = val;
    return 1;
  }

  elementType get(int index)
  {
    if (index >= usedSize || index < 0)
    {
      return NULL;
    }
    return array[index];
  }

  int getSize()
  {
    return usedSize;
  }

  int search(elementType key)
  {
    for (int i = 0; i < usedSize; i++)
    {
      if (array[i] == key)
      {
        return i;
      }
    }
    return -1;
  }

  void resize(int newSize)
  {
    if (newSize < 0)
    {
      printf("Invalid size!\n");
      return;
    }
    int *newArray = new elementType[newSize];
    for (int i = 0; i < usedSize; i++)
    {
      newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    arraySize = newSize;
  }
};

#endif // ARRAY_H