#include<iostream>
#include<stack>
#include<list>
#include<set>
#include "traversals.cpp"

class Solution  {
public:
  int count;
  void dfs(Node *root, int sum, int curr_sum)  {
    if(root == NULL)    return;
    curr_sum += root->data;

    if(curr_sum == sum) count++;
    dfs(root->left, sum, curr_sum);
    dfs(root->right, sum, curr_sum);
  }

  void inOrder(Node *root, int sum)    {
    if(root == NULL)    return;
    inOrder(root->left, sum);
    dfs(root, sum, 0);
    inOrder(root->right, sum);
  }

  void pathSum(Node *root, int sum)  {
    inOrder(root, sum);
    cout<<count<<endl;
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

  sol.pathSum(root2, 21);
  sol.res.clear();
  // sol.pathSum(root2, 34);

  /*
  Output:
  10 5 2 1
  10 5 6 9
  10 20 12 19
  10 20 25
  */

  return 0;
}
