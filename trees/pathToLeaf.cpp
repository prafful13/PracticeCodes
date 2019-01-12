#include<iostream>
#include<stack>
#include<list>
#include<set>
#include "BST.cpp"

class Solution  {
public:
  list<list<Node *> > pathToLeaf(Node *root)  {
    stack<Node *> stack;
    list<list<Node *> > res;
    list<Node *> curr_path;
    set<Node *> set;
    if(root == NULL)  return res;
    stack.push(root);
    curr_path.push_back(root);
    while(!stack.empty()) {
      Node *curr = stack.top();
      if(curr->left != NULL && set.find(curr->left) == set.end()) {
        stack.push(curr->left);
        curr_path.push_back(curr->left);
        set.insert(curr->left);
      }
      else if(curr->right != NULL && set.find(curr->right) == set.end()) {
        stack.push(curr->right);
        curr_path.push_back(curr->right);
        set.insert(curr->right);
      }
      else  if(curr->left == NULL && curr->right == NULL) {
        res.push_back(curr_path);
        curr_path.pop_back();
        stack.pop();
      }
      else  {
        curr_path.pop_back();
        stack.pop();
      }
    }
    return res;
  }

  void print(list<list<Node*> > ll)  {
    list<list<Node*> >::iterator it = ll.begin();
    while (it != ll.end()) {
      list<Node*>::iterator i = (*it).begin();
      while (i != (*it).end())  {
        cout<<(*i)->data<<" ";
        i++;
      }
      cout<<endl;
      it++;
    }
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

  list<list<Node*> > result = sol.pathToLeaf(root);

  sol.print(result);

  /*
  Output:
  10 5 2 1
  10 5 6 9
  10 20 12 19
  10 20 25
  */

  return 0;
}
