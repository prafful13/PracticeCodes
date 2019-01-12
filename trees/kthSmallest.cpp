#include<iostream>
#include<stack>
#include<list>
#include<set>
#include "traversals.cpp"

class Solution  {
public:
  int element;
  int kth;
  int kthSmallest(Node* root, int k) {
    kth = k;
    inOrder(root);
    return element;
  }
  void inOrder(Node *node) {
    if(node == NULL)  return;

    inOrder(node->left);
    kth--;
    if(kth==0)  {element = node->data; return;}
    inOrder(node->right);
  }
};

int main()  {
  BST tree;
  Node *root = NULL, *root2 = NULL;

  root = tree.insert(root, 10);
  root = tree.insert(root, 5);
  root = tree.insert(root, 1);
  root = tree.insert(root, 6);
  root = tree.insert(root, 12);
  root = tree.insert(root, 2);
  root = tree.insert(root, 1);
  root = tree.insert(root, 19);
  root = tree.insert(root, 25);
  root = tree.insert(root, 9);

  root2 = tree.insert(root2, 10);
  root2 = tree.insert(root2, 5);
  root2 = tree.insert(root2, 6);
  root2 = tree.insert(root2, 3);
  root2 = tree.insert(root2, 2);
  root2 = tree.insert(root2, 1);


  Solution sol;
  cout<<sol.isBalanced(root);

  return 0;
}
