#include<iostream>
#include<stack>
#include<list>
#include<set>
#include "traversals.cpp"

class Solution  {
public:
  bool isBalanced(Node* root) {
      return getDepth(root)>=0;
  }

  int getDepth(Node* root){
      if(root==NULL) return 0;
      int l = getDepth(root->left);
      int r = getDepth(root->right);
      if(l<0 || r<0 || abs(l-r)>1 ) return -1;
      return max(l, r)+1;
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
