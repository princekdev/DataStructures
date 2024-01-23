#include <iostream>
#include "binarysearchtree.h"

int main()
{
  BinarySearchTree binarySearchTree;

  printf("Inserting 5: ");
  if (binarySearchTree.insertKeyRecursive(5))
  {
    printf("inserted\n");
  }
  else
  {
    printf("already present\n");
  }
  binarySearchTree.inOrderTraverse();
  printf("\n");

  printf("Inserting 3: ");
  if (binarySearchTree.insertKeyRecursive(3))
  {
    printf("inserted\n");
  }
  else
  {
    printf("already present\n");
  }
  binarySearchTree.inOrderTraverse();
  printf("\n");

  printf("Inserting 4: ");
  if (binarySearchTree.insertKeyIterative(4))
  {
    printf("inserted\n");
  }
  else
  {
    printf("already present\n");
  }
  binarySearchTree.inOrderTraverse();
  printf("\n");

  printf("searching 3: ");
  if (binarySearchTree.search(3))
  {
    printf("deleted\n");
  }
  else
  {
    printf("not found\n");
  }

  printf("deleting 3: ");
  if (binarySearchTree.deleteKey(3))
  {
    printf("deleted\n");
  }
  else
  {
    printf("not found\n");
  }

  binarySearchTree.inOrderTraverse();
  printf("\n");

  return 0;
}