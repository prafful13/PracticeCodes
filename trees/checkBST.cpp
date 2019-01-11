#include<iostream>
#include<queue>
#include<list>
#include "BST.cpp"

class Solution  {
public:
  pair<pair<int,int>,bool>  checkSub(Node* node)   {
      pair<pair<int,int>,bool> res;

      if(node->left == NULL && node->right == NULL)
          return make_pair(make_pair(node->data,node->data),true);
      else if(node->left == NULL) {
          res = checkSub(node->right);
          if(res.second == true)  {
              if(node->data < res.first.first)
                  return make_pair(make_pair(node->data, res.first.second),true);
              else    return make_pair(make_pair(-1,-1),false);
          }
          else    return make_pair(make_pair(-1,-1),false);
      }
      else if(node->right == NULL)    {
          res = checkSub(node->left);
          if(res.second == true)  {
              if(node->data > res.first.second)
                  return make_pair(make_pair(res.first.first, node->data), true);
              else    return make_pair(make_pair(-1,-1),false);
          }
          else    return make_pair(make_pair(-1,-1),false);
      }
      else    {
          pair<pair<int,int>,bool> resl = checkSub(node->left);
          pair<pair<int,int>,bool> resr = checkSub(node->right);
          if(resl.second == true && resr.second == true)  {
              if(node->data > resl.first.second && node->data < resr.first.first)
                  return make_pair(make_pair(resl.first.first, resr.first.second), true);
              else    return make_pair(make_pair(-1,-1),false);
          }
          else    return make_pair(make_pair(-1,-1),false);
      }
  }

  bool checkBST(Node* root) {
        if(root == NULL)    return true;
        pair<pair<int,int>,bool> res = checkSub(root);
        return res.second;
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
  cout<<sol.checkBST(root)<<endl;
  root->left->right->data = 40;
  cout<<sol.checkBST(root)<<endl;

  /*
  Output:
  1
  0
  */

  return 0;
}
