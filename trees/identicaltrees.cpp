#include<iostream>
#include<stack>
#include "BST.cpp"

class Solution  {
public:
  bool isIdentical(Node *root1, Node *root2)  {
    if(root1 == NULL && root2 == NULL)  return true;
    else if(root1 != NULL && root2 != NULL)
      if(root1->data == root2->data)  return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
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

  root2 = tree.insert(root2, 10);
  root2 = tree.insert(root2, 5);
  root2 = tree.insert(root2, 20);
  root2 = tree.insert(root2, 6);
  root2 = tree.insert(root2, 12);
  root2 = tree.insert(root2, 2);
  root2 = tree.insert(root2, 1);
  root2 = tree.insert(root2, 19);
  root2 = tree.insert(root2, 25);
  root2 = tree.insert(root2, 9);

  root3 = tree.insert(root3, 10);
  root3 = tree.insert(root3, 5);
  root3 = tree.insert(root3, 12);
  root3 = tree.insert(root3, 6);
  root3 = tree.insert(root3, 25);
  root3 = tree.insert(root3, 2);
  root3 = tree.insert(root3, 1);
  root3 = tree.insert(root3, 19);
  root3 = tree.insert(root3, 20);
  root3 = tree.insert(root3, 9);

  Solution sol;
  cout<<sol.isIdentical(root1, root2);
  cout<<endl;
  cout<<sol.isIdentical(root1, root3);
  cout<<endl;

  /*
  Output:
  1
  0
  */

  return 0;
}
