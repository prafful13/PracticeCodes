#include<iostream>
#include<stack>
#include<queue>
#include "BST.cpp"

class Solution  {
public:
  vector<Node *> nodesWithinRange(Node* root, int a, int b) {
    queue<Node *> q;
    vector<Node *> res;
    if(root == NULL)  return res;
    q.push(root);
    while(!q.empty()) {
      Node *curr = q.front();
      q.pop();
      if(curr->data <= b && curr->data >= a)  {
        if(curr->left != NULL)  q.push(curr->left);
        if(curr->right != NULL)  q.push(curr->right);
        res.push_back(curr);
      }
      else if(curr->data < a) {
        if(curr->right != NULL)  q.push(curr->right);
      }
      else  {
        if(curr->left != NULL)  q.push(curr->left);
      }
    }
    return res;
  }

  void printVector(vector<Node *> v)  {
    vector<Node*>::iterator it = v.begin();
    while(it!=v.end())  {
      cout<<(*it)->data<<" ";
      it++;
    }
    cout<<endl;
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

  sol.printVector(sol.nodesWithinRange(root, 11, 23));
  sol.printVector(sol.nodesWithinRange(root, 3, 24));

  /*
  Output:
  20 12 19
  10 5 20 6 12 9 19
  */

  return 0;
}
