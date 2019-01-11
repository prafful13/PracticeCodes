#include<iostream>
#include<stack>
#include "BST.cpp"

class Solution  {
public:
  bool isFoldable(Node *root) {
    if(root == NULL)    return true;
    if(root->left == NULL && root->right == NULL)   return true;
    if(root->left != NULL && root->right != NULL) {
      Node *node1 = new Node(0);
      node1->left = root->left->left;
      node1->right = root->right->right;

      Node *node2 = new Node(0);
      node2->left = root->left->right;
      node2->right = root->right->left;

      return isFoldable(node1) && isFoldable(node2);
    }
    return false;
  }
};

int main()  {
  BST tree;
  Node *root1 = NULL, *root2 = NULL, *root3 = NULL;

  root1 = tree.insert(root1, 10);
  root1 = tree.insert(root1, 5);
  root1 = tree.insert(root1, 20);
  root1 = tree.insert(root1, 6);
  root1 = tree.insert(root1, 12);
  root1 = tree.insert(root1, 2);
  root1 = tree.insert(root1, 1);
  root1 = tree.insert(root1, 19);
  root1 = tree.insert(root1, 25);
  root1 = tree.insert(root1, 9);

  root3 = tree.insert(root3, 10);
  root3 = tree.insert(root3, 5);
  root3 = tree.insert(root3, 12);
  root3 = tree.insert(root3, 6);
  root3 = tree.insert(root3, 25);
  root3 = tree.insert(root3, 2);
  root3 = tree.insert(root3, 1);
  root3 = tree.insert(root3, 11);
  root3 = tree.insert(root3, 30);

  Solution sol;
  cout<<sol.isFoldable(root1);
  cout<<endl;
  cout<<sol.isFoldable(root3);
  cout<<endl;

  /*
  Output:
  0
  1
  */

  return 0;
}
