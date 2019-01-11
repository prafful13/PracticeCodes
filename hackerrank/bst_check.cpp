#include<bits/stdc++.h>

using namespace std;

// Link to problem statement: https://www.hackerrank.com/challenges/is-binary-search-tree/problem

struct Node {
  int data;
  Node* left;
  Node* right;
};

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

int main()  {
  //create tree
  return 0;
}
