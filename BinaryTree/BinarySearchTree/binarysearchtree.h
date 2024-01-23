#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

class BinarySearchTree
{
  class Node
  {
  public:
    int data;
    Node *left = NULL, *right = NULL;
    Node(int val)
    {
      data = val;
    }
  };
  Node *root = NULL;

  bool insertKeyRecursion(Node *&traverser, int key)
  {
    static int isInserted;
    isInserted = 0;
    if (traverser == NULL)
    {
      return 1;
    }
    if (traverser->data > key)
    {
      if (insertKeyRecursion(traverser->left, key) && !isInserted)
      {
        traverser->left = new Node(key);
        isInserted = 1;
      }
    }
    else if (traverser->data < key)
    {
      if (insertKeyRecursion(traverser->right, key))
      {
        traverser->right = new Node(key);
        isInserted = 1;
      }
    }
    if (traverser != root)
    {
      return 0;
    }
    return isInserted;
  }

  Node *deleteNode(Node *&keyNode)
  {
    Node *newLinkingNode;
    if (keyNode->left == NULL && keyNode->right == NULL)
    {
      newLinkingNode = NULL;
    }
    else if (keyNode->right == NULL)
    {
      newLinkingNode = keyNode->left;
    }
    else if (keyNode->left == NULL)
    {
      newLinkingNode = keyNode->right;
    }
    else if (keyNode->left->right == NULL)
    {
      newLinkingNode = keyNode->left;
      keyNode->left->right = keyNode->right;
    }
    else if (keyNode->right->left == NULL)
    {
      newLinkingNode = keyNode->right;
      keyNode->right->left = keyNode->left;
    }
    else
    {
      Node *maxTraverser = keyNode->left;
      while (maxTraverser->right->right != NULL)
      {
        maxTraverser = maxTraverser->right;
      }
      newLinkingNode = maxTraverser->right;
      maxTraverser->right->left = keyNode->left;
      maxTraverser->right->right = keyNode->right;
      maxTraverser->right = NULL;
    }
    delete keyNode;
    return newLinkingNode;
  }

  bool deleteKeyRecursion(Node *&traverser, int key)
  {
    static int found;
    found = 0;
    if (traverser == NULL)
    {
      return 0;
    }
    if (traverser->data < key)
    {
      if (deleteKeyRecursion(traverser->right, key))
      {
        if (!found)
        {
          traverser->right = deleteNode(traverser->right);
          found = 1;
          return 1;
        }
      }
    }
    else if (traverser->data > key)
    {
      if (deleteKeyRecursion(traverser->left, key))
      {
        if (!found)
        {
          traverser->left = deleteNode(traverser->left);
          found = 1;
          return 1;
        }
      }
    }
    else
    {
      return 1;
    }
    return found;
  }

  void deleteAllRecursion(Node *&traverser)
  {
    if (traverser == NULL)
    {
      return;
    }
    deleteAllRecursion(traverser->left);
    deleteAllRecursion(traverser->right);
    delete traverser;
  }

  bool searchRecursion(Node *&traverser, int key)
  {
    if (traverser == NULL)
    {
      return 0;
    }
    if (traverser->data > key)
    {
      return searchRecursion(traverser->left, key);
    }
    else if (traverser->data < key)
    {
      return searchRecursion(traverser->right, key);
    }
    else
    {
      return 1;
    }
  }

  void preOrderTraverseRecursion(Node *&root)
  {
    if (root == NULL)
    {
      return;
    }
    printf("%d ", root->data);
    preOrderTraverseRecursion(root->left);
    preOrderTraverseRecursion(root->right);
  }

  void inOrderTraverseRecursion(Node *&root)
  {
    if (root == NULL)
    {
      return;
    }
    inOrderTraverseRecursion(root->left);
    printf("%d ", root->data);
    inOrderTraverseRecursion(root->right);
  }

  void postOrderTraverseRecursion(Node *&root)
  {
    if (root == NULL)
    {
      return;
    }
    postOrderTraverseRecursion(root->left);
    postOrderTraverseRecursion(root->right);
    printf("%d ", root->data);
  }

public:
  ~BinarySearchTree()
  {
    deleteAll();
    printf("BinarySearchTree Destructor: All deleted!");
  }

  bool insertKeyRecursive(int key)
  {
    if (root == NULL)
    {
      root = new Node(key);
      return 1;
    }
    return insertKeyRecursion(root, key);
  }

  bool insertKeyIterative(int key)
  {
    if (root == NULL)
    {
      root = new Node(key);
      return 1;
    }
    Node *traverser = root;
    while (true)
    {
      if (traverser->data < key)
      {
        if (traverser->right == NULL)
        {
          traverser->right = new Node(key);
          return 1;
        }
        traverser = traverser->right;
      }
      else if (traverser->data > key)
      {
        if (traverser->left == NULL)
        {
          traverser->left = new Node(key);
        }
        traverser = traverser->left;
      }
      else
      {
        return 0;
      }
    }
    return 1;
  }

  bool deleteKey(int key)
  {
    if (root->data == key)
    {
      root = deleteNode(root);
      return 1;
    }
    return deleteKeyRecursion(root, key);
  }

  void deleteAll()
  {
    deleteAllRecursion(root);
  }

  bool search(int key)
  {
    return searchRecursion(root, key);
  }

  bool searchIterative(int key)
  {
    Node *traverser = root;
    while (traverser != NULL)
    {
      if (traverser->data < key)
      {
        traverser = traverser->right;
      }
      else if (traverser->data > key)
      {
        traverser = traverser->left;
      }
      else
      {
        return 1;
      }
    }
    return 0;
  }

  bool isEmpty()
  {
    if (root == NULL)
    {
      return 1;
    }
    return 0;
  }

  void preOrderTraverse()
  {
    printf("[ ");
    preOrderTraverseRecursion(root);
    printf("]\n");
  }

  void inOrderTraverse()
  {
    printf("[ ");
    inOrderTraverseRecursion(root);
    printf("]\n");
  }

  void postOrderTraverse()
  {
    printf("[ ");
    postOrderTraverseRecursion(root);
    printf("]\n");
  }
};

#endif // BINARYSEARCHTREE_H