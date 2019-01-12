#include<iostream>
#include<stack>
#include<list>
#include<set>
#include "traversals.cpp"

//  Question: https://practice.geeksforgeeks.org/problems/mirror-tree/1

class Solution  {
public:
  void mirrorImage(Node *root) {
    if(root == NULL)  return ;
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorImage(root->left);
    mirrorImage(root->right);
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

  Solution sol;
  Traversals t;

  sol.mirrorImage(root);
  t.inOrder(root);

  /*
  Output:
  10 5 2 1
  10 5 6 9
  10 20 12 19
  10 20 25
  */

  return 0;
}
