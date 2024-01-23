#include <iostream>
#include "avltree.h"

int main()
{
  AVLTree avlTree;

  printf("Inserting 5: ");
  if (avlTree.insertKey(5))
  {
    printf("inserted\n");
  }
  else
  {
    printf("already present\n");
  }
  avlTree.inOrderTraverse();
  avlTree.postOrderTraverse();
  avlTree.preOrderTraverse();
  printf("\n");

  printf("Inserting 5: ");
  if (avlTree.insertKey(5))
  {
    printf("inserted\n");
  }
  else
  {
    printf("already present\n");
  }
  avlTree.inOrderTraverse();
  avlTree.postOrderTraverse();
  avlTree.preOrderTraverse();
  printf("\n");

  printf("Inserting 2: ");
  if (avlTree.insertKey(2))
  {
    printf("inserted\n");
  }
  else
  {
    printf("already present\n");
  }
  avlTree.inOrderTraverse();
  avlTree.postOrderTraverse();
  avlTree.preOrderTraverse();
  printf("\n");

  printf("Inserting 3: ");
  if (avlTree.insertKey(3))
  {
    printf("inserted\n");
  }
  else
  {
    printf("already present\n");
  }
  avlTree.inOrderTraverse();
  avlTree.postOrderTraverse();
  avlTree.preOrderTraverse();
  printf("\n");

  printf("Inserting 1: ");
  if (avlTree.insertKey(1))
  {
    printf("inserted\n");
  }
  else
  {
    printf("already present\n");
  }
  avlTree.inOrderTraverse();
  avlTree.postOrderTraverse();
  avlTree.preOrderTraverse();
  printf("\n");

  printf("Inserting 4: ");
  if (avlTree.insertKey(4))
  {
    printf("inserted\n");
  }
  else
  {
    printf("already present\n");
  }
  avlTree.inOrderTraverse();
  avlTree.postOrderTraverse();
  avlTree.preOrderTraverse();
  printf("\n");

  printf("searching 3: ");
  if (avlTree.search(3))
  {
    printf("found\n");
  }
  else
  {
    printf("not found\n");
  }

  printf("deleting 3: ");
  if (avlTree.deleteKey(3))
  {
    printf("deleted\n");
  }
  else
  {
    printf("not found\n");
  }

  avlTree.inOrderTraverse();
  avlTree.postOrderTraverse();
  avlTree.preOrderTraverse();
  printf("\n");

  printf("deleting 1: ");
  if (avlTree.deleteKey(1))
  {
    printf("deleted\n");
  }
  else
  {
    printf("not found\n");
  }

  avlTree.inOrderTraverse();
  avlTree.postOrderTraverse();
  avlTree.preOrderTraverse();
  printf("\n");

  printf("Inserting 3: ");
  if (avlTree.insertKey(3))
  {
    printf("inserted\n");
  }
  else
  {
    printf("already present\n");
  }
  avlTree.inOrderTraverse();
  avlTree.postOrderTraverse();
  avlTree.preOrderTraverse();
  printf("\n");

  printf("Inserting 6: ");
  if (avlTree.insertKey(6))
  {
    printf("inserted\n");
  }
  else
  {
    printf("already present\n");
  }
  avlTree.inOrderTraverse();
  avlTree.postOrderTraverse();
  avlTree.preOrderTraverse();
  printf("\n");

  printf("Inserting 7: ");
  if (avlTree.insertKey(7))
  {
    printf("inserted\n");
  }
  else
  {
    printf("already present\n");
  }
  avlTree.inOrderTraverse();
  avlTree.postOrderTraverse();
  avlTree.preOrderTraverse();
  printf("\n");

  printf("Inserting 8: ");
  if (avlTree.insertKey(8))
  {
    printf("inserted\n");
  }
  else
  {
    printf("already present\n");
  }
  avlTree.inOrderTraverse();
  avlTree.postOrderTraverse();
  avlTree.preOrderTraverse();
  printf("\n");

  printf("Inserting 9: ");
  if (avlTree.insertKey(9))
  {
    printf("inserted\n");
  }
  else
  {
    printf("already present\n");
  }
  avlTree.inOrderTraverse();
  avlTree.postOrderTraverse();
  avlTree.preOrderTraverse();
  printf("\n");

  printf("Inserting 10: ");
  if (avlTree.insertKey(10))
  {
    printf("inserted\n");
  }
  else
  {
    printf("already present\n");
  }
  avlTree.inOrderTraverse();
  avlTree.postOrderTraverse();
  avlTree.preOrderTraverse();
  printf("\n");

  printf("Inserting 11: ");
  if (avlTree.insertKey(11))
  {
    printf("inserted\n");
  }
  else
  {
    printf("already present\n");
  }
  avlTree.inOrderTraverse();
  avlTree.postOrderTraverse();
  avlTree.preOrderTraverse();
  printf("\n");

  printf("Inserting 12: ");
  if (avlTree.insertKey(12))
  {
    printf("inserted\n");
  }
  else
  {
    printf("already present\n");
  }
  avlTree.inOrderTraverse();
  avlTree.postOrderTraverse();
  avlTree.preOrderTraverse();
  printf("\n");

  return 0;
}