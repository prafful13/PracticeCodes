#include<iostream>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<map>
#include "traversals.cpp"

class Solution  {
public:
  void topView(Node *root)  {
    queue<pair<Node *, int> > q;
    map<int, Node *> m;
    q.push(make_pair(root, 0));
    int l,r;
    l = r = 0;
    m[0] = root;
    while(!q.empty()) {
      Node *curr = q.front().first;
      int curr_dist = q.front().second;
      q.pop();
      if(curr_dist<l)  {
        m[curr_dist] = curr;
        l = curr_dist;
      }
      if(curr_dist>r) {
        m[curr_dist] = curr;
        r = curr_dist;
      }
      if(curr->left!=NULL)  q.push(make_pair(curr->left, curr_dist - 1));
      if(curr->right!=NULL) q.push(make_pair(curr->right, curr_dist + 1));
    }
    while(l<=r) {
      cout<<m[l++]->data<<" ";
    }
  }

  void leftView(Node *root, int curr, int& max) {
    if(root == NULL)  return;
    if(curr>max) {
      cout<<root->data<<" ";
      max = curr;
    }
    leftView(root->left, curr + 1, max);
    leftView(root->right, curr + 1, max);
  }

  void rightView(Node *root, int curr, int& max)  {
    if(root == NULL)  return;
    if(curr>max) {
      cout<<root->data<<" ";
      max = curr;
    }
    rightView(root->right, curr + 1, max);
    rightView(root->left, curr + 1, max);
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

  root2 = tree.insert(root2, 1);
  root2 = tree.insert(root2, 14);
  root2 = tree.insert(root2, 3);
  root2 = tree.insert(root2, 7);
  root2 = tree.insert(root2, 4);
  root2 = tree.insert(root2, 5);
  root2 = tree.insert(root2, 15);
  root2 = tree.insert(root2, 6);
  root2 = tree.insert(root2, 13);
  root2 = tree.insert(root2, 10);
  root2 = tree.insert(root2, 11);
  root2 = tree.insert(root2, 2);
  root2 = tree.insert(root2, 12);
  root2 = tree.insert(root2, 8);
  root2 = tree.insert(root2, 9);

  Solution sol;
  int max = -1;
  cout<<root2->data<<endl;
  sol.leftView(root, 0, max);
  cout<<endl;
  sol.topView(root2);
  return 0;
}
