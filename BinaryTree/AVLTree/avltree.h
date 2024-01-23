#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>

class AVLTree
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

  int getHeight(Node *&traverser)
  {
    if (traverser == NULL)
    {
      return 0;
    }
    int leftHeight = getHeight(traverser->left);
    int rightHeight = getHeight(traverser->right);
    if (leftHeight > rightHeight)
    {
      return leftHeight + 1;
    }
    return rightHeight + 1;
  }

  int getBalanceFactor(Node *&checkNode)
  {
    return getHeight(checkNode->left) - getHeight(checkNode->right);
  }

  Node *leftRotate(Node *&imbalancedNode)
  {
    Node *balancedNode = imbalancedNode->right;
    imbalancedNode->right = balancedNode->left;
    balancedNode->left = imbalancedNode;
    return balancedNode;
  }

  Node *rightRotate(Node *&imbalancedNode)
  {
    Node *balancedNode = imbalancedNode->left;
    imbalancedNode->left = balancedNode->right;
    balancedNode->right = imbalancedNode;
    return balancedNode;
  }

  Node *balancenode(Node *&balanceNode)
  {
    if (getBalanceFactor(balanceNode) < -1)
    {
      if (balanceNode->right->right == NULL)
      {
        balanceNode->right = rightRotate(balanceNode->right);
      }
      return leftRotate(balanceNode);
    }
    if (getBalanceFactor(balanceNode) > 1)
    {
      if (balanceNode->left->left == NULL)
      {
        balanceNode->left = leftRotate(balanceNode->left);
      }
      return rightRotate(balanceNode);
    }
    return balanceNode;
  }

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
      if (insertKeyRecursion(traverser->left, key))
      {
        traverser->left = new Node(key);
        isInserted = 1;
      }
      if (isInserted)
      {
        traverser->left = balancenode(traverser->left);
      }
    }
    else if (traverser->data < key)
    {
      if (insertKeyRecursion(traverser->right, key))
      {
        traverser->right = new Node(key);
        isInserted = 1;
      }
      if (isInserted)
      {
        traverser->right = balancenode(traverser->right);
      }
    }
    if (traverser != root)
    {
      return 0;
    }
    if (isInserted)
    {
      root = balancenode(root);
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
      if (found)
      {
        traverser->right = balancenode(traverser->right);
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
      if (found)
      {
        traverser->left = balancenode(traverser->left);
      }
    }
    else
    {
      return 1;
    }
    return found;
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
  ~AVLTree()
  {
    deleteAll();
    printf("AVLTree Destructor: All deleted!");
  }

  bool insertKey(int key)
  {
    if (root == NULL)
    {
      root = new Node(key);
      return 1;
    }
    return insertKeyRecursion(root, key);
  }

  bool deleteKey(int key)
  {
    if (root->data == key)
    {
      root = deleteNode(root);
      return 1;
    }
    int isDeleted = deleteKeyRecursion(root, key);
    root = balancenode(root);
    return isDeleted;
  }

  bool search(int key)
  {
    return searchRecursion(root, key);
  }

  void deleteAll()
  {
    deleteAllRecursion(root);
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

#endif // AVLTREE_H