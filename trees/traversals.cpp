#include<iostream>
#include "BST.cpp"

class Traversals {
    public:
    void inOrder(Node *root) {
      if(root == NULL)  return;
      inOrder(root->left);
      cout<<root->data<<" ";
      inOrder(root->right);
    }

    void preOrder(Node *root) {
      if(root == NULL)  return;
      cout<<root->data<<" ";
      preOrder(root->left);
      preOrder(root->right);
    }

    void postOrder(Node *root)  {
      if(root == NULL)  return;
      postOrder(root->left);
      postOrder(root->right);
      cout<<root->data<<" ";
    }

    

};

int main()  {
  BST tree;
  Node *root = NULL;

  root = tree.insert(root, 10);
  root = tree.insert(root, 5);
  root = tree.insert(root, 20);
  root = tree.insert(root, 6);
  root = tree.insert(root, 12);
  root = tree.insert(root, 2);
  root = tree.insert(root, 1);
  root = tree.insert(root, 19);
  root = tree.insert(root, 25);
  root = tree.insert(root, 9);

  Traversals logic;
  logic.inOrder(root);
  cout<<endl;
  logic.preOrder(root);
  cout<<endl;
  logic.postOrder(root);
  cout<<endl;

  return 0;
}
