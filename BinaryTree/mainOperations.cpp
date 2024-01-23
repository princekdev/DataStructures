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

bool search(Node *&root, int key)
{
  if (root == NULL)
  {
    return 0;
  }
  if (root->data == key)
  {
    return 1;
  }
  if (search(root->left, key) || search(root->right, key))
  {
    return 1;
  }
  return 0;
}

void preOrderTraverse(Node *&root)
{
  if (root == NULL)
  {
    return;
  }
  printf("%d ", root->data);
  preOrderTraverse(root->left);
  preOrderTraverse(root->right);
}

void postOrderTraverse(Node *&root)
{
  if (root == NULL)
  {
    return;
  }
  postOrderTraverse(root->left);
  postOrderTraverse(root->right);
  printf("%d ", root->data);
}

void inOrderTraverse(Node *&root)
{
  if (root == NULL)
  {
    return;
  }
  inOrderTraverse(root->left);
  printf("%d ", root->data);
  inOrderTraverse(root->right);
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
  Node *n1 = new Node(7);
  Node *n2 = new Node(2);
  Node *n3 = new Node(9);
  Node *n4 = new Node(5);
  Node *n5 = new Node(1);

  root = n1;
  n1->left = n2;
  n1->right = n3;

  n2->left = n4;
  n2->right = n5;

  printf("Pre order traversal: ");
  preOrderTraverse(root);
  printf("\n");
  printf("Post order traversal: ");
  postOrderTraverse(root);
  printf("\n");
  printf("In order traversal: ");
  inOrderTraverse(root);
  printf("\n");

  printf("Searching 5:\n");
  if (search(root, 5))
  {
    printf("present\n");
  }
  else
  {
    printf("not present\n");
  }

  printf("Searching 3 Iteratively:\n");
  if (search(root, 3))
  {
    printf("present\n");
  }
  else
  {
    printf("not present\n");
  }

  printf("Deleting all:\n");
  deleteAll(root);

  return 0;
}