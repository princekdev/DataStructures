#include <iostream>

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

bool isBST(Node *&root)
{
  if (root->left == NULL && root->right == NULL)
  {
    return 1;
  }
  if (root->left != NULL)
  {
    if (!isBST(root->left) || root->left->data >= root->data || root->left->right != NULL && root->left->right->data >= root->data)
    {
      return 0;
    }
  }
  if (root->right != NULL)
  {
    if (!isBST(root->right) || root->right->data <= root->data || root->right->left != NULL && root->right->left->data <= root->data)
    {
      return 0;
    }
  }
  return 1;
}

void deleteAll(Node *&traverser)
{
  if (traverser == NULL)
  {
    return;
  }
  deleteAll(traverser->left);
  deleteAll(traverser->right);
  delete traverser;
}

int main()
{
  Node *root = NULL;
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  Node *n5 = new Node(5);
  Node *n6 = new Node(6);
  Node *n7 = new Node(7);
  Node *n8 = new Node(8);
  Node *n9 = new Node(9);

  root = n6;

  n6->left = n4;

  n4->left = n2;
  n2->left = n1;
  n2->right = n3;

  n4->right = n5;

  n6->right = n8;

  n8->left = n7;
  n8->right = n9;

  printf("Checking for BST:\n");
  printf("       _______6_______\n"
         "   ___4___         ___8___\n"
         " _2_      5       7       9\n"
         "1   3\n\n");

  if (isBST(root))
  {
    printf("it is a BST\n\n");
  }
  else
  {
    printf("it is not a BST\n\n");
  }

  n6->data = 5;
  n5->data = 6;

  printf("Checking for BST:\n\n");
  printf("       _______5_______\n"
         "   ___4___         ___8___\n"
         " _2_      6       7       9\n"
         "1   3\n\n");

  if (isBST(root))
  {
    printf("it is a BST\n\n");
  }
  else
  {
    printf("it is not a BST\n\n");
  }

  n4->right = NULL;
  delete n5;

  printf("Checking for BST:\n");
  printf("       _______5_______\n"
         "   ___4            ___8___\n"
         " _2_              7       9\n"
         "1   3\n\n");

  if (isBST(root))
  {
    printf("it is a BST\n\n");
  }
  else
  {
    printf("it is not a BST\n\n");
  }

  deleteAll(root);

  return 0;
}